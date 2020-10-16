CC = g++

a.out: main.o gamemap.o
	$(CC) -o a.out main.o gamemap.o

main.o:main.cpp
	$(CC) -c main.cpp

gamemap.o: gamemap.cpp
	$(CC) -c gamemap.cpp
	
clean:
	rm *.o *.out




