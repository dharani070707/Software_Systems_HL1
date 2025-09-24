/*
Author : Dharani Prasad S
Description of problem solved :
Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define BUF_SIZE 1

int main(){
	int fd;
    	char ch;
    	int bytesRead;

    	fd = open("writeFile.txt", O_RDONLY);
    	if (fd == -1) {
        	perror("Error opening file");
    	}

    	printf("Reading file line by line:\n");

    	while ((bytesRead = read(fd, &ch, BUF_SIZE)) > 0) {
        	write(1, &ch, 1); 
    	}	

    	if (bytesRead == -1) {
        	perror("Error reading file");
    	}

    	close(fd);
    	printf("\nEnd of file reached. File closed.\n");

    	return 0;
}
/*
Reading file line by line:
i am creating this file for program 7.c to read from and then copy this file to some other file 

it 
creates 
i am adding extra spaces for testing

End of file reached. File closed.
*/
