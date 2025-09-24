#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define RECSIZE 50

int main() {
    int fd = open("trains.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    char rec1[RECSIZE], rec2[RECSIZE], rec3[RECSIZE];
    snprintf(rec1, sizeof(rec1), "TrainA %d\n", 50);
    snprintf(rec2, sizeof(rec2), "TrainB %d\n", 30);
    snprintf(rec3, sizeof(rec3), "TrainC %d\n", 10);

    write(fd, rec1, RECSIZE);
    write(fd, rec2, RECSIZE);
    write(fd, rec3, RECSIZE);

    close(fd);
    return 0;
}

