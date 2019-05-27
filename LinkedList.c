/*
 COP4610 – Principles of Operating Systems – Summer C 2019
 Prof. Jose F. Osorio
 Student: Enzo Mendoza 2923725

 Assignment #: 1
 Specs: Creating Linux Kernel Modules
 Due Date: 05/26/2019 by 11:55pm

 Module Name: LinkedList

 I Certify that this program code has been written by me
 and no part of it has been taken from any sources.
*/

#include <linux/list.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/types.h>

#define 

/* This function is called when the module is loaded. */
int simple_init(void)
{
       printk(KERN_INFO "Loading Module\n");

        //struct made
        struct birthday{
            int day;
            int month;
            int year;
            struct list_head list;
        };

        static LIST_HEAD(birthday_list);
        
        //struct initialization
        struct birthday *person1;
        person1 = kmalloc(sizeof(*person1), GFP_KERNEL);
        person1 -> day = 2;
        person1 -> month = 8;
        person1 -> year = 1998;
        INIT_LIST_HEAD(&person1 -> list);

        list_add_tail(&person1 -> list, &birthday_list);

        struct birthday *person2;
        person2 = kmalloc(sizeof(*person2), GFP_KERNEL);
        person2 -> day = 10;
        person2 -> month = 2;
        person2 -> year = 1975;
        INIT_LIST_HEAD(&person2 -> list);

        list_add_tail(&person2 -> list, &birthday_list);

        struct birthday *person3;
        person3 = kmalloc(sizeof(*person3), GFP_KERNEL);
        person3 -> day = 24;
        person3 -> month = 1;
        person3 -> year = 1991;
        INIT_LIST_HEAD(&person3 -> list);

        list_add_tail(&person3 -> list, &birthday_list);

        struct birthday *person4;
        person4 = kmalloc(sizeof(*person4), GFP_KERNEL);
        person4 -> day = 13;
        person4 -> month = 5;
        person4 -> year = 1967;
        INIT_LIST_HEAD(&person4 -> list);

        list_add_tail(&person4 -> list, &birthday_list);

        struct birthday *person5;
        person5 = kmalloc(sizeof(*person5), GFP_KERNEL);
        person5 -> day = 17;
        person5 -> month = 7;
        person5 -> year = 1985;
        INIT_LIST_HEAD(&person5 -> list);

        list_add_tail(&person5 -> list, &birthday_list);
        
        struct birtday *ptr;

        //traverses the birthday list and prints the contents to dmesg
        for(pos = list_first_entry(head, typeof(*pos), member); &pos -> member != (head); 
            pos = list_next_entry(pos, member))
        {
            printk(KERN_INFO "Day: %d Month: %d Year: %d", ptr -> day, ptr -> month, ptr -> year);
        }
    
       return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	printk(KERN_INFO "Removing Module\n");

    struct birthday *ptr, *next;

        //traverses list and deletes and frees space
        for(pos = list_first_entry(head, typeof(*pos), member); &pos -> member != (head); 
            pos = list_next_entry(pos, member))
        {
            list_del(&ptr - > list);
            kfree(ptr);
        }
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("LinkedList");
MODULE_AUTHOR("Enzo Mendoza");