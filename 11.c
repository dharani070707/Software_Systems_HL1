/*
Author : Dharani Prasad S
Description of problem solved :
Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    int fd, fd_dup1, fd_dup2, fd_dup3;

    fd = open("dup_test.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    fd_dup1 = dup(fd);
    if (fd_dup1 == -1) {
        perror("dup");
        exit(1);
    }

    fd_dup2 = dup2(fd, 10);   
    if (fd_dup2 == -1) {
        perror("dup2");
        exit(1);
    }

    fd_dup3 = fcntl(fd, F_DUPFD, 20);  
    if (fd_dup3 == -1) {
        perror("fcntl");
        exit(1);
    }

    write(fd, "Written using fd\n", 17);
    write(fd_dup1, "Written using dup\n", 18);
    write(fd_dup2, "Written using dup2\n", 19);
    write(fd_dup3, "Written using fcntl\n", 20);

    close(fd);
    close(fd_dup1);
    close(fd_dup2);
    close(fd_dup3);

    printf("Checking dup_test.txt to see all writes.\n");
    system("cat dup_test.txt");
    system("rm dup_test.txt");

    return 0;
}
/*
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./a.out 
Checking dup_test.txt to see all writes.
Written using fd
Written using dup
Written using dup2
Written using fcntl
*/
