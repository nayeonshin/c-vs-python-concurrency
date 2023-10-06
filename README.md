# C vs. Python Concurrency

* Python
  * Thread-safe: safe for multithreading; if something is not thread-safe, values in thread 1 can change in thread 2, causing problems
  * Mostly utilizes multiprocessing because multithreading makes little sense due to the nature of GIL
  * When we talk about guaranteeing thread safety, we mean providing locking internally, which incurs locking overhead and affects performance
