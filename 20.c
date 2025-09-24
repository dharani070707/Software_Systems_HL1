/*
 Author : Dharani Prasad S
 Description of problem solved : 
 Find out the priority of your running program. Modify the priority with nice command.
*/
#include <stdio.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int main() {
    pid_t pid = getpid();
    
    // Get and print the initial priority
    errno = 0; 
    int initial_priority = getpriority(PRIO_PROCESS, pid);
    if (initial_priority == -1 && errno != 0) {
        perror("Failed to get initial priority");
        return 1;
    }
    printf("Initial priority (nice value) of this process (PID: %d) is: %d\n", pid, initial_priority);

    // Increment the nice value by 5, making the process less important
    int increment = 5;
    errno = 0;
    int new_priority = nice(increment);

    // Check for errors
    if (new_priority == -1 && errno != 0) {
        perror("Failed to change priority with nice()");
        return 1;
    }
    
    printf("Changed priority by incrementing with %d\n", increment);
    printf("New priority (nice value) of this process is: %d\n", new_priority);

    return 0;
}
/*
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./a.out 
Initial priority (nice value) of this process (PID: 3721) is: 0
Changed priority by incrementing with 5
New priority (nice value) of this process is: 5
*/
