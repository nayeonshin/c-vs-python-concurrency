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
```
MULTIPROCESSING - Child sum: 125000000250000000
MULTIPROCESSING - Parent sum: 375000000250000000
MULTIPROCESSING - Elapsed time: 2 seconds & -499685221 nanoseconds
MULTITHREADING - Sum: 375000000250000000
MULTITHREADING - Sum: 125000000250000000
MULTITHREADING - Elapsed time: 1 seconds & 466343694 nanoseconds
MULTIPROCESSING - Child sum: 125000000250000000
MULTIPROCESSING - Parent sum: 375000000250000000
MULTIPROCESSING - Elapsed time: 2 seconds & -583534862 nanoseconds
MULTITHREADING - Sum: 375000000250000000
MULTITHREADING - Sum: 125000000250000000
MULTITHREADING - Elapsed time: 1 seconds & 421848298 nanoseconds
MULTIPROCESSING - Parent sum: 375000000250000000
MULTIPROCESSING - Child sum: 125000000250000000
MULTIPROCESSING - Elapsed time: 2 seconds & -621611791 nanoseconds
MULTITHREADING - Sum: 125000000250000000
MULTITHREADING - Sum: 375000000250000000
MULTITHREADING - Elapsed time: 1 seconds & 379889516 nanoseconds
MULTIPROCESSING - Parent sum: 375000000250000000
MULTIPROCESSING - Child sum: 125000000250000000
MULTIPROCESSING - Elapsed time: 1 seconds & 364613317 nanoseconds
MULTITHREADING - Sum: 375000000250000000
MULTITHREADING - Sum: 125000000250000000
MULTITHREADING - Elapsed time: 2 seconds & -623737969 nanoseconds
MULTIPROCESSING - Parent sum: 375000000250000000
MULTIPROCESSING - Child sum: 125000000250000000
MULTIPROCESSING - Elapsed time: 1 seconds & 382625026 nanoseconds
MULTITHREADING - Sum: 375000000250000000
MULTITHREADING - Sum: 125000000250000000
MULTITHREADING - Elapsed time: 2 seconds & -616986582 nanoseconds
MULTIPROCESSING - Child sum: 125000000250000000
MULTIPROCESSING - Parent sum: 375000000250000000
MULTIPROCESSING - Elapsed time: 1 seconds & 370934898 nanoseconds
MULTITHREADING - Sum: 375000000250000000
MULTITHREADING - Sum: 125000000250000000
MULTITHREADING - Elapsed time: 1 seconds & 381489271 nanoseconds
MULTIPROCESSING - Child sum: 125000000250000000
MULTIPROCESSING - Parent sum: 375000000250000000
MULTIPROCESSING - Elapsed time: 2 seconds & -602459486 nanoseconds
MULTITHREADING - Sum: 375000000250000000
MULTITHREADING - Sum: 125000000250000000
MULTITHREADING - Elapsed time: 1 seconds & 384620785 nanoseconds
MULTIPROCESSING - Child sum: 125000000250000000
MULTIPROCESSING - Parent sum: 375000000250000000
MULTIPROCESSING - Elapsed time: 1 seconds & 409549674 nanoseconds
MULTITHREADING - Sum: 125000000250000000
MULTITHREADING - Sum: 375000000250000000
MULTITHREADING - Elapsed time: 2 seconds & -600105027 nanoseconds
MULTIPROCESSING - Child sum: 125000000250000000
MULTIPROCESSING - Parent sum: 375000000250000000
MULTIPROCESSING - Elapsed time: 1 seconds & 384002247 nanoseconds
MULTITHREADING - Sum: 125000000250000000
MULTITHREADING - Sum: 375000000250000000
MULTITHREADING - Elapsed time: 2 seconds & -619433794 nanoseconds
MULTIPROCESSING - Child sum: 125000000250000000
MULTIPROCESSING - Parent sum: 375000000250000000
MULTIPROCESSING - Elapsed time: 1 seconds & 413724392 nanoseconds
MULTITHREADING - Sum: 125000000250000000
MULTITHREADING - Sum: 375000000250000000
MULTITHREADING - Elapsed time: 1 seconds & 394728554 nanoseconds
```
### Python
```
MULTIPROCESSING - parent sum: 375000000250000000
Elapsed time: 7.2514 seconds
MULTIPROCESSING - child sum: 125000000250000000
Elapsed time: 7.2593 seconds
MULTIPROCESSING - parent sum: 375000000250000000
Elapsed time: 6.8909 seconds
MULTIPROCESSING - child sum: 125000000250000000
Elapsed time: 6.9000 seconds
MULTIPROCESSING - parent sum: 375000000250000000
Elapsed time: 6.7831 seconds
MULTIPROCESSING - child sum: 125000000250000000
Elapsed time: 6.8175 seconds
MULTIPROCESSING - parent sum: 375000000250000000
Elapsed time: 6.8093 seconds
MULTIPROCESSING - child sum: 125000000250000000
Elapsed time: 6.8095 seconds
MULTIPROCESSING - parent sum: 375000000250000000
Elapsed time: 6.7336 seconds
MULTIPROCESSING - child sum: 125000000250000000
Elapsed time: 6.7806 seconds
MULTIPROCESSING - parent sum: 375000000250000000
Elapsed time: 6.8401 seconds
MULTIPROCESSING - child sum: 125000000250000000
Elapsed time: 6.8557 seconds
MULTIPROCESSING - parent sum: 375000000250000000
Elapsed time: 6.8562 seconds
MULTIPROCESSING - child sum: 125000000250000000
Elapsed time: 6.8861 seconds
MULTIPROCESSING - child sum: 125000000250000000
Elapsed time: 6.8576 seconds
MULTIPROCESSING - parent sum: 375000000250000000
Elapsed time: 6.8585 seconds
MULTIPROCESSING - parent sum: 375000000250000000
Elapsed time: 6.8767 seconds
MULTIPROCESSING - child sum: 125000000250000000
Elapsed time: 6.8889 seconds
MULTIPROCESSING - parent sum: 375000000250000000
Elapsed time: 6.8910 seconds
MULTIPROCESSING - child sum: 125000000250000000
Elapsed time: 6.9079 seconds
MULTITHREADING - sum: 125000000250000000
Elapsed time: 6.5146 seconds
MULTITHREADING - sum: 375000000250000000
Elapsed time: 6.4522 seconds
Total elapsed time: 12.9672 seconds
MULTITHREADING - sum: 125000000250000000
Elapsed time: 12.6901 seconds
MULTITHREADING - sum: 375000000250000000
Elapsed time: 6.3458 seconds
Total elapsed time: 12.6904 seconds
MULTITHREADING - sum: 125000000250000000
Elapsed time: 6.5151 seconds
MULTITHREADING - sum: 375000000250000000
Elapsed time: 7.3046 seconds
Total elapsed time: 13.8200 seconds
MULTITHREADING - sum: 375000000250000000
Elapsed time: 6.7045 seconds
MULTITHREADING - sum: 125000000250000000
Elapsed time: 14.6300 seconds
Total elapsed time: 14.6303 seconds
MULTITHREADING - sum: 125000000250000000
Elapsed time: 12.9159 seconds
MULTITHREADING - sum: 375000000250000000
Elapsed time: 6.4605 seconds
Total elapsed time: 12.9162 seconds
MULTITHREADING - sum: 125000000250000000
Elapsed time: 13.0238 seconds
MULTITHREADING - sum: 375000000250000000
Elapsed time: 6.5294 seconds
Total elapsed time: 13.0241 seconds
MULTITHREADING - sum: 125000000250000000
Elapsed time: 13.4993 seconds
MULTITHREADING - sum: 375000000250000000
Elapsed time: 6.9382 seconds
Total elapsed time: 13.4997 seconds
MULTITHREADING - sum: 375000000250000000
Elapsed time: 6.4555 seconds
MULTITHREADING - sum: 125000000250000000
Elapsed time: 12.9622 seconds
Total elapsed time: 12.9624 seconds
MULTITHREADING - sum: 125000000250000000
Elapsed time: 6.5012 seconds
MULTITHREADING - sum: 375000000250000000
Elapsed time: 6.5234 seconds
Total elapsed time: 13.0248 seconds
MULTITHREADING - sum: 125000000250000000
Elapsed time: 12.9386 seconds
MULTITHREADING - sum: 375000000250000000
Elapsed time: 6.4377 seconds
Total elapsed time: 12.9389 seconds
```
### Python with GIL disabled
```
MULTIPROCESSING - parent sum: 375000000250000000
Elapsed time: 9.2781 seconds
MULTIPROCESSING - child sum: 125000000250000000
Elapsed time: 9.2903 seconds
MULTIPROCESSING - parent sum: 375000000250000000
Elapsed time: 8.9958 seconds
MULTIPROCESSING - child sum: 125000000250000000
Elapsed time: 9.0027 seconds
MULTIPROCESSING - parent sum: 375000000250000000
Elapsed time: 8.8130 seconds
MULTIPROCESSING - child sum: 125000000250000000
Elapsed time: 8.8824 seconds
MULTIPROCESSING - child sum: 125000000250000000
Elapsed time: 8.8240 seconds
MULTIPROCESSING - parent sum: 375000000250000000
Elapsed time: 9.3511 seconds
MULTIPROCESSING - parent sum: 375000000250000000
Elapsed time: 8.7856 seconds
MULTIPROCESSING - child sum: 125000000250000000
Elapsed time: 8.9390 seconds
MULTIPROCESSING - parent sum: 375000000250000000
Elapsed time: 8.8271 seconds
MULTIPROCESSING - child sum: 125000000250000000
Elapsed time: 8.8429 seconds
MULTIPROCESSING - child sum: 125000000250000000
Elapsed time: 8.7293 seconds
MULTIPROCESSING - parent sum: 375000000250000000
Elapsed time: 8.7332 seconds
MULTIPROCESSING - parent sum: 375000000250000000
Elapsed time: 8.7519 seconds
MULTIPROCESSING - child sum: 125000000250000000
Elapsed time: 8.7557 seconds
MULTIPROCESSING - parent sum: 375000000250000000
Elapsed time: 8.8093 seconds
MULTIPROCESSING - child sum: 125000000250000000
Elapsed time: 8.8760 seconds
MULTIPROCESSING - child sum: 125000000250000000
Elapsed time: 8.7335 seconds
MULTIPROCESSING - parent sum: 375000000250000000
Elapsed time: 8.7382 seconds
MULTITHREADING - sum: 125000000250000000
Elapsed time: 8.4339 seconds
MULTITHREADING - sum: 375000000250000000
Elapsed time: 8.4373 seconds
Total elapsed time: 8.4386 seconds
MULTITHREADING - sum: 125000000250000000
Elapsed time: 8.4831 seconds
MULTITHREADING - sum: 375000000250000000
Elapsed time: 8.5176 seconds
Total elapsed time: 8.5181 seconds
MULTITHREADING - sum: 375000000250000000
Elapsed time: 8.4700 seconds
MULTITHREADING - sum: 125000000250000000
Elapsed time: 8.6625 seconds
Total elapsed time: 8.6628 seconds
MULTITHREADING - sum: 375000000250000000
Elapsed time: 8.7715 seconds
MULTITHREADING - sum: 125000000250000000
Elapsed time: 9.1789 seconds
Total elapsed time: 9.1792 seconds
MULTITHREADING - sum: 375000000250000000
Elapsed time: 8.5403 seconds
MULTITHREADING - sum: 125000000250000000
Elapsed time: 8.7045 seconds
Total elapsed time: 8.7049 seconds
MULTITHREADING - sum: 375000000250000000
Elapsed time: 8.6328 seconds
MULTITHREADING - sum: 125000000250000000
Elapsed time: 8.6381 seconds
Total elapsed time: 8.6384 seconds
MULTITHREADING - sum: 375000000250000000
Elapsed time: 8.5279 seconds
MULTITHREADING - sum: 125000000250000000
Elapsed time: 8.7053 seconds
Total elapsed time: 8.7057 seconds
MULTITHREADING - sum: 375000000250000000
Elapsed time: 8.5383 seconds
MULTITHREADING - sum: 125000000250000000
Elapsed time: 8.7318 seconds
Total elapsed time: 8.7322 seconds
MULTITHREADING - sum: 375000000250000000
Elapsed time: 8.5395 seconds
MULTITHREADING - sum: 125000000250000000
Elapsed time: 8.9919 seconds
Total elapsed time: 8.9922 seconds
MULTITHREADING - sum: 375000000250000000
Elapsed time: 8.5238 seconds
MULTITHREADING - sum: 125000000250000000
Elapsed time: 8.7469 seconds
Total elapsed time: 8.7472 seconds
```
