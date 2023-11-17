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
### Python
- ```
  MULTIPROCESSING - child sum: 125000000250000000
  Elapsed time: 10.3505 seconds
  MULTIPROCESSING - parent sum: 375000000250000000
  Elapsed time: 10.8930 seconds
  MULTIPROCESSING - child sum: 125000000250000000
  Elapsed time: 9.9217 seconds
  MULTIPROCESSING - parent sum: 375000000250000000
  Elapsed time: 10.4201 seconds
  MULTIPROCESSING - child sum: 125000000250000000
  Elapsed time: 10.0054 seconds
  MULTIPROCESSING - parent sum: 375000000250000000
  Elapsed time: 10.4874 seconds
  MULTIPROCESSING - child sum: 125000000250000000
  Elapsed time: 10.8732 seconds
  MULTIPROCESSING - parent sum: 375000000250000000
  Elapsed time: 11.3635 seconds
  MULTIPROCESSING - child sum: 125000000250000000
  Elapsed time: 12.7589 seconds
  MULTIPROCESSING - parent sum: 375000000250000000
  Elapsed time: 13.2249 seconds
  MULTIPROCESSING - child sum: 125000000250000000
  Elapsed time: 11.7908 seconds
  MULTIPROCESSING - parent sum: 375000000250000000
  Elapsed time: 12.3251 seconds
  MULTIPROCESSING - child sum: 125000000250000000
  Elapsed time: 10.5399 seconds
  MULTIPROCESSING - parent sum: 375000000250000000
  Elapsed time: 11.0465 seconds
  MULTIPROCESSING - child sum: 125000000250000000
  Elapsed time: 14.0985 seconds
  MULTIPROCESSING - parent sum: 375000000250000000
  Elapsed time: 14.7141 seconds
  MULTIPROCESSING - parent sum: 375000000250000000
  Elapsed time: 12.9177 seconds
  MULTIPROCESSING - child sum: 125000000250000000
  Elapsed time: 12.7725 seconds
  MULTIPROCESSING - child sum: 125000000250000000
  Elapsed time: 10.9024 seconds
  MULTIPROCESSING - parent sum: 375000000250000000
  Elapsed time: 11.4107 seconds
  MULTITHREADING - sum: 125000000250000000
  MULTITHREADING - sum: 375000000250000000
  Elapsed time: 20.5378 seconds
  Elapsed time: 10.3211 seconds
  Total elapsed time: 20.5383 seconds
  MULTITHREADING - sum: 125000000250000000
  Elapsed time: 10.5405 seconds
  MULTITHREADING - sum: 375000000250000000
  Elapsed time: 10.2845 seconds
  Total elapsed time: 20.8253 seconds
  MULTITHREADING - sum: 125000000250000000
  Elapsed time: 20.4475 seconds
  MULTITHREADING - sum: 375000000250000000
  Elapsed time: 10.1938 seconds
  Total elapsed time: 20.4478 seconds
  MULTITHREADING - sum: 125000000250000000
  Elapsed time: 10.2529 seconds
  MULTITHREADING - sum: 375000000250000000
  Elapsed time: 10.3536 seconds
  Total elapsed time: 20.6068 seconds
  MULTITHREADING - sum: 125000000250000000
  Elapsed time: 10.2210 seconds
  MULTITHREADING - sum: 375000000250000000
  Elapsed time: 10.2929 seconds
  Total elapsed time: 20.5142 seconds
  MULTITHREADING - sum: 375000000250000000
  MULTITHREADING - sum: 125000000250000000
  Elapsed time: 20.4080 seconds
  Elapsed time: 10.2137 seconds
  Total elapsed time: 20.4082 seconds
  MULTITHREADING - sum: 125000000250000000
  MULTITHREADING - sum: 375000000250000000
  Elapsed time: 20.5610 seconds
  Elapsed time: 10.2405 seconds
  Total elapsed time: 20.5613 seconds
  MULTITHREADING - sum: 125000000250000000
  Elapsed time: 20.4908 seconds
  MULTITHREADING - sum: 375000000250000000
  Elapsed time: 10.3205 seconds
  Total elapsed time: 20.4911 seconds
  MULTITHREADING - sum: 125000000250000000
  MULTITHREADING - sum: 375000000250000000
  Elapsed time: 10.6589 seconds
  Elapsed time: 20.9045 seconds
  Total elapsed time: 20.9048 seconds
  MULTITHREADING - sum: 125000000250000000
  Elapsed time: 22.2828 seconds
  MULTITHREADING - sum: 375000000250000000
  Elapsed time: 10.8728 seconds
  Total elapsed time: 22.2830 seconds
  ```