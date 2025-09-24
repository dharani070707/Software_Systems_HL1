/*
 Author : Dharani Prasad S
 Description of problem solved : 
 Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define RECSIZE 50
#define TRAINS 3

void showTrains(int fd) {
    char buf[RECSIZE + 1];
    printf("\nAvailable Trains:\n");
    lseek(fd, 0, SEEK_SET);
    for (int i = 0; i < TRAINS; i++) {
        read(fd, buf, RECSIZE);
        buf[RECSIZE] = '\0';
        printf("%d. %s", i + 1, buf);
    }
    printf("\n");
}

int main() {
    int fd = open("trains.txt", O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Step 1: Display all trains
    showTrains(fd);

    // Step 2: Ask for input
    int train_no;
    printf("Enter train number to book (1-%d): ", TRAINS);
    scanf("%d", &train_no);

    if (train_no < 1 || train_no > TRAINS) {
        printf("Invalid train number!\n");
        close(fd);
        return 1;
    }

    // Step 3: Lock that record
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (train_no - 1) * RECSIZE;
    lock.l_len = RECSIZE;

    printf("Waiting for lock on Train %d...\n", train_no);
    fcntl(fd, F_SETLKW, &lock);
    printf("Lock acquired \n");

    // Step 4: Read record
    char buf[RECSIZE + 1];
    lseek(fd, lock.l_start, SEEK_SET);
    read(fd, buf, RECSIZE);
    buf[RECSIZE] = '\0';

    char train[20];
    int tickets;
    sscanf(buf, "%s %d", train, &tickets);

    printf("%s has %d tickets available.\n", train, tickets);

    if (tickets > 0) {
        tickets--;
        printf("Ticket booked successfully! Remaining: %d\n", tickets);

        char newrec[RECSIZE];
        snprintf(newrec, sizeof(newrec), "%s %d\n", train, tickets);

        // Write back
        lseek(fd, lock.l_start, SEEK_SET);
        write(fd, newrec, strlen(newrec));
    } else {
        printf("No tickets left for %s!\n", train);
    }
    getchar();
    getchar();
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    close(fd);

    return 0;
}
/*
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./a.out 

Available Trains:
1. TrainA 50
2. TrainB 30
3. TrainC 10

Enter train number to book (1-3): 1
Waiting for lock on Train 1...
Lock acquired 
TrainA has 50 tickets available.
Ticket booked successfully! Remaining: 49

*/
