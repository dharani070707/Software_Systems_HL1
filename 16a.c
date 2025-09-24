/*
 Author : Dharani Prasad S
 Description of problem solved : 
 Write a program to perform mandatory locking.
a. Implement write lock
*/


#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<stdio.h>



int main(void){
	struct flock lock;
	int fd;
	fd = open("file2.txt",O_RDWR);
	printf("%d",fd);
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start =0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	printf("Before entering the critical section \n");
	fcntl(fd,F_SETLKW,&lock);
	printf("Inside the critical section \n");
	getchar();
	fcntl(fd,F_UNLCK,&lock);
	printf("Unlocked the critical section \n");
	return 0;
}

/*
Terminal 1 
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./a.out
3Before entering the critical section
Inside the critical section


Terminal 2
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./a.out
3Before entering the critical section


*/
