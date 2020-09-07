Run: main.o Client.o
	g++ -std=c++11 -g -Wall main.o Client.o -o Run

main.o: main.cpp Client.h
	g++ -std=c++11 -g -Wall -c main.cpp

Client.o: Client.h Client.cpp
	g++ -std=c++11 -g -Wall -c Client.cpp



clean:
	rm *.o Run
