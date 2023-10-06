# C vs. Python Concurrency

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
