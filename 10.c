/*
Author : Dharani Prasad S
Description of problem solved :
Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    int fd = open("lseek.txt", O_CREAT | O_RDWR | O_TRUNC, 744);
    if (fd == -1) {
        perror("File open failed");
        exit(1);
    }

    char buffer[100];

    printf("Enter at least 20 characters: \n");
    int n = read(0, buffer, sizeof(buffer));
    if (n < 20) {
        printf("Please enter at least 20 characters!\n");
        close(fd);
        return 1;
    }

    write(fd, buffer, 10);

    off_t pos = lseek(fd, 10, SEEK_CUR);
    if (pos == -1) {
        perror("lseek failed");
        close(fd);
        return 1;
    }
    printf("File pointer moved, current offset = %ld\n", pos);

    write(fd, buffer + 10, 10);

    close(fd);

    printf("Now checking the file with: od -c lseek.txt\n");
    system("od -c lseek.txt");

    return 0;
}
/*
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./a.out 
Enter at least 20 characters: 
gydwouegspiueqieogpiugrpwiurewho[i  qwdg
File pointer moved, current offset = 20
Now checking the file with: od -c lseek.txt
0000000   g   y   d   w   o   u   e   g   s   p  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   i   u   e   q   i   e   o   g   p   i
0000036
*/
