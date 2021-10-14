a.out: main.o shifter.o
	gcc *.o
main.o: shifter.h main.c
	gcc -c main.c
rate.o: shifter.h shifter.c
	gcc -c shifter.c
clean:
	rm a.out
	rm *.o