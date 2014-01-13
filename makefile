testprog: fitsarrayvv.o testprog.o
	gcc -o testprog fitsarrayvv.o testprog.o -lcfitsio -pthread -lm

testprog.o: ./src/testprog.c
	gcc -c -Wall -W -ansi -pedantic ./src/testprog.c

fitsarrayvv.o: ./src/fitsarrayvv.c ./src/fitsarrayvv.h
	gcc -c -Wall -W -ansi -pedantic ./src/fitsarrayvv.c
