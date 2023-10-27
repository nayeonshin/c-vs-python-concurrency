# C vs. Python Concurrency

## Background

- Thread-safe: means safe for multithreading

  - If something is not thread-safe, values in thread 1 can change in thread 2, causing problems.

- C: POSIX Threads (Pthreads) & `fork()`
- Python: `threading` and `multiprocessing` modules

  - `threading`: works with threads
    - Limited by Python's Global Interpreter Lock (GIL)
    - Less efficient for CPU-bound tasks.
  - `multiprocessing`: works with processes
    - Each process with its own Python interpreter and memory space
    - Suitable for CPU-bound tasks & can bypass the GIL
  - Mostly utilizes multiprocessing because multithreading makes little sense due to the nature of GIL
  - When we talk about guaranteeing thread safety, we mean providing locking internally, which incurs locking overhead and affects performance
  - e.g. `PriorityQueue` (thread-safe) vs. `heapq` (not thread-safe)

## TILs (Today I Learned)

- To preserve a value after the child process ends, use inter-process communication (IPC) mechanisms to share the calculated value between the child and parent processes. One common method for achieving it is to use a pipe.
- In Unix-like systems, the exit status of a process is an 8-bit value (0-255). When you pass a value to the `exit` funcion, it's subject to modulo 256 (i.e. it wraps around if it exceeds 255).

## Outputs

- `extended_unix_concurrency.c`: With `MAX_NUMBER` being `1000000000`, one possible output is:

```
MULTIPROCESSING - parent sum: 375000000250000000
MULTIPROCESSING - child sum: 125000000250000000
MULTITHREADING - sum: 500000000500000000
```

## TODOs

- [ ] Research on how to analyze the performance metrics
