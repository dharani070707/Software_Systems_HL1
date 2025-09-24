 /*
 * Author : Dharani Prasad S
 * Description of problem solved : 
 * Write a program to open an existing file with read write mode. Try O_EXCL flag also.
 */

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){

	int fd = open("file2.txt", O_RDWR);
	if(fd == -1){
		perror("Open lib : ");
	}else{
		 printf("File file2.txt opened in read-write mode successfully (fd=%d)\n", fd);
		 close(fd);
	}

    fd = open("file2.txt", O_RDWR | O_CREAT | O_EXCL, 0644);
    if (fd == -1) {
        perror("open (O_CREAT | O_EXCL)");
    } else {
        printf("File created successfully with O_EXCL (fd=%d)\n", fd);
        close(fd);
    }
	return 0;
}
/*
 * dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./a.out
File file2.txt opened in read-write mode successfully (fd=3)
open (O_CREAT | O_EXCL): File exists
*/


