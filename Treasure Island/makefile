all: final

final: main.o Character.o Space.o Dirt.o Grass.o Sand.o Special.o Game.o
	g++ -std=c++11 main.o Character.o Space.o Dirt.o Grass.o Sand.o Special.o Game.o -o final

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Character.o: Character.cpp
	g++ -std=c++11 -c Character.cpp

Space.o: Space.cpp
	g++ -std=c++11 -c Space.cpp

Dirt.o: Dirt.cpp
	g++ -std=c++11 -c Dirt.cpp

Grass.o: Grass.cpp
	g++ -std=c++11 -c Grass.cpp

Sand.o: Sand.cpp
	g++ -std=c++11 -c Sand.cpp

Special.o: Special.cpp
	g++ -std=c++11 -c Special.cpp

Game.o: Game.cpp
	g++ -std=c++11 -c Game.cpp

zip:
	zip Final_Project_Lee_David.zip -D *.cpp *.hpp *.pdf *.txt makefile

clean:
	rm *.o final