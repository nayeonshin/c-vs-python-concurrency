#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_NUMBER 10 // The upper limit for sum

int calculate_sum(int start, int end);

int main()
{
    // Multiprocessing
    int child_sum, parent_sum;

    int child_start = 1, child_end = MAX_NUMBER / 2;
    int parent_start = child_end + 1, parent_end = MAX_NUMBER;

    int pipe_fd[2];
    pid_t child_pid;

    // Creates a pipe
    if (pipe(pipe_fd) == -1) {
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
        child_sum = calculate_sum(child_start, child_end);
        // Writes the result to the pipe
        close(pipe_fd[0]); // Closes the read end of the pipe
        write(pipe_fd[1], &child_sum, sizeof(int));
        close(pipe_fd[1]);  // Close the write end of the pipe

        exit(0);
    } else {
        // Parent process calculates the sum for its portion.
        parent_sum = calculate_sum(parent_start, parent_end);

        // Waits for the child process to finish
        int status;
        wait(&status);

        // Reads the result from the pipe
        close(pipe_fd[1]); // Closes the write end of the pipe
        read(pipe_fd[0], &child_sum, sizeof(int));
        close(pipe_fd[0]);  // Closes the read end of the pipe

        printf("Multiprocessing sum: %d\n", child_sum + parent_sum);

        return 0;
    }
}

// Function to calculate the sum from start to end
int calculate_sum(int start, int end) {
    int sum = 0;

    for (int num = start; num <= end; num++) {
        sum += num;
    }

    return sum;
}