/*
 Author : Dharani Prasad S
 Description of problem solved : 
 Write a simple program to execute in an infinite loop at the background. Go to /proc directory and identify all the process related information in the corresponding proc directory.
*/

#include<stdio.h>


int main(){
	for(;;);
	return 0;
}

/*
 * dharani-prasad-s@dharani-prasad-s-FX505DY:~/Desktop/SS_Assignments/Hands_on_List1$ ./2.sh
    PID TTY          TIME CMD
  67687 pts/0    00:00:00 bash
  67832 pts/0    00:00:00 bash
  67838 pts/0    00:00:00 a.out
  67839 pts/0    00:00:00 ps
The program is executing in 67838
arch_status  cmdline		 environ  ksm_merging_pages  maps	 ns		patch_state  sessionid	   statm	   timerslack_ns
attr	     comm		 exe	  ksm_stat	     mem	 numa_maps	personality  setgroups	   status	   uid_map
autogroup    coredump_filter	 fd	  latency	     mountinfo	 oom_adj	projid_map   smaps	   syscall	   wchan
auxv	     cpu_resctrl_groups  fdinfo   limits	     mounts	 oom_score	root	     smaps_rollup  task
cgroup	     cpuset		 gid_map  loginuid	     mountstats  oom_score_adj	sched	     stack	   timens_offsets
clear_refs   cwd		 io	  map_files	     net	 pagemap	schedstat    stat	   timers
Killing the program with kill command
    PID TTY          TIME CMD
  67687 pts/0    00:00:00 bash
  67832 pts/0    00:00:00 bash
  67841 pts/0    00:00:00 ps
./2.sh: line 9: 67838 Killed                  ./a.out
*/
