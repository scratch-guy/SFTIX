#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
char input[255];
char *argv[256];
int main() {
  while (1) {
    write(1, "# ", 2);
    read(0, input, sizeof(input));
    input[strcspn(input, "\n")] ='\0';
    char path[255];
    int i = 0;
    char *token = strtok(input, " ");
    while (token && i < 255) {
      argv[i++] = token;
      token = strtok(NULL, " ");
    }
    argv[i] = NULL;
    sprintf(path, "/usr/bin/%s", argv[0]);
    if (fork() == 0) {
      execve(path, argv, NULL);
      write(1, "fail =(\n", 8);
      _exit(1);
    } else {
      wait(NULL);
     }
  }
}
