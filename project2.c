//Name: Matthew Murphy
//ID: 15147193

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

int entry(void)
{
	printk(KERN_INFO "Loading");
	struct task_struct *task;
	
	for_each_process(task){
		printk(KERN_INFO "pid: %d|\tpname: %s|\tstate: %ld\n", task->pid, task->comm, task->state);
	}
	
	printk(KERN_INFO "Done\n");
	return 0;
}

void exit(void)
{
	printk(KERN_INFO "Removed Module");
}

module_init(entry);
module_exit(exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Matthew Murphy");
MODULE_DESCRIPTION("This loadable kernal module prints a list of current processes.");
