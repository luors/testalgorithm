
CC = g++ -g -o0 -std=c++11

a.out:find.cpp io.out heap.out t.out tt.out
	$(CC) find.cpp -o a.out


io.out:iostreamtest.cpp
	$(CC) iostreamtest.cpp -o io.out

	
heap.out:heaptest.cpp
	$(CC) heaptest.cpp -o heap.out

t.out:threadtest.cpp
	$(CC) threadtest.cpp -lpthread -o t.out	

tt.out:templatetest.cpp
	$(CC) templatetest.cpp -o tt.out
	
clean:
	rm *.out

