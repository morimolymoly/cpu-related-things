.PHONY: all
EXTRA_CFLAGS := -I$(PWD)/../include
obj-m := vmcall_ia32.o
KERNEL_DIR = /lib/modules/$(shell uname -r)/build
VERBOSE   := 0

all:
	make -C $(KERNEL_DIR) --include-dir=$(PWD)/$(INCLUDES) SUBDIRS=$(PWD) KBUILD_VERBOSE=0  modules

clean:
	rm -rf  *.o *.ko *.mod.c *.symvers *.order .tmp_versions .vmcall_ia32.* .cache.*

test:
	sudo insmod vmcall_ia32.ko && dmesg | tail -n2 | grep "MOLY" | sudo rmmod vmcall_ia32
