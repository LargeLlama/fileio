all: main.o
	@gcc -o fileio.out main.o

main.o: main.c
	@gcc -c main.c

run:
	@./fileio.out

clean:
	@rm *.o*
	@rm test.txt
