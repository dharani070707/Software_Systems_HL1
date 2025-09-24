/*
Author : Dharani Prasad S
Description of problem solved :
Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
*/

#include<stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>

int main(){
	struct stat sb;
	int fd = open("db.txt",O_RDONLY);
	if(fd == -1){
		perror("Cant open the file: \n");
	}else{
		printf("Opening file was successfully \n");
	}

	if (fstat(fd, &sb) == -1) {
		perror("fstat");
		return 1;
	    }

	    printf("File inode: %ld\n", sb.st_ino);
	    printf("Number of links: %ld\n", sb.st_nlink);
	    printf("Number of hard links: %ld\n", (long) sb.st_nlink);
	    printf("User ID of owner (UID): %d\n", sb.st_uid);
	    printf("Group ID of owner (GID): %d\n", sb.st_gid);
	    printf("File size: %ld bytes\n", (long) sb.st_size);
	    printf("Block size: %ld\n", (long) sb.st_blksize);
	    printf("Number of blocks allocated: %ld\n", (long) sb.st_blocks); 
	    printf("File type:                ");

           switch (sb.st_mode & S_IFMT) {
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
           }
 
	   printf("Last status change:       %s", ctime(&sb.st_ctime));
           printf("Last file access:         %s", ctime(&sb.st_atime));
           printf("Last file modification:   %s", ctime(&sb.st_mtime));

	    close(fd);
	    return 0;
		



}
/*
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./a.out 
Opening file was successfully 
File inode: 1968546
Number of links: 1
Number of hard links: 1
User ID of owner (UID): 1000
Group ID of owner (GID): 1000
File size: 24 bytes
Block size: 4096
Number of blocks allocated: 8
File type:                regular file
Last status change:       Tue Aug 19 14:44:03 2025
Last file access:         Thu Aug 21 23:08:58 2025
Last file modification:   Tue Aug 19 14:44:03 2025
*/

