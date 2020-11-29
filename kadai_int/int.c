#include <linux/kernel.h>	/* We're doing kernel work */
#include <linux/module.h>	/* Specifically, a module */
#include <linux/sched.h>
#include <linux/workqueue.h>
#include <linux/interrupt.h>	/* We want an interrupt */

irqreturn_t int068_interrupt(int irq, void *dev_id)
{
    printk("Interrupt should be handled there\n");
}

static int __init
clcdint_init(void)
{
    unsigned int irq;
    unsigned int irqflags;
    int ret;

    irq=0;
    irqflags=IRQF_NO_SUSPEND;

    ret = request_irq(irq, int068_interrupt,
            irqflags, "clcdint-int-timer", NULL);

    if (ret!=0) {
            printk("ERROR: Cannot request IRQ %d", irq);
    }

    printk("CLCDINT_INIT\n");
    return 0;
}

module_init(clcdint_init);

static void __exit
clcdint_exit(void)
{
    unsigned int irq;
    irq=0;
    free_irq(irq, NULL);
    printk("CLCDINT_EXIT\n");
}

module_exit(clcdint_exit);
