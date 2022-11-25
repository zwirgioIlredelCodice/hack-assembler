assembler: main.o ains.o cins.o
	gcc -o assembler main.o ains.o cins.o

main.o: main.c ains.h cins.h
	gcc -c main.c

ains.o: ains.c ains.h
	gcc -c ains.c

cins.o: cins.c cins.h
	gcc -c cins.c
run:
	./assembler
clean:
	rm *.o assembler

