assembler: main.o
	gcc -o assembler main.o

main.o: main.c #defs.h
	gcc -c main.c

run:
	./assembler
clean:
	rm *.o assembler

