#include <stdio.h>
#include <windows.h> // Windows API header

const char *MESSAGE = "Thread %d: Hello, World!\n";
// TODO: create a constant for error message

/**
 * @param lpParam `LPVOID` stands for Long Pointer to VOID.
 *        It is a Windows API data type for a pointer to an unspecified data type
 *        or a pointer to any type.
 * @return DWORD, a 32-bit unsigned integer.
 *         WINAPI is a calling convention for Windows API functions.
 *         A calling convention is a set of rules that govern how functions are called
 *         and how parameters are passed between the caller and the callee.
 */
DWORD WINAPI print_thread1_hello(LPVOID lpParam)
{
    // TODO: Loop to see how the two threads take turns running
    // sleep
    // count up to 10,000 instead of sleeping
    printf(MESSAGE, 1);
}

DWORD WINAPI print_thread2_hello(LPVOID lpParam)
{
    printf(MESSAGE, 2);
}

int main()
{
    HANDLE thread1, thread2;

    // Creates the first thread
    /*
     * NULL: default security attributes
     * 0: default stack size
     * print_thread1_hello: function to be executed by the thread
     * NULL: argument passed to the thread function
     * 0: creation flags
     * NULL: thread identifier
     */
    thread1 = CreateThread(NULL, 0, print_thread1_hello, NULL, 0, NULL);
    // If there is an error
    if (thread1 == NULL)
    {
        // Prints an error message to the standard error output
        fprintf(stderr, "Thread 1: error\n");
        return 1;
    }

    // Creates the second thread
    thread2 = CreateThread(NULL, 0, print_thread2_hello, NULL, 0, NULL);
    if (thread2 == NULL)
    {
        fprintf(stderr, "Thread 2: error\n");
        return 1;
    }

    // Waits for both threads to finish
    // INFINITE timeout: function will wait indefinitely until the threads finish execution
    WaitForSingleObject(thread1, INFINITE);
    WaitForSingleObject(thread2, INFINITE);

    // Closes thread handles to clean up resources associated with the threads
    CloseHandle(thread1);
    CloseHandle(thread2);

    printf("Main thread: Both threads have finished.");

    return 0;
}
