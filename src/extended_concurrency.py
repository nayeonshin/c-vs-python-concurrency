from multiprocessing import Process
from threading import Thread

MAX_NUMBER = 1000000000  # The upper limit for the sum


def calculate_sum_in_range(start: int, end: int) -> int:
    return sum(range(start, end + 1))


def calculate_for_process(start: int, end: int, name: str) -> None:
    result = calculate_sum_in_range(start, end)
    print(f"MULTIPROCESSING - {name} sum: {result}")


def calculate_for_thread(start: int, end: int) -> None:
    result = calculate_sum_in_range(start, end)
    print(f"MULTITHREADING - sum: {result}")


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

    thread1.start()
    thread2.start()

    thread1.join()
    thread2.join()


if __name__ == "__main__":
    bounds = 1, MAX_NUMBER // 2, (MAX_NUMBER // 2) + 1, MAX_NUMBER

    sum_using_multiprocessing(bounds)
    sum_using_multithreading(bounds)
