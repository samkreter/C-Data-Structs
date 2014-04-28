all : hw4

hw4 : stack.o calculator.o frontend.o
		gcc stack.o calculator.o frontend.o -o hw4

frontend.o: frontend.c calculator.h
		gcc frontend.c -c

stack.o: stack.c stack.h
		gcc stack.c -c
			
calculator.o: calculator.c calculator.h
		gcc calculator.c -c


clean:
		rm *.o hw4
