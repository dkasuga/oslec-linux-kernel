/* An example of Memory Allocation */

#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/gfp.h>
#include<linux/highmem.h>

#define size 10

#define PRINT_PREF  "[HIGHMEM]: "
#define INTS_IN_PAGE (PAGE_SIZE/sizeof(int))

const char* STUDENT_ID = "48-206511";

static int __init alloc_init(void)
{
    struct page *my_page;
    char *pointer;
    
    printk(PRINT_PREF "Entering module.\n");

    my_page = alloc_page(GFP_HIGHUSER);
    if(!my_page) return -1;

    printk(PRINT_PREF "Page allocation is successful");

	// pointer = kmalloc(size, GFP_KERNEL);  
    pointer = (char*)kmap(my_page);
	
	if(!pointer)
        printk(KERN_ALERT" Faild ");

    strncpy(pointer, STUDENT_ID, size);

	printk(PRINT_PREF " student id : %s ", pointer);
	// kfree(pointer);
    kunmap(my_page);
    __free_pages(my_page, 0);
	return 0;
}



static void __exit alloc_exit(void)
{
	printk(KERN_ALERT"Time to exit");
}

module_init(alloc_init);
module_exit(alloc_exit);
