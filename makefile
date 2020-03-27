CC = g++
quicksort.out: quicksort.o
	$(CC) -o quicksort.out quicksort.o

quicksort.o : quicksort.cpp
	$(CC) -c quicksort.cpp

clean:
	rm *.o *.out




