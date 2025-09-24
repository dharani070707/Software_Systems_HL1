/*
 Author : Dharani Prasad S
 Description of problem solved : 
 Write a program to find out time taken to execute getpid system call. Use time stamp counter.
*/
#include <stdio.h>    
#include <stdint.h> 
#include <stdlib.h>   
#include <unistd.h>   
#include <fcntl.h>    
#include <inttypes.h>
#include <string.h>  
#include<x86intrin.h>

int main() {
    int fd;
    char buffer[1024];
    ssize_t bytes_read;
    double cpu_mhz = 0.0;
    char *start_ptr;

    fd = open("/proc/cpuinfo", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1) {
        perror("read");
        close(fd);
        exit(1);
    }
    
    buffer[bytes_read] = '\0';

    start_ptr = strstr(buffer, "cpu MHz");

    if (start_ptr != NULL) {
        start_ptr = strchr(start_ptr, ':');
        if (start_ptr != NULL) {
            start_ptr++; // Move past the colon
            sscanf(start_ptr, "%lf", &cpu_mhz);
        }
    }

    close(fd);

    if (cpu_mhz > 0.0) {
        printf("CPU Clock Speed: %.2f MHz\n", cpu_mhz);
    } else {
        printf("CPU clock speed not found.\n");
    }
    uint64_t start_cycles, end_cycles;

    start_cycles = __rdtsc();

    pid_t pid = getpid();

    end_cycles = __rdtsc();

    uint64_t total_cycles = end_cycles - start_cycles;



    printf("PID: %d\n", pid);
    printf("getpid() execution took %" PRIu64 " clock cycles.\n", total_cycles);
    double time_ns = 0.0;
    if (cpu_mhz > 0.0) {
        time_ns = (double)total_cycles * 1000.0 / cpu_mhz;
        printf("Time taken: %.2f nanoseconds\n", time_ns);
    } else {
        printf("Cannot calculate time: CPU frequency not found.\n");
    }


    return 0;
}
/*
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./a.out
CPU Clock Speed: 1364.82 MHz
PID: 3641
getpid() execution took 17073 clock cycles.
Time taken: 12509.35 nanoseconds
*/
