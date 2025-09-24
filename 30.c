/*
 Author : Dharani Prasad S
 Description of problem solved : 
 Write a program to run a script at a specific time using a Daemon process.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

void create_daemon() {
    pid_t pid;

    pid = fork();
    if (pid < 0) exit(EXIT_FAILURE);
    if (pid > 0) exit(EXIT_SUCCESS);

    if (setsid() < 0) exit(EXIT_FAILURE);

    pid = fork();
    if (pid < 0) exit(EXIT_FAILURE);
    if (pid > 0) exit(EXIT_SUCCESS);

    umask(0);

    // 👇 Keep current directory (don’t chdir("/"))
    for (int x = sysconf(_SC_OPEN_MAX); x >= 0; x--) {
        close(x);
    }
}

int main() {
    int target_hour = 12;  // 12 PM
    int target_min  = 27;  // Change for testing

    const char *script_path = "./myscript.out";
    const char *log_path = "./daemon_log.log";

    create_daemon();

    // Log daemon start
    FILE *log = fopen(log_path, "a");
    if (log) {
        fprintf(log, "Daemon started at %s\n", ctime(&(time_t){time(NULL)}));
        fflush(log);
        fclose(log);
    }

    while (1) {
        time_t now = time(NULL);
        struct tm *local = localtime(&now);

        if (local->tm_hour == target_hour && local->tm_min == target_min) {
            // Run script
            char command[512];
            snprintf(command, sizeof(command),
                     "%s >> ./myscript_output.log 2>&1", script_path);
            system(command);

            // Write to log
            FILE *log2 = fopen(log_path, "a");
            if (log2) {
                fprintf(log2, "[%02d:%02d:%02d] Script executed: %s\n",
                        local->tm_hour, local->tm_min, local->tm_sec, script_path);
                fflush(log2);
                fclose(log2);
            }

            sleep(60); // avoid multiple runs in same minute
        }
        sleep(1);
    }

    return 0;
}

/*
dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ cat daemon_log.log
Daemon started at Tue Sep  2 12:26:00 2025

[12:27:00] Script executed: ./myscript.out

*/
