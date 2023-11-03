#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_NUMBER 1000000000 // The upper limit for sum

struct Bounds {
    int start1;
    int start2;
    int end1;
    int end2;
};

long long calculate_sum(long long start, long long end);
int sum_using_multiprocessing(struct Bounds);
int sum_using_multithreading(struct Bounds);

const char* RESULT_MESSAGE = "MULTIPROCESSING - %s sum: %lld\n";

int main()
{
    struct Bounds bounds;
    bounds.start1 = 1;
    bounds.end1 = MAX_NUMBER / 2;
    bounds.start2 = bounds.end1 + 1;
    bounds.end2 = MAX_NUMBER;

    int multiprocessing_result = sum_using_multiprocessing(bounds);
    int multithreading_result = sum_using_multithreading(bounds);

    return multiprocessing_result & multithreading_result;
}

// Function to calculate the sum from start to end
long long calculate_sum_in_range(long long start, long long end) {
    long long sum = 0;

    for (long long num = start; num <= end; num++) {
        sum += num;
    }

    return sum;
}

// Function to be execute by a single thread
void *calculate(void *arg) {
    long long *params = (long long*) arg;
    long long sum = calculate_sum_in_range(params[0], params[1]);
    printf("MULTITHREADING - sum: %lld\n", sum);
    return NULL;
}

int sum_using_multiprocessing(struct Bounds bounds) {
    long long child_sum, parent_sum;
    long long child_start = bounds.start1, child_end = bounds.end1;
    long long parent_start = bounds.start2, parent_end = bounds.end2;

    pid_t child_pid;

    child_pid = fork();
    if (child_pid == -1) {
        perror("Fork failed.");
        return 1;
    }

    if (child_pid == 0) {
        // Child process calculates the sum for its portion.
        child_sum = calculate_sum_in_range(child_start, child_end);
        printf(RESULT_MESSAGE, "child", child_sum);

        exit(0);
    } else {
        // Parent process calculates the sum for its portion.
        parent_sum = calculate_sum_in_range(parent_start, parent_end);
        printf(RESULT_MESSAGE, "parent", parent_sum);

        // Waits for the child process to finish
        wait(NULL);
    }

    return 0;
}

int sum_using_multithreading(struct Bounds bounds) {
    long long thread1_sum, thread2_sum;
    long long start1 = bounds.start1, end1 = bounds.end1;
    long long start2 = bounds.start2, end2 = bounds.end2;

    pthread_t thread1;

    // start, end
    long long thread1_params[] = {start1, end1};
    long long thread2_params[] = {start2, end2};

    if (pthread_create(&thread1, NULL, calculate, thread1_params) != 0) {
        perror("pthread_create");
        return 1;
    }

    calculate(thread2_params);
    pthread_join(thread1, NULL);

    return 0;
}
