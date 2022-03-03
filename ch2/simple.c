#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/slab.h>

struct birthday {
       int day;
       int month;
       int year;
       struct list_head list;
       char name[]; 
};

static LIST_HEAD(birthday_list);


void add_person_entry(int day, int month, int year){
       struct birthday *person;
       person = kmalloc(sizeof(struct birthday), GFP_KERNEL);
       INIT_LIST_HEAD(&person->list);

       person->day = day;
       person->month = month;
       person->year = year;
       list_add_tail(&person->list, &birthday_list);
}

void init_birthday_list(void) {
       add_person_entry(10, 11, 2011);
       add_person_entry(11, 11, 2013);
       add_person_entry(10, 11, 2014);
       add_person_entry(11, 11, 2015);
       add_person_entry(10, 11, 2016);
       printk(KERN_INFO "start order: \n");
       struct birthday *ptr;
       list_for_each_entry(ptr ,&birthday_list, list){
              printk(KERN_INFO "order node : %d \n",ptr->year);
       }
}

void clear_birthday_list(void) {
       struct birthday *ptr, *next;
       printk(KERN_INFO "start delete: \n");
       list_for_each_entry_safe(ptr, next ,&birthday_list, list){
              list_del(&ptr->list);
              printk(KERN_INFO "delete node : %d \n",ptr->year);
              kfree(ptr);
       }
}


/* This function is called when the module is loaded. */
int simple_init(void)
{
       printk(KERN_INFO "Loading Module\n");
       init_birthday_list();       
       return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
       clear_birthday_list();
	printk(KERN_INFO "Removing Module\n");
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

