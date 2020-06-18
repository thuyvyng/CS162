
CC = g++
exe_file = pizza
$(exe_file): driver.o menu.o restaurant.o pizza.o
	$(CC) driver.o menu.o restaurant.o pizza.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
menu.o: menu.cpp
	$(CC) -c menu.cpp
restaurant.o: restaurant.cpp
	$(CC) -c restaurant.cpp
pizza.o: pizza.cpp
	$(CC) -c pizza.cpp
clean:
	rm -f *.out *.o $(exe_file)

