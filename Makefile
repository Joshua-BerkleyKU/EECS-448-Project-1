Run: main.o Client.o Player.o Boards.o
	g++ -std=c++11 -g -Wall main.o Client.o Player.o Boards.o -o Run

main.o: main.cpp Client.h Player.h
	g++ -std=c++11 -g -Wall -c main.cpp

Client.o: Client.h Client.cpp
	g++ -std=c++11 -g -Wall -c Client.cpp

Player.o: Player.h Player.cpp
	g++ -std=c++11 -g -Wall -c Player.cpp

Boards.o: Boards.h Boards.cpp
	g++ -std=c++11 -g -Wall -c Boards.cpp

clean:
	rm *.o Run
