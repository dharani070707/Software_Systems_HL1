/*
 Author : Dharani Prasad S
 Description of problem solved : 
 Write a program to create a Zombie state of the running program.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0) {
        printf("Child process (PID: %d) exiting...\n", getpid());
        exit(0);
    }
    else {
        printf("Parent process (PID: %d) created child (PID: %d)\n", getpid(), pid);

        sleep(5);


        execlp("ps", "ps", "-l", NULL);

    }

    return 0;
}
/*
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./a.out 
Parent process (PID: 3873) created child (PID: 3874)
Child process (PID: 3874) exiting...
F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S  1000    3460    3452  0  80   0 -  2849 do_wai pts/0    00:00:00 bash
0 R  1000    3873    3460  0  80   0 -  3445 -      pts/0    00:00:00 ps
1 Z  1000    3874    3873  0  80   0 -     0 -      pts/0    00:00:00 a.out
*/
