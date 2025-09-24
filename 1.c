
//####################################################################################
//# Author : Dharani Prasad S
//# Description of problem solved : 
//# Create the following types of a files using (i) shell command (ii) system call
//#a. soft link (symlink system call)
//#b. hard link (link system call)
//#c. FIFO (mkfifo Library Function or mknod system call)
//#######################################################################################

//we are adding files using system calls first


#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>


int main(){
	// here we will create a softlink file
	int res = symlink("/tempDir/file1.txt","slink.txt");
	if(res == 0){
		printf("Symlink successfully created \n");
	}else{
		perror("Symlink error :");
	}

	// now hardlink file using link 
	res = link("file2.txt","hlink.txt");
	if(res == 0){
		printf("Link successfully created \n");
	}else{
		perror("link");
	}
	//now fifo file 
	res = mkfifo("myfifo.txt",0744);
        if(res == 0){
                printf("Fifo File successfully created \n");
        }else{
                perror("MyFifo");
        }	
	  printf("\nDirectory listing (ls -l):\n");
	  system("ls -l");
	  printf("Removing files to do the same in shellscript\n");
	  system("rm slink.txt hlink.txt myfifo.txt");


	return 0;

}

/*Symlink successfully created 
Link successfully created 
Fifo File successfully created 

Directory listing (ls -l):
total 236
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s   861 Aug 19 15:02 10.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s   982 Aug 17 22:52 11.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s   948 Aug 18 22:40 12.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s   952 Aug 19 14:22 13.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s  1301 Aug 19 14:40 14.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s   249 Aug 18 22:43 15.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s   503 Aug 14 15:08 16a.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s   618 Aug 14 15:09 16b.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s  1273 Aug 24 21:10 17.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s   345 Aug 24 21:08 17helper.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s  1976 Aug 24 21:20 18.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s   605 Aug 24 21:18 18helper.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s  1594 Aug 28 14:32 19.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s  1369 Sep  1 18:36 1.c
-rwxrwxrwx 1 dharani-prasad-s dharani-prasad-s   522 Aug 13 22:55 1.sh
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s   966 Aug 28 14:37 20.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s   511 Aug 28 14:37 21.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s   872 Aug 28 14:38 22.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s   477 Aug 28 14:39 23.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s   579 Aug 24 21:30 24.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s   261 Aug 28 15:14 25.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s   331 Sep  1 18:27 26.c
-rwxrwxr-x 1 dharani-prasad-s dharani-prasad-s 15968 Sep  1 18:25 26helper
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s   157 Sep  1 18:24 26helper.c
-rwxrwxr-x 1 dharani-prasad-s dharani-prasad-s 15968 Sep  1 18:26 26helper.out
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s  1639 Sep  1 18:31 27.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s  1293 Sep  1 18:33 28.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s    54 Aug 13 23:33 2.c
-rwxrwxrwx 1 dharani-prasad-s dharani-prasad-s   143 Aug 13 23:33 2.sh
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s   390 Aug 21 15:15 3.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s   502 Aug 13 23:36 4.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s   539 Aug 14 00:23 5.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s   145 Aug 14 00:11 6.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s  1035 Aug 14 00:37 7.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s   547 Aug 19 14:58 8.c
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s  1711 Aug 19 15:00 9.c
-rwxrwxr-x 1 dharani-prasad-s dharani-prasad-s 16152 Sep  2 10:24 a.out
-rwxr--r-- 1 dharani-prasad-s dharani-prasad-s    24 Aug 19 14:44 db.txt
-rwxrwxrwx 2 dharani-prasad-s dharani-prasad-s    57 Aug 13 23:59 file2.txt
-rwxrwxrwx 2 dharani-prasad-s dharani-prasad-s    57 Aug 13 23:59 hlink.txt
-rw-r--r-- 1 dharani-prasad-s dharani-prasad-s    30 Aug 19 15:01 lseek.txt
prwxr--r-- 1 dharani-prasad-s dharani-prasad-s     0 Sep  2 10:24 myfifo.txt
-rw-r--r-- 1 dharani-prasad-s dharani-prasad-s    51 Aug 28 14:38 output.txt
lrwxrwxrwx 1 dharani-prasad-s dharani-prasad-s    18 Sep  2 10:24 slink.txt -> /tempDir/file1.txt
drwxrwxr-x 2 dharani-prasad-s dharani-prasad-s  4096 Aug 13 22:28 tempDir
-rwxr-xr-x 1 dharani-prasad-s dharani-prasad-s     0 Aug 21 15:15 testFileCreat.txt
-rwxrwxr-x 1 dharani-prasad-s dharani-prasad-s 16232 Aug 14 15:10 testWrite
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s     9 Aug 24 21:10 ticket.txt
-rw-rw-r-- 1 dharani-prasad-s dharani-prasad-s   150 Aug 24 21:20 trains.txt
-rw-r--r-- 1 dharani-prasad-s dharani-prasad-s   139 Aug 14 00:37 writeFile.txt
Removing files to do the same in shellscript
*/



