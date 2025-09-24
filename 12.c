/*
Author : Dharani Prasad S
Description of problem solved :
Write a program to find out the opening mode of a file. Use fcntl.
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    fd = open("lseek.txt", O_RDWR | O_APPEND);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // get file status flags
    int flags = fcntl(fd, F_GETFL);
    if (flags < 0) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    // extract access mode
    int accmode = flags & O_ACCMODE;

    if (accmode == O_RDONLY)
        printf("File opened in READ only mode\n");
    else if (accmode == O_WRONLY)
        printf("File opened in WRITE only mode\n");
    else if (accmode == O_RDWR)
        printf("File opened in READ/WRITE mode\n");

    if (flags & O_APPEND)
        printf("File has APPEND mode enabled\n");
    if (flags & O_NONBLOCK)
        printf("File has NON-BLOCKING mode enabled\n");
    if (flags & O_SYNC)
        printf("File has SYNCHRONOUS WRITE mode enabled\n");

    close(fd);
    return 0;
}
/*
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./a.out 
File opened in READ/WRITE mode
File has APPEND mode enabled
*/
