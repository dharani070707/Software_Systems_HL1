/*
Author : Dharani Prasad S
Description of problem solved :
Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    fd_set readfds;
    struct timeval timeout;
    int ret;

    // Initialize the FD set
    FD_ZERO(&readfds);
    FD_SET(0, &readfds);  // monitor stdin (fd=0)

    // Set timeout 10 seconds
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for input (10 seconds)...\n");
    // fd+1 , readfds, writefds, expectfds, timeout
    ret = select(0 + 1, &readfds, NULL, NULL, &timeout);

    if (ret == -1) {
        perror("select");
        exit(EXIT_FAILURE);
    } else if (ret == 0) {
        printf("Timeout! No input within 10 seconds.\n");
    } else {
        if (FD_ISSET(0, &readfds)) {
            char buf[1024];
            int n = read(STDIN_FILENO, buf, sizeof(buf)-1);
            if (n > 0) {
                buf[n] = '\0';
                printf("You typed: %s", buf);
            }
        }
    }

    return 0;
}
/*
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./a.out 
Waiting for input (10 seconds)...
qwjhdqwuyfewg
You typed: qwjhdqwuyfewg
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./a.out 
Waiting for input (10 seconds)...
Timeout! No input within 10 seconds.
*/
