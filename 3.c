/*
 Author : Dharani Prasad S
 Description of problem solved : 
 Write a program to create a file and print the file descriptor value. Use creat ( ) system call
*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd = creat("testFileCreat.txt", 0755);
    if (fd == -1) {
        perror("creat");
        exit(1);
    } else {
        printf("Created Successfully\n");
        printf("file descriptor value is %d\n", fd);
    }

    system("ls -lrt");
    system("rm testFileCreat.txt");

    return 0;
}
/*
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./a.out
Created Successfully
file descriptor value is 3
total 236
*/
