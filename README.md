# SFTNIX

**SFTNIX** is a rootfs-native, POSIX-like operating system built on Linux. Authored by ****** (age **), it features a custom shell, a hand-rolled init system, and a minimalist boot flow. SFTNIX embodies the UNIX philosophy through simplicity, explicit control, and composable design.

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
├──root
|
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
Open-Source project. Use with credit.


MIT License

Copyright (c) 2025 scratch-guy

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

---

## 🛠️ Build Instructions

```bash
sudo apt update #update
sudo apt install git #installs git package
git clone --depth 1 https://github.com/scratch-guy/SFTIX #downloads this repository
cd SFTIX #goes into directory, important for run.sh and init.sh
chmod +x run.sh init.sh shell #give init, boot, and shell permissions required
./run.sh #run boot code
```

Ensure BusyBox is installed in `/usr/bin/` or symlinked appropriately.

---

## 🧪 Example Session

```bash
user@LAPTOP-XXXXXXXX:~$ ./run.sh
# echo hello world
hello world
# busybox
BusyBox v1.36.1 ...
```

---

## 🏁 Status

SFTNIX is a verified, bootable, POSIX-like OS with a custom shell and minimal userland (shell).

---

## ✍️ Author

****** (age \**) scratch-guy
TikTok: undertale_lover_asriel

## Credits:
Based on Linus Torvald's linux 0.01 rootfs. (https://github.com/zavg/linux-0.01)
