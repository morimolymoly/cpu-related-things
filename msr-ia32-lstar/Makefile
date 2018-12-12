.PHONY: all
EXTRA_CFLAGS := -I$(PWD)/../include
obj-m := msr-ia32-lstar.o
KERNEL_DIR = /lib/modules/$(shell uname -r)/build
VERBOSE   := 0

all:
	make -C $(KERNEL_DIR) --include-dir=$(PWD)/$(INCLUDES) SUBDIRS=$(PWD) KBUILD_VERBOSE=0  modules

clean:
	rm -rf  *.o *.ko *.mod.c *.symvers *.order .tmp_versions .msr-ia32-lstar.* .cache.*

test:
	sudo insmod msr-ia32-lstar.ko && dmesg | tail -n 2 | grep "MOLY" && sudo rmmod msr-ia32-lstar
