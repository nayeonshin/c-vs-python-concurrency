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
- The "can't pickle" error in Python typically occurs when you're trying to pass a function or an object that can't be serialized (pickled) to a separate process, which is necessary for multiprocessing in Python.
- Python bytecode is the low-level representation of Python code executed by the Python interpreter.
- The GIL is released during I/O operations, which is why multithreading can still be effective for I/O-bound tasks where the threads spend a significant amount of time waiting for I/O operations to complete.

## Outputs

- `extended_unix_concurrency.c`: With `MAX_NUMBER` being `1000000000`, one possible output is:

```
MULTIPROCESSING - Parent sum: 375000000250000000
MULTIPROCESSING - child sum: 125000000250000000
MULTITHREADING - sum: 500000000500000000
```

## GIL (Global Interpreter Lock)

- The actual computation of the sum within the `calculate_sum_in_range()` function in `extended_concurrency.py` is still serialized.
  - The GIL serializes the two threads' access to the Python interpreter and the execution of Python bytecode, meaning that one thread has to wait for the other to finish its calculation before it can proceed.
  - While the threads can perform other operations concurrently, such as function calls, print statements, and so on, the actual computation of the sum (the `sum(range(start, end + 1))` part) is restricted by the GIL.
- In other words, while the threads can run concurrently for I/O-bound tasks, when it comes to CPU-bound tasks like calculating the sum, the GIL prevents full utilization of multiple CPU cores.
- In this specific case, multithreading may not provide significant performance benefits for CPU-bound tasks due to the GIL.

## TODOs

- [ ] Research on how to analyze the performance metrics (in progress)
  - C
    - Execution time: `clock()` or `gettimeofday()` to record timestamps
    - CPU utilization: system calls or libraries like `getrusage` or `clock_gettime`.
  - Python
    - Execution time: `timeit` module or third-party libraries like `pytest-benchmark` and `perf` --- probably `pref`
    - CPU utilization: `psutil` library, which provides functions to retrieve CPU usage
  - Execution time comparison, CPU utilization, thread activity, GIL contention, profiling and line-by-line analysis


## Testing
### C
- `clock_gettime()`: used to retrieve the current time according to a specified clock
  ```
  MULTIPROCESSING - Parent sum: 375000000250000000
  MULTIPROCESSING - Child sum: 125000000250000000
  MULTIPROCESSING - Elapsed time: 1 seconds & 400070000 nanoseconds
  MULTITHREADING - Sum: 125000000250000000
  MULTITHREADING - Sum: 375000000250000000
  MULTITHREADING - Elapsed time: 1 seconds & 349450000 nanoseconds
  MULTIPROCESSING - Child sum: 125000000250000000
  MULTITHREADING - Elapsed time: 1 seconds & 349450000 nanoseconds
  MULTIPROCESSING - Parent sum: 375000000250000000
  MULTIPROCESSING - Elapsed time: 2 seconds & -652107000 nanoseconds
  MULTITHREADING - Sum: 125000000250000000
  MULTITHREADING - Sum: 375000000250000000
  MULTITHREADING - Elapsed time: 1 seconds & 271121000 nanoseconds
  MULTIPROCESSING - Child sum: 125000000250000000
  MULTITHREADING - Elapsed time: 1 seconds & 271121000 nanoseconds
  MULTIPROCESSING - Parent sum: 375000000250000000
  MULTIPROCESSING - Elapsed time: 1 seconds & 270017000 nanoseconds
  MULTITHREADING - Sum: 125000000250000000
  MULTITHREADING - Sum: 375000000250000000
  MULTITHREADING - Elapsed time: 1 seconds & 263026000 nanoseconds
  MULTIPROCESSING - Child sum: 125000000250000000
  MULTITHREADING - Elapsed time: 1 seconds & 263026000 nanoseconds
  MULTIPROCESSING - Parent sum: 375000000250000000
  MULTIPROCESSING - Elapsed time: 2 seconds & -722341000 nanoseconds
  MULTITHREADING - Sum: 125000000250000000
  MULTITHREADING - Sum: 375000000250000000
  MULTITHREADING - Elapsed time: 1 seconds & 261108000 nanoseconds
  MULTIPROCESSING - Child sum: 125000000250000000
  MULTITHREADING - Elapsed time: 1 seconds & 261108000 nanoseconds
  MULTIPROCESSING - Parent sum: 375000000250000000
  MULTIPROCESSING - Elapsed time: 1 seconds & 274580000 nanoseconds
  MULTITHREADING - Sum: 125000000250000000
  MULTITHREADING - Sum: 375000000250000000
  MULTITHREADING - Elapsed time: 2 seconds & -732768000 nanoseconds
  MULTIPROCESSING - Parent sum: 375000000250000000
  MULTITHREADING - Elapsed time: 2 seconds & -732768000 nanoseconds
  MULTIPROCESSING - Child sum: 125000000250000000
  MULTIPROCESSING - Elapsed time: 1 seconds & 311547000 nanoseconds
  MULTITHREADING - Sum: 125000000250000000
  MULTITHREADING - Sum: 375000000250000000
  MULTITHREADING - Elapsed time: 1 seconds & 263950000 nanoseconds
  MULTIPROCESSING - Child sum: 125000000250000000
  MULTITHREADING - Elapsed time: 1 seconds & 263950000 nanoseconds
  MULTIPROCESSING - Parent sum: 375000000250000000
  MULTIPROCESSING - Elapsed time: 1 seconds & 281155000 nanoseconds
  MULTITHREADING - Sum: 375000000250000000
  MULTITHREADING - Sum: 125000000250000000
  MULTITHREADING - Elapsed time: 2 seconds & -734153000 nanoseconds
  MULTIPROCESSING - Parent sum: 375000000250000000
  MULTITHREADING - Elapsed time: 2 seconds & -734153000 nanoseconds
  MULTIPROCESSING - Child sum: 125000000250000000
  MULTIPROCESSING - Elapsed time: 1 seconds & 278114000 nanoseconds
  MULTITHREADING - Sum: 375000000250000000
  MULTITHREADING - Sum: 125000000250000000
  MULTITHREADING - Elapsed time: 1 seconds & 268394000 nanoseconds
  MULTIPROCESSING - Child sum: 125000000250000000
  MULTITHREADING - Elapsed time: 1 seconds & 268394000 nanoseconds
  MULTIPROCESSING - Parent sum: 375000000250000000
  MULTIPROCESSING - Elapsed time: 1 seconds & 273923000 nanoseconds
  MULTITHREADING - Sum: 125000000250000000
  MULTITHREADING - Sum: 375000000250000000
  MULTITHREADING - Elapsed time: 2 seconds & -735864000 nanoseconds
  MULTIPROCESSING - Child sum: 125000000250000000
  MULTITHREADING - Elapsed time: 2 seconds & -735864000 nanoseconds
  MULTIPROCESSING - Parent sum: 375000000250000000
  MULTIPROCESSING - Elapsed time: 1 seconds & 286125000 nanoseconds
  MULTITHREADING - Sum: 125000000250000000
  MULTITHREADING - Sum: 375000000250000000
  ```
