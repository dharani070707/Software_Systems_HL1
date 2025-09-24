/*
 Author : Dharani Prasad S
 Description of problem solved : 
 Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    char *program = "./26helper.out"; 

    char *args[] = {"./26helper.out", "Hello", "123", NULL};

    printf("Executing %s...\n", program);

    if (execvp(program, args) == -1) {
        perror("execvp failed");
        exit(1);
    }

    return 0;
}
/*
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./a.out 
Executing ./26helper.out...
Arg 0: ./26helper.out
Arg 1: Hello
Arg 2: 123
*/
