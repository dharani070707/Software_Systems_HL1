/*
Author : Dharani Prasad S
Description of problem solved :
Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
*/

#include<stdio.h>
#include<unistd.h>

int main(){
	char buffer[100];
	int n = read(0, buffer, sizeof(buffer));
	write(1,buffer,n);

	return 0;
}

/*
harani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./a.out 
this is the input i am giving to my buffer i will try to give more than 100 characters so that buffer will only take 100 and read and write only 100 characters lets see this
this is the input i am giving to my buffer i will try to give more than 100 characters so that buffe
*/
