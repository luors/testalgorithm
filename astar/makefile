a.out:main.o gamemap.o
	gcc -g -o a.out main.o gamemap.o

main.o:gamemap.c
	gcc -g -c main.c

gamemap.o:gamemap.c
	gcc -g -c gamemap.c

clean:
	rm a.out *.o