/*
Author : Dharani Prasad S
Description of problem solved :
Write a program to copy file1 into file2 ($cp file1 file2).
*/
#include <stdio.h>
#include <unistd.h>    
#include <fcntl.h>     
#include <stdlib.h>    

#define BUFFER_SIZE 1024

int main(){
	int fd1,fd2;
	char buf[BUFFER_SIZE];
	int bytesRead, bytesWritten;
	fd1 = open("readFile.txt", O_RDONLY);
	    if (fd1 < 0) {
		perror("Error opening readFile.txt");
		return 1;
	    }else{
		    printf("opening readFile.txt successful\n");
	    }
	fd2 = open("writeFile.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    	if (fd2 < 0) {
        	perror("Error opening/creating writeFile.txt\n");
        	close(fd1);
		return 1;
    		}
	else {
		printf("opening writeFile.txt successful");
	}
	while ((bytesRead = read(fd1, buf, BUFFER_SIZE)) > 0) {
		bytesWritten = write(fd2, buf, bytesRead);
		if(bytesRead != bytesWritten){
			perror("Error writing to destination file\n");
            		close(fd1);
            		close(fd2);
			return 1;
		}
	}
    close(fd1);
    close(fd2);
    printf("File copied successfully.\n");
    system("cat writeFile.txt");
    return 0;
}
/*
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./a.out 
opening readFile.txt successful
opening writeFile.txt successfulFile copied successfully.
i am creating this file for program 7.c to read from and then copy this file to some other file 

it 
creates 
i am adding extra spaces for testing

*/
