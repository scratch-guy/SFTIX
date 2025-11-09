# SFTNIX

**SFTNIX** is a rootfs-native, POSIX-like operating system built on Linux. Authored by Tentatio (age 10), it features a custom shell, a hand-rolled init system, and a minimalist boot flow. SFTNIX embodies the UNIX philosophy through simplicity, explicit control, and composable design.

---

## 🧠 Philosophy

- **POSIX compliance** via native syscalls (`fork`, `execve`, `wait`)
- **Minimal rootfs layout** with no systemd, no Bash, no package manager
- **Custom shell** written in C, compiled to a native ELF binary
- **Explicit boot flow** from script to shell, no hidden logic
- **Legacy-first engineering**: every artifact is verified, documented, and canonized

---

## 📦 Directory Structure

```
/
├── boot/       → run.sh (boot trigger)
├── init/       → init.sh (init handoff to shell)
├── bin/        → shell.c + shell (custom REPL)
└── usr/bin/    → BusyBox + external commands
```

---

## 🚀 Boot Flow

```plaintext
/boot/run.sh → /init/init.sh → /bin/shell
```

- `run.sh`: Launches the init script
- `init.sh`: Starts the custom shell
- `shell`: REPL loop that parses input and executes `/usr/bin/[cmd]`

---

## 🐚 Shell Features

- Written in C
- Parses space-delimited input
- Forks and executes commands via `/usr/bin/[cmd]`
- No built-ins (yet)—all commands must be external binaries
- Error handling: prints `fail =(` on `execve` failure

---

## 🔤 Name Origin

- **SFT** → reversed is **TFS**, echoing **rootfs**
- **NIX** → UNIX-like lineage
- **SFTNIX** = “rootfs UNIX”
- clever, huh?
---

## 📜 License

NONE!!! just give credit

---

## 🛠️ Build Instructions

```bash
gcc -o bin/shell bin/shell.c
```

Ensure BusyBox is installed in `/usr/bin/` or symlinked appropriately.

---

## 🧪 Example Session

```bash
victim@LAPTOP-O1R0QL0J:~$ sh ~/linux/boot/run.sh
# echo hello world
hello world
# busybox
BusyBox v1.36.1 ...
```

---

## 🏁 Status

SFTNIX is a verified, bootable, POSIX-like OS with a custom shell and minimal userland.

---

## ✍️ Author

Landon (age \**)

