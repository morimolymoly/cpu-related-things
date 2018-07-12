SOURCE = ./src
INCLUDES = -I$(SOURCE)/include
OBJS = $(SOURCE)/msr-ia32-lstar.o

CFLAGS = -O2 -Wall -Wextra $(INCLUDES)

.PHONY: default
default:
	$(MAKE) all

all: $(OBJS) Makefile

%.o : %.c Makefile
	gcc $*.c -o $*.o $(CFLAGS)

.PHONY: clean
clean:
	rm $(SOURCE)/*.o
