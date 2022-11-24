assembler: main.o ains.o
	gcc -o assembler main.o ains.o

main.o: main.c ains.h
	gcc -c main.c

ains.o: ains.c ains.h
	gcc -c ains.c
run:
	./assembler
clean:
	rm *.o assembler

