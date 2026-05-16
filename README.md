# Implementation and Analysis of Core Operating System Concepts

> A practical exploration of fundamental OS concepts using **C** and **Unix Shell Scripting**

**Course:** Operating Systems



---

## Overview

This project experimentally demonstrates core Operating System concepts through user-space implementations in C, using POSIX system calls on a Linux environment. Each concept is built as a standalone module, allowing focused observation of OS behavior without kernel-level modifications.

**Topics covered:**
- Process creation and termination
- Orphan process handling
- CPU scheduling simulation
- Dynamic memory management
- Signal handling and process control
- Thread synchronization and concurrency
- Shared memory inter-process communication (IPC)
- Shell scripting and automation

---

## Project Structure

```
.
├── process.c          # Process creation and management
├── process_orphan.c   # Orphan process handling
├── scheduler.c        # CPU scheduling simulation
├── memory.c           # Dynamic memory management
├── signal.c           # Signal handling
├── signal_kill.c      # Process termination via signals
├── thread_sync.c      # Thread synchronization with mutex
├── shared_mem.c       # Shared memory IPC
├── main.sh            # Compilation and execution automation
└── mycommand.sh       # Custom shell command demonstration
```

---

## Modules

### `process.c` — Process Creation and Management
Uses `fork()` to create child processes. Demonstrates parent–child relationships, concurrent execution, and how the OS creates a new Process Control Block (PCB) for each child.

### `process_orphan.c` — Orphan Process Handling
Demonstrates what happens when a parent exits before its child. The OS automatically re-parents the orphan to `init`/`systemd`, ensuring system stability.

### `scheduler.c` — CPU Scheduling Simulation
Simulates task scheduling at the user level using `sleep()` to introduce execution delays, visualizing time-sharing and task ordering.

### `memory.c` — Dynamic Memory Management
Demonstrates correct use of `malloc()` and `free()` for heap allocation and deallocation, highlighting the importance of manual memory management in C.

### `signal.c` — Signal Handling
Registers a custom signal handler using `signal()` to intercept signals like `SIGINT`, showing how processes can respond to asynchronous OS events instead of using default behavior.

### `signal_kill.c` — Process Termination via Signals
Uses `kill()` to send termination signals to target processes, demonstrating graceful process shutdown and external process control.

### `thread_sync.c` — Thread Synchronization
Creates multiple threads with `pthread_create()` that share a resource. Uses a **mutex lock** to enforce mutual exclusion and prevent race conditions.

### `shared_mem.c` — Shared Memory IPC
Creates a shared memory segment using POSIX APIs. Multiple processes attach to the same region to exchange data — the fastest IPC mechanism available in Unix.

### `main.sh` — Automation Script
Compiles all C source files with GCC and runs each module sequentially. The entire project can be compiled and executed with a single command.

### `mycommand.sh` — Custom Shell Command
Demonstrates basic shell scripting: executing predefined system commands and showing how scripts extend OS functionality.

---

## Technologies

| Component | Details |
|---|---|
| Language | C |
| OS | Linux / Unix |
| Compiler | GCC |
| Libraries | POSIX (`unistd.h`, `pthread.h`, `signal.h`) |
| Automation | Bash shell scripting |

---

## Getting Started

### Prerequisites
- Linux / Unix environment
- GCC compiler
- POSIX thread library (`libpthread`)

### Run the Project

```bash
# Clone the repository
git clone <your-repo-url>
cd <repo-folder>

# Make the main script executable and run it
chmod +x main.sh
./main.sh
```

This will automatically compile all C modules and execute them in order.

### Compile a Single Module Manually

```bash
gcc process.c -o process && ./process
gcc thread_sync.c -o thread_sync -lpthread && ./thread_sync
gcc shared_mem.c -o shared_mem && ./shared_mem
```

---

## Testing

Verification was performed by:
- Checking process IDs and parent–child relationships via terminal output
- Observing orphan process adoption by `init`/`systemd`
- Sending signals manually using terminal commands (e.g., `kill`, `Ctrl+C`)
- Monitoring thread execution order and synchronization correctness

---

## Limitations

- No kernel-level modifications — all implementations are user-space only
- CPU scheduling is simulated, not a real scheduler
- No GUI or visualization interface

---


