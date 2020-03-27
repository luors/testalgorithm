CC = g++
a.out: main.o
	$(CC) -o a.out main.o

main.o : main.cpp
	$(CC) -c main.cpp

clean:
	rm *.o a.out




