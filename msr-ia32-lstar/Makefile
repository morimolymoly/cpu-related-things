.PHONY: all clean
INCLUDES = -I../include
obj-m := msr-ia32-lstar.o

all:
	make -C ../output $(INCLUDES) M=$(PWD) modules

clean:
	make -C ../linux M=$(PWD) clean
