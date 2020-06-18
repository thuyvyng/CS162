CC = g++
exe_file = real_estate
$(exe_file): driver.o functions.o properties.o players.o random_event.o
	$(CC) driver.o functions.o properties.o players.o random_event.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
functions.o: functions.cpp
	$(CC) -c functions.cpp
properties.o: properties.cpp
	$(CC) -c properties.cpp
players.o: players.cpp
	$(CC) -c players.cpp
random_event.o: random_event.cpp
	$(CC) -c random_event.cpp
clean:
	rm -f *.out *.o $(exe_file)

