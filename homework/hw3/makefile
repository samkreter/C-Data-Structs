all : hw3

hw3 : driver.o algorithm.o 
		gcc driver.o algorithm.o -o hw3

driver.o: driver.c header.h
		gcc driver.c -c
			
algorithm.o: algorithm.c header.h
		gcc algorithm.c -c

clean:
		rm *.o hw3
