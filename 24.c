/*
 Author : Dharani Prasad S
 Description of problem solved : 
 Write a program to create an orphan process.
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0) {
        printf("Child process started. PID = %d, Parent PID = %d\n", getpid(), getppid());
        
        sleep(5);

        printf("Child process still running. PID = %d, New Parent PID = %d (orphaned)\n", getpid(), getppid());
    }
    else {
        printf("Parent process exiting. PID = %d\n", getpid());
        exit(0);   // Parent exits immediately
    }

    return 0;
}
/*
Parent process exiting. PID = 3922
Child process started. PID = 3923, Parent PID = 3922
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ Child process still running. PID = 3923, New Parent PID = 2258 (orphaned)
*/
