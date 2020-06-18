//program: run_facts.cpp
//author: thuyvy nguyen
//date: april 14th 2018
//description: the driver file for assign 1
//input: command line, files, and user input
//output: files or print to screen


#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include "state_facts.h"

using namespace std;

//******************************************************************
int main(int argc, char *argv[]){
	ifstream input;
	ofstream outfile;

	char* file = new char[256];
	char* file1 = new char[256];

	int num_state_enter;
	state *states_db;
 	county* counties_db;

	if ( is_valid_arguments(argv,argc) == 1){
		num_state_enter = get_num_states(argv,argc);
		states_db = create_states(num_state_enter);

                file = get_file_name(argv,argc,file, input);
		ifstream input(file);	    // opens a stream of the file

        	get_state_data(states_db, counties_db, num_state_enter, input);

                file1 = get_outfile (file1, outfile);
		ofstream outfile(file1);	    // opens a stream of the file

		state_largest_population(states_db, num_state_enter, outfile);
		county_largest_population(states_db, num_state_enter, outfile);
		county_income(states_db, num_state_enter, outfile);
		county_avg_house(states_db, num_state_enter, outfile);
		state_sort_name(states_db, num_state_enter, outfile);
		state_sort_population(states_db, num_state_enter, outfile);
		county_sort_name(states_db, num_state_enter, outfile);
		county_sort_population(states_db, num_state_enter, outfile);
	}
	else{
		cout << "Error. Invalid command line arguments" << endl;
	}

	delete [] file;
	delete [] file1;

	for (int i = 0; i < num_state_enter; i++){
	        delete [] states_db[i].c;
	}

        delete_info(&states_db, num_state_enter);

	return 0;
}
