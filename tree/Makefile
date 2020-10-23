
CC = g++ -g

main:main.o TNode.o
	$(CC) -o a.out main.o TNode.o 

main.o:main.cpp
	$(CC) -c main.cpp

TNode.o:TNode.h TNode.cpp
	$(CC) -c TNode.cpp

clean:
	rm *.o a.out





