#include <stdio.h>
#include <windows.h>

const char* MESSAGE = "Parent process: Child process %s\n.";
const char* PROGRAM_NAME = "notepad.exe";

int main() {
    // Structures used to store information about the new process
    // such as its attributes and handles
    STARTUPINFO si; // Used to specify the characteristics and behavior of a new process
    PROCESS_INFORMATION pi; // Used to retrieve information about new process

    // Initializes the above structures to establish a clean and preditable starting point
    ZeroMemory(&si, sizeof(si));  // Sets all the bytes in the structures to zero
    si.cb = sizeof(si); // Sets the size to ensure that the structures are properly initialized
    ZeroMemory(&pi, sizeof(pi));

    // If it fails
    if (!CreateProcess(
        NULL,          // Application name
        PROGRAM_NAME, // Command to run
        NULL,          // Process security attributes
        NULL,          // Thread security attributes
        FALSE,         // Inherit handles from the parent process
        0,             // Creation flags; in this case, no special flags are set.
        NULL,          // Environment block; the new process inherits the env vars from parent
        NULL,          // Current directory; the new process uses current dir of parent
        &si,           // STARTUPINFO structure
        &pi            // PROCESS_INFORMATION structure
    )) {
        fprintf(stderr, "CreateProcess failed");
        return 1;
    }

    printf(MESSAGE, "created and running Notepad");

    // Waits for the child process to exit
    WaitForSingleObject(pi.hProcess, INFINITE);

    printf(MESSAGE, "has exited.\n");
    printf("Parent process has excited.\n");

    // Closes process and thread handles to avoid resource leaks
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
