#include <linux/module.h>
#include <linux/io.h>
#include <linux/slab.h>
#include "msr.h"

static inline uint64_t exec_rdmsr(uint64_t msr)
{
	uint32_t low, high;
	asm volatile (
		"rdmsr"
		: "=a"(low), "=d"(high)
		: "c"(msr)
	);
	return ((uint64_t)high << 32) | low;
}

static int __init
foo_init (void)
{
    ulong phys;
    u32 callnum;

    asm volatile ("vmcall"
                  : "=a" (callnum)
                  : "a" (0), "b" ("foo"));

    if (callnum == 0) {
        printk ("[foo] vmcall foo failed.\n");
        return -EINVAL;
    }
    uint64_t res = exec_rdmsr(MSR_IA32_LSTAR);
    phys = virt_to_phys ((uint64_t *)res);
    printk("MOLY: %lx\n", phys);
    asm volatile ("vmcall"
                  :
                  : "a" (callnum), "b" (phys));
    return 0;
}

static void __exit
foo_exit(void)
{
    printk("[foo] exit\n");
}

module_init (foo_init);
module_exit (foo_exit);