/*
Author : Dharani Prasad S
Description of problem solved :
Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main(){
	int fds[5];
	char fname[30];
	char cmd[30];
        for(int i =0;i<5;i++){
		sprintf(fname, "fileName%d.txt", i);
	        fds[i] = creat(fname,O_CREAT|O_RDWR);
		if(fds[i] == -1){
			perror("Creat");
		}else{
			printf("File %s created successfully",fname);
			sprintf(cmd, "ls -l /proc/%d/fd", getpid());
			system(cmd);
		}	

		getchar();
	}
		system("yes | rm fileName0.txt fileName1.txt fileName2.txt fileName3.txt fileName4.txt");

	return 0;
}
/*
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./a.out 
total 0
lrwx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 0 -> /dev/pts/1
lrwx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 1 -> /dev/pts/1
lrwx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 2 -> /dev/pts/1
l-wx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 3 -> /home/dharani-prasad-s/Desktop/SS_Assignments/Hands_on_List1/fileName0.txt
File fileName0.txt created successfully
total 0
lrwx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 0 -> /dev/pts/1
lrwx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 1 -> /dev/pts/1
lrwx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 2 -> /dev/pts/1
l-wx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 3 -> /home/dharani-prasad-s/Desktop/SS_Assignments/Hands_on_List1/fileName0.txt
l-wx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 4 -> /home/dharani-prasad-s/Desktop/SS_Assignments/Hands_on_List1/fileName1.txt
File fileName1.txt created successfully
total 0
lrwx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 0 -> /dev/pts/1
lrwx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 1 -> /dev/pts/1
lrwx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 2 -> /dev/pts/1
l-wx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 3 -> /home/dharani-prasad-s/Desktop/SS_Assignments/Hands_on_List1/fileName0.txt
l-wx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 4 -> /home/dharani-prasad-s/Desktop/SS_Assignments/Hands_on_List1/fileName1.txt
l-wx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 5 -> /home/dharani-prasad-s/Desktop/SS_Assignments/Hands_on_List1/fileName2.txt
File fileName2.txt created successfully
total 0
lrwx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 0 -> /dev/pts/1
lrwx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 1 -> /dev/pts/1
lrwx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 2 -> /dev/pts/1
l-wx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 3 -> /home/dharani-prasad-s/Desktop/SS_Assignments/Hands_on_List1/fileName0.txt
l-wx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 4 -> /home/dharani-prasad-s/Desktop/SS_Assignments/Hands_on_List1/fileName1.txt
l-wx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 5 -> /home/dharani-prasad-s/Desktop/SS_Assignments/Hands_on_List1/fileName2.txt
l-wx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 6 -> /home/dharani-prasad-s/Desktop/SS_Assignments/Hands_on_List1/fileName3.txt
File fileName3.txt created successfully
total 0
lrwx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 0 -> /dev/pts/1
lrwx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 1 -> /dev/pts/1
lrwx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 2 -> /dev/pts/1
l-wx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 3 -> /home/dharani-prasad-s/Desktop/SS_Assignments/Hands_on_List1/fileName0.txt
l-wx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 4 -> /home/dharani-prasad-s/Desktop/SS_Assignments/Hands_on_List1/fileName1.txt
l-wx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 5 -> /home/dharani-prasad-s/Desktop/SS_Assignments/Hands_on_List1/fileName2.txt
l-wx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 6 -> /home/dharani-prasad-s/Desktop/SS_Assignments/Hands_on_List1/fileName3.txt
l-wx------ 1 dharani-prasad-s dharani-prasad-s 64 Sep  2 10:41 7 -> /home/dharani-prasad-s/Desktop/SS_Assignments/Hands_on_List1/fileName4.txt
File fileName4.txt created successfully
*/
