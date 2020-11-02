/* An example of Memory Allocation */

#include<linux/slab.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

#define size 10

MODULE_DESCRIPTION("example of memory allocation ");
MODULE_AUTHOR("cvam");
MODULE_LICENSE("GPL");

const char* STUDENT_ID = "48-206511";

static int __init alloc_init(void)
{
    char *pointer;
    
	pointer = kmalloc(size, GFP_KERNEL);  
	
	if(!pointer)
	{	printk(KERN_ALERT" Faild ");
		//report error 
	}

    strncpy(pointer, STUDENT_ID, size);

	printk(" student id : %s ", pointer);
	kfree(pointer);
	return 0;
}



static void __exit alloc_exit(void)
{
	printk(KERN_ALERT"Time to exit");
}

module_init(alloc_init);
module_exit(alloc_exit);
