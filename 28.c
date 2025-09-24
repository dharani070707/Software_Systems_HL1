/*
 Author : Dharani Prasad S
 Description of problem solved : 
 Write a program to get maximum and minimum real time priority.
*/
#include <stdio.h>
#include <sched.h>
#include <errno.h>
//use chrt -m

int main() {
    int min_priority, max_priority;

    // For SCHED_FIFO
    min_priority = sched_get_priority_min(SCHED_FIFO);
    if (min_priority == -1) {
        perror("sched_get_priority_min (FIFO)");
    }
    max_priority = sched_get_priority_max(SCHED_FIFO);
    if (max_priority == -1) {
        perror("sched_get_priority_max (FIFO)");
    }
    printf("SCHED_FIFO: Min = %d, Max = %d\n", min_priority, max_priority);

    // For SCHED_RR
    min_priority = sched_get_priority_min(SCHED_RR);
    if (min_priority == -1) {
        perror("sched_get_priority_min (RR)");
    }
    max_priority = sched_get_priority_max(SCHED_RR);
    if (max_priority == -1) {
        perror("sched_get_priority_max (RR)");
    }
    printf("SCHED_RR: Min = %d, Max = %d\n", min_priority, max_priority);

    // For SCHED_OTHER (normal, not realtime)
    min_priority = sched_get_priority_min(SCHED_OTHER);
    if (min_priority == -1) {
        perror("sched_get_priority_min (OTHER)");
    }
    max_priority = sched_get_priority_max(SCHED_OTHER);
    if (max_priority == -1) {
        perror("sched_get_priority_max (OTHER)");
    }
    printf("SCHED_OTHER: Min = %d, Max = %d\n", min_priority, max_priority);

    return 0;
}
/*
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./a.out 
SCHED_FIFO: Min = 1, Max = 99
SCHED_RR: Min = 1, Max = 99
SCHED_OTHER: Min = 0, Max = 0
*/
