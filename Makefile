all: tictactoe

tictactoe: main.o Game.o Board.o
	g++ main.o Game.o Board.o -o tictactoe -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp

Game.o: Game.cpp
	g++ -c Game.cpp

Board.o: Board.cpp
	g++ -c Board.cpp

clean:
	rm -rf *o tictactoe
