.PHONY: all clean

obj-m := msr-ia32-lstar.o

all:
    make -C ../output M=$(PWD) modules

clean:
    make -C ../linux M=$(PWD) clean
