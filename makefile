# Order of the dependencies matters, sort of. It runs from left -> right.
# Run by running 'make' in the terminal

### Class Example ###

#strtest: dwstring.o main.o
#	gcc -o strtest dwstring.o main.o

#dwstring.o: dwstring.c dwstring.h
#	gcc -c dwstring.c

#main.o: main.c dwstring.h
#	gcc -c main.c

# Only one that happens automatically
# my_str_y_functions.o and main.o are run because they're
# dependencies of test.
test: my_str_y_strings.o main.o
	gcc -o test my_str_y_strings.o main.o

my_str_y_functions.o: my_str_y_strings.c my_str_y_strings.h
	gcc -c my_str_y_strings.c

main.o: main.c my_str_y_strings.h
	gcc -c main.c

# Does not run automatically because it is not a dependency
# of test. Use by running 'make run'
run: test
	./test

clean:
	rm *.o
	rm *~