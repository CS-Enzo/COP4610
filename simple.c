/*
 COP4610 – Principles of Operating Systems – Summer C 2019
 Prof. Jose F. Osorio
 Student: fname lastname – panther id

 Assignment #: 1
 Specs: Creating Linux Kernel Modules
 Due Date: 05/26/2019 by 11:55pm

 Module Name:

 I Certify that this program code has been written by me
 and no part of it has been taken from any sources.

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
*/

/* This function is called when the module is loaded. */
int simple_init(void)
{
       printk(KERN_INFO "Loading Module\n");

       return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	printk(KERN_INFO "Removing Module\n");
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("simple");
MODULE_AUTHOR("Enzo Mendoza");

