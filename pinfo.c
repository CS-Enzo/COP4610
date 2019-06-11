/*
 COP4610 – Principles of Operating Systems – Summer C 2019
 Prof. Jose F. Osorio
 Student Name: Enzo Mendoza 2923725
 Project: Customizing Linux Kernel
 Specs:   Adding Static System Call
 Due Date: 06/10/2019 by 11:55pm
 Module Name: pinfo.c
 I Certify that this program code has been written by me
 and no part of it has been taken from any sources.
*/
              
 
#include <linux/syscalls.h>

#include <linux/pinfo.h>

#include <linux/linkage.h>

#include <asm/current.h>

#include <linux/list.h>

#include <linux/time.h>

#include <linux/string.h>

#include <linux/kernel.h>

#include <linux/sched.h>

…

asmlinkage long sys_pinfo(struct pinfo *info)

{

   // Local Declarations

    //if info is null 	
    if(info == NULL)
        return -22;

 

	// Main Logic, assigning 
	struct task_struct *t = current;
	info->pid = task_pid_nr(current);
	info->state = t->state;
	info->nice = task_nice(current);
	info->parent_pid = t->parent;
	info->nr_children = t->signal->thread_head;
	info->nr_threads = t->signal->nr_threads;
	info->uid = (long) t->cred-.uid.val;
	info->user_time = t->signal->utime;
	info->sys_time = t->signal->stime;
	info->cutime = t->signal->cutime;
     

 

    return 0;

}
