#include <stdio.h>
#include <pthread.h>

#define LOOP_COUNT 10000

const char *HELLO_MESSAGE = "Thread %d: Hello, World!\n";

// Function to be executed by the first thread
void *print_thread1_hello(void *arg)
{
    for (int i = 0; i < LOOP_COUNT; i++)
    {
        printf(HELLO_MESSAGE, 1);
    }
    return NULL;
}

// Function to be executed by the second thread
void *print_thread2_hello(void *arg)
{
    for (int i = 0; i < LOOP_COUNT; i++)
    {
        printf(HELLO_MESSAGE, 2);
    }
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    // Creates the first thread
    if (pthread_create(&thread1, NULL, print_thread1_hello, NULL) != 0)
    {
        perror("Thread 1: pthread_create");
        return 1;
    }

    // Creates the second thread
    if (pthread_create(&thread2, NULL, print_thread2_hello, NULL) != 0)
    {
        perror("Thread 2: pthread_create");
        return 1;
    }

    // Waits for both threads to finish
    if (pthread_join(thread1, NULL) != 0)
    {
        perror("Thread 1: pthread_join");
        return 1;
    }
    if (pthread_join(thread2, NULL) != 0)
    {
        perror("Thread 2: pthread_join");
        return 1;
    }

    printf("Main thread: Both threads have finished.\n");

    return 0;
}