CC = g++
quicksort.out: quicksort.o common.h
	$(CC) -o quicksort.out quicksort.o

quicksort.o : quicksort.cpp common.h
	$(CC) -c quicksort.cpp


clean:
	rm *.o *.out




