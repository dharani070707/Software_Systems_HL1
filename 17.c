/*
 Author : Dharani Prasad S
 Description of problem solved : 
  Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd = open("ticket.txt", O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    struct flock lock;
    lock.l_type = F_WRLCK;   // Write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("Waiting for lock...\n");
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl lock");
        close(fd);
        return 1;
    }
    printf("Lock acquired \n");

    // Read file
    char buf[100];
    int n = read(fd, buf, sizeof(buf) - 1);
    buf[n] = '\0';

    char *numPart = strchr(buf, '=');
    if (!numPart) {
        printf("Invalid format in file!\n");
        close(fd);
        return 1;
    }
    numPart++;
    int ticket = atoi(numPart);
    printf("Old Ticket = %d\n", ticket);

    ticket++;

    // Move to beginning to overwrite
    lseek(fd, 0, SEEK_SET);

    // Format new content without snprintf
    char newbuf[100];
    sprintf(newbuf, "Ticket=%d\n", ticket);
    write(fd, newbuf, strlen(newbuf));

    printf("New Ticket = %d\n", ticket);
    getchar();
    // Unlock
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);
    return 0;
}
/*
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./a.out
Waiting for lock...
Lock acquired
Old Ticket = 1
New Ticket = 2
*/


