from multiprocessing import Process
from os import getpid

MESSAGE = "{} process: My PID is {}."


def print_message():
    # This code is executed by the child process.
    print(MESSAGE.format("Child", getpid()))


def main():
    # Creates a child process
    child = Process(target=print_message)
    child.start()

    # This code is executed by the parent process.
    print(MESSAGE.format("Parent", getpid()))
    print("Child process PID: ", child.pid)

    child.join()


if __name__ == "__main__":
    main()
