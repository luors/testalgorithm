CC = g++

a.out: main.cpp quicksort.out bubblesort.out
	$(CC) -o a.out main.cpp

quicksort.out: quicksort.o common.h
	$(CC) -o quicksort.out quicksort.o

quicksort.o : quicksort.cpp common.h
	$(CC) -c quicksort.cpp


bubblesort.out: bubblesort.o common.h
	$(CC) -o bubblesort.out bubblesort.o

bubblesort.o : bubblesort.cpp common.h
	$(CC) -c bubblesort.cpp


clean:
	rm *.o *.out




