all: run

test_tree.exe: test_tree.o tree.o
	gcc test_tree.o tree.o -o test_tree.exe

tree.o: tree.c tree.h
	gcc -c tree.c -o tree.o

test_tree.o: test_tree.c tree.h
	gcc -c test_tree.c -o test_tree.o

main.exe: main.o
	gcc main.o tree.o -o main.exe

main.o: main.c tree.h
	gcc -c main.c -o main.o

run: test_tree.exe
	./test_tree.exe

run_main: main.exe
	./main.exe

build: test_tree.exe
	@echo "The assembly is completed"

clean:
	rm -f *.o test_tree.exe
