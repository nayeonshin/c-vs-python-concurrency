#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ERROR_VALUE -1
#define MAX_NUMBER 1000000000 // The upper limit for sum

const char* RESULT_MESSAGE = "%s sum: %lld\n";

long long calculate_sum(long long start, long long end);
int sum_using_multiprocessing();

int main()
{
    sum_using_multiprocessing();
}

// Function to calculate the sum from start to end
long long calculate_sum_in_range(long long start, long long end) {
    long long sum = 0;

    for (long long num = start; num <= end; num++) {
        sum += num;
    }

    return sum;
}

int sum_using_multiprocessing() {
    long long child_sum, parent_sum;

    long long child_start = 1, child_end = MAX_NUMBER / 2;
    long long parent_start = child_end + 1, parent_end = MAX_NUMBER;

    int pipe_fd[2];
    pid_t child_pid;

    // Creates a pipe
    if (pipe(pipe_fd) == -1) {
        printf("HELLO!!!!");
        perror("Pipe creation failed.");
        return 1;
    }

    child_pid = fork();
    if (child_pid < 0) {
        perror("Fork failed.");
        return 1;
    }

    if (child_pid == 0) {
        // Child process calculates the sum for its portion.
        child_sum = calculate_sum_in_range(child_start, child_end);
        // Writes the result to the pipe
        close(pipe_fd[0]); // Closes the read end of the pipe
        write(pipe_fd[1], &child_sum, sizeof(long long));
        close(pipe_fd[1]);  // Close the write end of the pipe

        exit(0);
    } else {
        // Parent process calculates the sum for its portion.
        parent_sum = calculate_sum_in_range(parent_start, parent_end);

        // Waits for the child process to finish
        int status;
        wait(&status);

        // Reads the result from the pipe
        close(pipe_fd[1]); // Closes the write end of the pipe
        read(pipe_fd[0], &child_sum, sizeof(long long));
        close(pipe_fd[0]);  // Closes the read end of the pipe

        printf(RESULT_MESSAGE, "Multiprocessing", child_sum + parent_sum);

        return 0;
    }
}
