#include <stdio.h>
#include <unistd.h>

const char* MESSAGE = "%s process: My PID is %d\n.";

int main() {
    pid_t child_pid;

    // Creates a child process
    child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed.");
        return 1;
    }

    if (child_pid == 0) {
        // This code is executed by the child process.
        printf(MESSAGE, "Child", getpid());
    } else {
        // This code is executed by the parent process.
        printf(MESSAGE, "Parent", getpid());
        printf("Child process PID: %d\n", child_pid);
    }

    return 0;
}