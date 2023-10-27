from threading import Thread

LOOP_COUNT = 10000
HELLO_MESSAGE = "Thread {}: Hello, World!\n"


# Function to be executed by the first thread
def print_thread1_hello():
    for _ in range(LOOP_COUNT):
        print(HELLO_MESSAGE.format(1))


# Function to be executed by the second thread
def print_thread2_hello():
    for _ in range(LOOP_COUNT):
        print(HELLO_MESSAGE.format(2))


def main():
    thread1 = Thread(target=print_thread1_hello)
    thread2 = Thread(target=print_thread2_hello)

    # Creates the first thread
    thread1.start()
    # Creates the second thread
    thread2.start()

    # Waits for both threads to finish
    thread1.join()
    thread2.join()

    print("Main thread: Both threads have finished.")


if __name__ == "__main__":
    main()
