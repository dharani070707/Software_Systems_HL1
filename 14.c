/*
 Author : Dharani Prasad S
 Description of problem solved : 
 Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[256];
    char cmd[300];
    FILE *fp;
    char buffer[1024];

    printf("Enter a filename: ");
    if (scanf("%255s", filename) != 1) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    snprintf(cmd, sizeof(cmd), "ls -ld %s", filename);

    fp = popen(cmd, "r");
    if (fp == NULL) {
        perror("popen failed");
        return 1;
    }

    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        char type = buffer[0];  // first character indicates type

        switch (type) {
            case '-': printf("%s is a regular file\n", filename); break;
            case 'd': printf("%s is a directory\n", filename); break;
            case 'l': printf("%s is a symbolic link\n", filename); break;
            case 'p': printf("%s is a FIFO (pipe)\n", filename); break;
            case 's': printf("%s is a socket\n", filename); break;
            case 'c': printf("%s is a character device\n", filename); break;
            case 'b': printf("%s is a block device\n", filename); break;
            default:  printf("%s type is unknown\n", filename);
        }
    }

    int status = pclose(fp);
    if (status != 0) {
        printf("File does not exist: %s\n", filename);
    }

    return 0;
}
/*
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./a.out 
Enter a filename: tempDir
tempDir is a directory
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./a.out 
Enter a filename: writeFile.txt
writeFile.txt is a regular file
*/
