/*
 Author : Dharani Prasad S
 Description of problem solved : 
 Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int fd;
    pid_t pid;

    fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open failed");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }
    else if (pid == 0) {
        char *msg = "Hello from Child process\n";
        write(fd, msg, strlen(msg));
        close(fd);

    }
    else {
        char *msg = "Hello from Parent process\n";
        write(fd, msg, strlen(msg));
        close(fd);

        wait(0);

        execlp("cat", "cat", "output.txt", NULL);
        perror("execlp failed");
        exit(1);
    }
    //no overwriting happens here 
    return 0;
}
/*
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./a.out 
Hello from Parent process
Hello from Child process
*/
