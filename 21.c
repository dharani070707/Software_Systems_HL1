/*
 Author : Dharani Prasad S
 Description of problem solved : 
 Write a program, call fork and print the parent and child process id.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork();   // create child process

    if (pid < 0) {
        // fork failed
        perror("fork failed");
        return 1;
    }
    else if (pid == 0) {
        // child process
        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    }
    else {
        // parent process
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}
/*
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./a.out 
Parent process: PID = 3772, Child PID = 3773
Child process: PID = 3773, Parent PID = 3772
*/
