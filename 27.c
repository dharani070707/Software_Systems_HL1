/*
 Author : Dharani Prasad S
 Description of problem solved : 
 Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execled. execv
e. execvp
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int choice;
    //All exec* functions belong to the exec family of system calls in Linux/Unix.
    //Their job: replace the current process image with a new program (no return unless error).
    printf("Choose exec variant to run ls -Rl:\n");
    printf("1. execl\n");
    printf("2. execlp\n");
    printf("3. execle\n");
    printf("4. execv\n");
    printf("5. execvp\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\n--- Using execl ---\n");
            execl("/bin/ls", "ls", "-Rl", NULL);
            perror("execl failed");
            break;

        case 2:
            printf("\n--- Using execlp ---\n");
            execlp("ls", "ls", "-Rl", NULL);
            perror("execlp failed");
            break;

        case 3:
            printf("\n--- Using execle ---\n");
            {
                char *envp[] = { NULL };
                execle("/bin/ls", "ls", "-Rl", NULL, envp);
                perror("execle failed");
            }
            break;

        case 4:
            printf("\n--- Using execv ---\n");
            {
                char *args[] = { "ls", "-Rl", NULL };
                execv("/bin/ls", args);
                perror("execv failed");
            }
            break;

        case 5:
            printf("\n--- Using execvp ---\n");
            {
                char *args[] = { "ls", "-Rl", NULL };
                execvp("ls", args);
                perror("execvp failed");
            }
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
/*
Choose exec variant to run ls -Rl:
1. execl
2. execlp
3. execle
4. execv
5. execvp
3

--- Using execle ---
.:
total 244
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s  5218 Sep  2 10:30 1.c
-rwxrwxrwx 1 dharani-prasad-s dharani-prasad-s   522 Aug 13 22:55 1.sh
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s  1572 Sep  2 10:52 10.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s  1458 Sep  2 10:54 11.c
*/
