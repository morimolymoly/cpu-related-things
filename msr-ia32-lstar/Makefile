.PHONY: all
INCLUDES = -I../include
obj-m := msr-ia32-lstar.o
KERNEL_DIR = /lib/modules/$(shell uname -r)/build
VERBOSE   := 0

all:
	make -C $(KERNEL_DIR) $(INCLUDES) SUBDIRS==$(PWD) KBUILD_VERBOSE=$(VERBOSE) modules

clean:
	rm -rf  *.o *.ko
