from multiprocessing import Process
from threading import Thread
from time import time

MAX_NUMBER = 1000000000  # The upper limit for the sum
TIME_MESSAGE = "Elapsed time: {:.4f} seconds"


def calculate_sum_in_range(start: int, end: int) -> int:
    return sum(range(start, end + 1))


def calculate_for_process(start: int, end: int, name: str) -> None:
    # start_time = time()
    result = calculate_sum_in_range(start, end)
    # end_time = time()
    print(f"MULTIPROCESSING - {name} sum: {result}")
    # print(TIME_MESSAGE.format(end_time - start_time))


def calculate_for_thread(start: int, end: int) -> None:
    # start_time = time()
    result = calculate_sum_in_range(start, end)
    # end_time = time()
    print(f"MULTITHREADING - sum: {result}")
    # print(TIME_MESSAGE.format(end_time - start_time))


def sum_using_multiprocessing(bounds: tuple[str]) -> None:
    child_start, child_end, parent_start, parent_end = bounds

    child = Process(
        target=calculate_for_process, args=(child_start, child_end, "child")
    )
    child.start()

    calculate_for_process(parent_start, parent_end, "parent")

    child.join()


def sum_using_multithreading(bounds: tuple[int]) -> None:
    start1, end1, start2, end2 = bounds

    thread1 = Thread(target=calculate_for_thread, args=(start1, end1))
    thread2 = Thread(target=calculate_for_thread, args=(start2, end2))

    # start_time = time()

    thread1.start()
    thread2.start()

    thread1.join()
    thread2.join()

    # end_time = time()
    # message = "Total " + TIME_MESSAGE[0].lower() + TIME_MESSAGE[1:]
    # print(message.format(end_time - start_time))


if __name__ == "__main__":
    bounds = 1, MAX_NUMBER // 2, (MAX_NUMBER // 2) + 1, MAX_NUMBER

    # for _ in range(10):
    sum_using_multiprocessing(bounds)
    # for _ in range(10):
    sum_using_multithreading(bounds)
