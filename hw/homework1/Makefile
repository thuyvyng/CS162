
CC = g++
exe_file = run_facts
$(exe_file): run_facts.o state_facts.o
	$(CC) run_facts.o state_facts.o -o $(exe_file)
driver.o: run_facts.cpp
	$(CC) -c run_facts.cpp
lab2.o: state_facts.cpp
	$(CC) -c state_facts.cpp

clean:
	rm -f *.out *.o $(exe_file)

