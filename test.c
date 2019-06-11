/*
 COP4610 – Principles of Operating Systems – Summer C 2019
 Prof. Jose F. Osorio
 Student Name: Enzo Mendoza 2923725
 Project: Customizing Linux Kernel
 Specs:   Adding Static System Call
 Due Date: 06/10/2019 by 11:55pm
 Module Name: test.c
 I Certify that this program code has been written by me
 and no part of it has been taken from any sources.
*/

#include <unistd.h>

#include <stdio.h>

#include “pinfo.h”

 

int main()

{

  struct pinfo p_info;

  int status;

  … /* create child processes and keep ‘em active */
	while(1){
	fork()
}
  … /* create child threads and keep’em active */

 

  /* If this is the parent process, call new system call… */

  status = syscall (327, &p_info);    //NOTE: use proper system call number designated in the system call table file (/usr/src/linux/arch/x86/syscalls/syscall_64.tbl)        

 

 /* … and output to standard output the info returned by new system call */

    printf("p_info:\n");

    printf(

        "pid = %d\n"

        "state = %ld\n"

        "nice = %ld\n"

        "parent_pid = %d\n"

        "children = %d\n"

        "youngest_child_pid = %d\n"

        "younger_sibling_pid = %d\n"

        "older_sibling_pid = %d\n"

        "start_time = %lu\n"

        "user_time = %ld\n"

        "sys_time = %ld\n"

        "uid = %ld\n"

        "comm = %s\n",

        p_info.pid, p_info.state, p_info.nice, p_info.parent_pid, p_info.children,

        p_info.youngest_child_pid, p_info.younger_sibling_pid, p_info.older_sibling_pid,

        p_info.start_time, p_info.user_time, p_info.sys_time, p_info.uid, p_info.comm);

exit(0);

}
