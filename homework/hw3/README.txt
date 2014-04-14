For this makefile I will be explaining what each aspect does briefly:

This is how a typical makefile will look like:

all : hello_world

hello_world : main.o code.o 
	gcc main.o code.o -o hello_world

main.o: main.c hello_world_header.h
	gcc main.c -c
	
code.o: code.c hello_world_header.h
	gcc code.c -c

clean:
	rm *.o hello_world
	
A makefile typically doesn't have an extension such as .jpeg, .c, .txt, etc.
It is saved as an all (*) file.

all: hello_world

In this line, hello_world is the name of our file that is made. When the
user types ./hello_world it will run their program similar to ./a.out. This is also
where all of our object files will be held in.

hello_world: main.o code.o
	gcc main.o code.o -o hello_world
	
Within hello_world as mentioned before, our object files will be held here. Notice
that we the gcc command to compile main.o and code.o. The -o tag describes that we are
compiling object files now into hello_world.

main.o: main.c hello_world_header.h
	gcc main.c -c
	
Similar to hello_world, this describes that we want to compile an object file for our
makefile. main.o will take in main.c and hello_world_header.h and compile our main.c
like how we have been compiling our programs all semester. The only difference here
when we compile is that we want to compile the object file to have the header file
as well.

code.o: code.c hello_world_header.h
	gcc code.c -c
	
This is just like main.o execept is compiled for code.o.

clean:
	rm *.o hello_world
	
This command basically gets rid of any existing makefiles and object files associated
with hello_world. Typing the command make clean will do this action for us.

In order to use the code above you must save the the makefile with the name "Makefile"
then type the command make and it will create the executable for us. Here is an example:

[cjvqm9@babbage helloWorld]$ make
gcc main.c -c
gcc code.c -c
gcc main.o code.o -o hello_world
