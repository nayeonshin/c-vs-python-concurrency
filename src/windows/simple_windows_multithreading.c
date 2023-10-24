#include <stdio.h>
#include <windows.h> // Windows API header

#define LOOP_COUNT 10000

const char *HELLO_MESSAGE = "Thread %d: Hello, World!\n";
const char *ERROR_MESSAGE = "Thread %d: error\n";

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
    for (int i = 0; i < LOOP_COUNT; i++) {
        printf(HELLO_MESSAGE, 1);
    }
}

DWORD WINAPI print_thread2_hello(LPVOID lpParam)
{
    for (int i = 0; i < LOOP_COUNT; i++) {
        printf(HELLO_MESSAGE, 2);
    }
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
        fprintf(stderr, ERROR_MESSAGE, 1);
        return 1;
    }

    // Creates the second thread
    thread2 = CreateThread(NULL, 0, print_thread2_hello, NULL, 0, NULL);
    if (thread2 == NULL)
    {
        fprintf(stderr, ERROR_MESSAGE, 2);
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
