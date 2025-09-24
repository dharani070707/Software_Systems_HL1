/*
 Author : Dharani Prasad S
 Description of problem solved : 
 Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR)
*/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void print_policy(int policy) {
    switch (policy) {
        case SCHED_OTHER: printf("SCHED_OTHER (Normal)\n"); break;
        case SCHED_FIFO:  printf("SCHED_FIFO (Real-time FIFO)\n"); break;
        case SCHED_RR:    printf("SCHED_RR (Real-time Round Robin)\n"); break;
        default:          printf("Unknown\n"); break;
    }
}

int main() {
    pid_t pid = getpid();
    int policy;
    struct sched_param param;

    // Get current scheduling policy
    policy = sched_getscheduler(pid);
    if (policy == -1) {
        perror("sched_getscheduler");
        exit(EXIT_FAILURE);
    }

    printf("Current Scheduling Policy: ");
    print_policy(policy);

    // Ask user for new policy
    int choice;
    printf("\nEnter new scheduling policy:\n");
    printf("1. SCHED_FIFO\n");
    printf("2. SCHED_RR\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    int new_policy;
    if (choice == 1)
        new_policy = SCHED_FIFO;
    else if (choice == 2)
        new_policy = SCHED_RR;
    else {
        printf("Invalid choice! Exiting.\n");
        return 1;
    }

    // Set priority within valid range
    param.sched_priority = (sched_get_priority_min(new_policy) +
                            sched_get_priority_max(new_policy)) / 2;

    if (sched_setscheduler(pid, new_policy, &param) == -1) {
        perror("sched_setscheduler");
        printf("Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("\nScheduling policy successfully changed!\n");

    // Confirm new policy
    policy = sched_getscheduler(pid);
    printf("New Scheduling Policy: ");
    print_policy(policy);

    return 0;
}
/*
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ sudo ./a.out 
[sudo] password for dharani-prasad-s: 
Current Scheduling Policy: SCHED_OTHER (Normal)

Enter new scheduling policy:
1. SCHED_FIFO
2. SCHED_RR
Your choice: 1

Scheduling policy successfully changed!
New Scheduling Policy: SCHED_FIFO (Real-time FIFO)
*/
