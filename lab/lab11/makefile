all : lab11

lab11 : function.o main.o 
		gcc function.o main.o -o sort

function.o: function.c header.h 
		gcc function.c -c
			
main.o: main.c header.h 
	gcc main.c -c


clean:
		rm *.o lab11
