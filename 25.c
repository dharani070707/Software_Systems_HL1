/*
 Author : Dharani Prasad S
 Description of problem solved : 
 Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t cpid1, cpid2, cpid3;

    // First child
    if ((cpid1 = fork()) == 0) {
        printf("Child 1 (PID: %d) running\n", getpid());
        sleep(1);
        exit(0);
    }

    // Second child
    if ((cpid2 = fork()) == 0) {
        printf("Child 2 (PID: %d) running\n", getpid());
        sleep(3);
        exit(0);
    }

    // Third child
    if ((cpid3 = fork()) == 0) {
        printf("Child 3 (PID: %d) running\n", getpid());
        sleep(10);
        exit(0);
    }

    // Parent waits specifically for second child
    int status;
    pid_t w = waitpid(cpid2, &status, 0);
    if (w == -1) {
        perror("waitpid");
    } else {
        printf("Parent waited for Child 2 (PID: %d), exited with status %d\n",
               w, WEXITSTATUS(status));
    }

    return 0;
}
/*
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./a.out 
Child 1 (PID: 4886) running
Child 2 (PID: 4887) running
Child 3 (PID: 4888) running

Parent waited for Child 2 (PID: 4887), exited with status 0
*/
