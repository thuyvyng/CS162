//program: state_facts.h
//author: thuyvy nguyen
//date: april 14th
//description: function declarations for assignment 1
//input; arrays, file, command line
//output: sorted and printed into another file


#include <iostream>
#include <string>

using namespace std;

struct county{
	string name;
	string *city;
	int cities;
	int population;
	float avg_income;
	float avg_house;
};


struct state{
	string name;
	struct county *c;
	int counties;
	int population;
};

bool is_valid_arguments(char*[], int);

bool is_int(string);

int convert_int( char*[], int);

int get_int(string);

state * create_states(int);

void get_state_data(state*, county*, int, ifstream &);

county * create_countries(int);

void get_county_data(county*, int, ifstream &);

void delete_info(state**, int);

char * get_file_name ( char*argv[], int argc, char* file, ifstream &);

char * get_outfile (char* file1, ofstream & outfile);

int get_num_states( char*argv[], int argc);

void state_largest_population(state * states_db, int num_states, ofstream &);

void county_largest_population(state * states_db, int num_states, ofstream &);

void county_income(state * states_db, int num_states, ofstream &);

void county_avg_house(state * states_db, int num_states, ofstream &);

void state_sort_name(state * states_db, int num_states, ofstream &);

void state_sort_population(state * states_db, int num_states, ofstream &);

void county_sort_name(state * states_db, int num_states, ofstream &);

void county_sort_population(state * states_db, int num_states, ofstream &);






























