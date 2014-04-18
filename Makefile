src=./src

objects=testprog.o fitsarrayvv.o

vpath %.h $(src)
vpath %.c $(src)

CC=gcc
CFLAGS=-Wall -W -O -pedantic -I$(src)
LDLIBS=-lcfitsio -pthread -lm

testprog: $(objects) 
	@$(CC) -o testprog $(objects) $(LDLIBS) 
	@rm *.o

.SILENT: $(objects)
