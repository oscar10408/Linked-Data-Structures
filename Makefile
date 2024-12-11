all: proj4.exe

LinkedNodeClass.o: LinkedNodeClass.cpp
	g++ -g -std=c++98 -Wall -c LinkedNodeClass.cpp -o LinkedNodeClass.o 
SortedListClass.o: SortedListClass.cpp LinkedNodeClass.h
	g++ -g -std=c++98 -Wall -c SortedListClass.cpp -o SortedListClass.o 
LIFOStackClass.o: LIFOStackClass.cpp LinkedNodeClass.h
	g++ -g -std=c++98 -Wall -c LIFOStackClass.cpp -o LIFOStackClass.o 
FIFOQueueClass.o: FIFOQueueClass.cpp LinkedNodeClass.h
	g++ -g -std=c++98 -Wall -c FIFOQueueClass.cpp -o FIFOQueueClass.o 
proj4.o: project4.cpp SortedListClass.o LIFOStackClass.o FIFOQueueClass.o
	g++ -g -std=c++98 -Wall -c project4.cpp -o proj4.o
proj4.exe: LinkedNodeClass.o SortedListClass.o LIFOStackClass.o FIFOQueueClass.o proj4.o
	g++ -g -std=c++98 LinkedNodeClass.o SortedListClass.o LIFOStackClass.o FIFOQueueClass.o proj4.o -o proj4.exe

clean:
	rm -rf *.o *.exe
