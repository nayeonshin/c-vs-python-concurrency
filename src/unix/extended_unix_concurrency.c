#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

#define MAX_NUMBER 1000000000 // The upper limit for sum

struct Bounds
{
    int start1;
    int start2;
    int end1;
    int end2;
};

long long calculate_sum(long long start, long long end);
int sum_using_multiprocessing(struct Bounds);
int sum_using_multithreading(struct Bounds);

const char *MULTIPROCESSING_MESSAGE = "MULTIPROCESSING - %s sum: %lld\n";
const char *TOTAL_TIME_MESSAGE = "%s - Total elapsed time: %lld second(s) & %lld nanoseconds\n";
const char *TIME_MESSAGE = "%s - Elapsed time: %lld second(s)";

int main()
{
    struct timespec start_time, end_time;
    long long elapsed_sec, elapsed_nsec;

    int multiprocessing_result, multithreading_result;

    struct Bounds bounds;
    bounds.start1 = 1;
    bounds.end1 = MAX_NUMBER / 2;
    bounds.start2 = bounds.end1 + 1;
    bounds.end2 = MAX_NUMBER;

    // Repeats 10 times for testing
    for (int i = 0; i < 10; i++)
    {
        // Measures time for multiprocessing
        clock_gettime(CLOCK_MONOTONIC, &start_time);
        multiprocessing_result = sum_using_multiprocessing(bounds);
        clock_gettime(CLOCK_MONOTONIC, &end_time);

        // Calculates elapsed time in seconds and nanoseconds
        elapsed_sec = end_time.tv_sec - start_time.tv_sec;
        elapsed_nsec = end_time.tv_nsec - start_time.tv_nsec;

        printf(TOTAL_TIME_MESSAGE, "MULTIPROCESSING", elapsed_sec, elapsed_nsec);

        // Measures time for multithreading
        clock_gettime(CLOCK_MONOTONIC, &start_time);
        multithreading_result = sum_using_multithreading(bounds);
        clock_gettime(CLOCK_MONOTONIC, &end_time);

        elapsed_sec = end_time.tv_sec - start_time.tv_sec;
        elapsed_nsec = end_time.tv_nsec - start_time.tv_nsec;

        printf(TOTAL_TIME_MESSAGE, "MULTITHREADING", elapsed_sec, elapsed_nsec);
    }

    return multiprocessing_result & multithreading_result;
}

// Function to calculate the sum from start to end
long long calculate_sum_in_range(long long start, long long end)
{
    long long sum = 0;

    for (long long num = start; num <= end; num++)
    {
        sum += num;
    }

    return sum;
}

// Function to be execute by a single thread
void *calculate(void *arg)
{
    long long *params = (long long *)arg;
    long long sum = calculate_sum_in_range(params[0], params[1]);
    printf("MULTITHREADING - Sum: %lld\n", sum);
    return NULL;
}

int sum_using_multiprocessing(struct Bounds bounds)
{
    struct timespec parent_start_time, parent_end_time, child_start_time, child_end_time;
    long long elapsed_sec;

    long long child_sum, parent_sum;
    long long child_start = bounds.start1, child_end = bounds.end1;
    long long parent_start = bounds.start2, parent_end = bounds.end2;

    pid_t child_pid;

    // Measures time for parent process
    clock_gettime(CLOCK_MONOTONIC, &parent_start_time);
    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Fork failed.");
        return 1;
    }

    if (child_pid == 0)
    {
        // Measures time for child process
        clock_gettime(CLOCK_MONOTONIC, &child_start_time);

        // Child process calculates the sum for its portion.
        child_sum = calculate_sum_in_range(child_start, child_end);
        printf(MULTIPROCESSING_MESSAGE, "Child", child_sum);
        exit(0);

        clock_gettime(CLOCK_MONOTONIC, &parent_end_time);
        elapsed_sec = parent_end_time.tv_sec - parent_start_time.tv_sec;
        printf(TIME_MESSAGE, "Parent process", elapsed_sec);
    }
    else
    {
        // Parent process calculates the sum for its portion.
        parent_sum = calculate_sum_in_range(parent_start, parent_end);
        printf(MULTIPROCESSING_MESSAGE, "Parent", parent_sum);
        // Waits for the child process to finish
        wait(NULL);

        clock_gettime(CLOCK_MONOTONIC, &parent_end_time);
        elapsed_sec = parent_end_time.tv_sec - parent_start_time.tv_sec;
        printf(TIME_MESSAGE, "Parent process", elapsed_sec);
    }

    return 0;
}

int sum_using_multithreading(struct Bounds bounds)
{
    struct timespec thread1_start_time, thread1_end_time, thread2_start_time, thread2_end_time;
    long long elapsed_sec;

    long long thread1_sum, thread2_sum;
    long long start1 = bounds.start1, end1 = bounds.end1;
    long long start2 = bounds.start2, end2 = bounds.end2;

    pthread_t thread1;

    // start, end
    long long thread1_params[] = {start1, end1};
    long long thread2_params[] = {start2, end2};

    // Measures time for thread 1
    clock_gettime(CLOCK_MONOTONIC, &thread1_start_time);
    if (pthread_create(&thread1, NULL, calculate, thread1_params) != 0)
    {
        perror("pthread_create");
        return 1;
    }

    // Measures time for thread 2
    clock_gettime(CLOCK_MONOTONIC, &thread2_start_time);
    calculate(thread2_params);
    clock_gettime(CLOCK_MONOTONIC, &thread2_end_time);
    elapsed_sec = thread2_end_time.tv_sec - thread2_start_time.tv_sec;
    printf(TIME_MESSAGE, "Thread 2", elapsed_sec);

    pthread_join(thread1, NULL);
    clock_gettime(CLOCK_MONOTONIC, &thread1_end_time);
    elapsed_sec = thread1_end_time.tv_sec - thread1_start_time.tv_sec;
    printf(TIME_MESSAGE, "Thread 1", elapsed_sec);

    return 0;
}
