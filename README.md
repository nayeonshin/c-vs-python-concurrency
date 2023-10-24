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

- Question: Tools for benchmarking?

  - C: `pthreads` library itself for multithreading / ??? for multiprocessing
  - Python: ???

## TILs (Today I Learned)

- To preserve a value after the child process ends, use inter-process communication (IPC) mechanisms to share the calculated value between the child and parent processes. One common method for achieving it is to use a pipe.

## Outputs

- `extended_unix_concurrency.c`: With `MAX_NUMBER` being a `1000000000`, the output is:

```
Multiprocessing sum: 500000000500000000
```

## TODOs

- [ ] Implement parallel sum using multithreading
- [ ] Research on how to analyze the performance metrics

## Questions

1. Is pipe the correct solution for binding the value between the processes?

- Will it affect the performance of multiprocessing?
- Can we not make it a control variable? We only want to compare the performance of (pure?) multiprocessing and multithreading.
