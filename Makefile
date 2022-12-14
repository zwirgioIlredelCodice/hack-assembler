assembler: main.o ains.o cins.o assemblatore.o symboltable.o
	gcc -o assembler main.o ains.o cins.o assemblatore.o symboltable.o

main.o: main.c assemblatore.h 
	gcc -c main.c

ains.o: ains.c ains.h
	gcc -c ains.c

cins.o: cins.c cins.h
	gcc -c cins.c

symboltable.o: symboltable.c symboltable.h
	gcc -c symboltable.c

assemblatore.o: assemblatore.c assemblatore.h ains.h cins.h symboltable.h
	gcc -c assemblatore.c

run:
	./assembler
clean:
	rm *.o assembler

