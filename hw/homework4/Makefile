CC = g++
exe_file = ants_and_bees
$(exe_file): driver.o insect.o bee.o ant.o harvester.o bodyguard.o fire.o longthrower.o ninja.o shortthrower.o thrower.o wall.o game.o
	$(CC) driver.o insect.o bee.o ant.o harvester.o bodyguard.o fire.o longthrower.o ninja.o shortthrower.o thrower.o wall.o game.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
insect.o: insect.cpp
	$(CC) -c insect.cpp
bee.o: bee.cpp
	$(CC) -c bee.cpp
ant.o: ant.cpp
	$(CC) -c ant.cpp
harvester.o: harvester.cpp
	$(CC) -c harvester.cpp
bodyguard.o: bodyguard.cpp
	$(CC) -c bodyguard.cpp
fire.o: fire.cpp
	$(CC) -c fire.cpp
longthrower.o: longthrower.cpp
	$(CC) -c longthrower.cpp
ninja.o: ninja.cpp
	$(CC) -c ninja.cpp
shortthrower.o: shortthrower.cpp
	$(CC) -c shortthrower.cpp
thrower.o: thrower.cpp
	$(CC) -c thrower.cpp
wall.o: wall.cpp
	$(CC) -c wall.cpp
game.o: game.cpp
	$(CC) -c game.cpp
clean:
	rm -f *.out *o $(exe_file)
