# Operating Systems Concepts in C and Bash

An educational Linux project that demonstrates user-space examples of operating-system concepts through small C programs and Bash menus. It is not a kernel-level task manager and does not monitor or control processes through a production-grade interface.

## Modules

The `src/` directory contains examples covering:

- process creation and parent/child behavior
- orphan processes
- CPU scheduling simulation
- dynamic and shared memory
- signal handling and signal-based process control
- threads and synchronization

The `bash/` directory contains a menu script and a small custom-command demonstration. Prebuilt Linux executables are checked into `bin/`.

## Repository layout

```text
.
├── bash/
│   ├── main.sh
│   └── mycommand.sh
├── bin/                 # checked-in Linux executables
├── src/                 # C source and checked-in builds
└── README.md
```

## Run the menu

Use a Linux environment with Bash and the checked-in `bin/` programs:

```bash
cd bash
chmod +x main.sh mycommand.sh
./main.sh
```

The script uses paths relative to the `bash/` working directory. The menu's "Shutdown OS" option only exits this demonstration program; it does not shut down the host.

## Compile examples from source

From the repository root, compile individual modules as needed. For example:

```bash
gcc src/memory.c -o /tmp/memory
gcc src/thread_sync.c -o /tmp/thread_sync -pthread
/tmp/memory
/tmp/thread_sync
```

Other examples may require Linux/POSIX APIs and have their own runtime behavior. Review each source file before running it. Some process and signal demonstrations intentionally affect child processes; run them in a disposable development environment.

## Requirements

- Linux or another compatible POSIX environment
- GCC
- Bash
- POSIX threads for `thread_sync`

## Limitations

- The scheduler is a user-space simulation, not an operating-system scheduler.
- This repository is a collection of teaching examples, not a general-purpose process manager.
- The checked-in executables are platform-specific; rebuild from `src/` for your environment.
