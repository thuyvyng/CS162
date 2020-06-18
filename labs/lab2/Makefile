CC = g++
exe_file = lab2
$(exe_file): driver.o lab2.o
	$(CC) driver.o lab2.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
lab2.o: lab2.cpp
	$(CC) -c lab2.cpp

clean:
	rm -f *.out *.o $(exe_file)
