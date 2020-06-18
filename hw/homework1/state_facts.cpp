//program: state_facts.cpp
//author: thuyvy nguyen
//date: april 14th 2018
//desciption: function bodies for assign 1
//input: file num of states user input
//output: the state and counties description


#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include "state_facts.h"

using namespace std;



//function: get_file name
//description: error handles getting correct text file in cmd
//parameters: command line and files
//pre:the command line numbers are right
//post: valid file is passed
//******************************************************************
char * get_file_name ( char*argv[], int argc, char* file, ifstream & input){
	if(strcmp(argv[1],"-f") == 0) {
		strcpy(file,argv[2]);
		input.open(file);
		while (!input.is_open()){
			cout << "Invalid file name in Command line." << endl;
			cout << "Enter file name to open: ";
			cin.getline(file,256);
			input.open(file);
		}

	}
	else if(strcmp(argv[3],"-f") == 0) {
		strcpy(file,argv[4]);
		input.open(file);
		while (!input.is_open()){
			cout << "Invalid file name in Command line." << endl;
			cout << "Enter file name to open: ";
			cin.getline(file,256);
			input.open(file);
		}
	}

	return file;
}
//function: get_outfile
//description:handles asking user if they want a file
//******************************************************************
char * get_outfile (char* file1, ofstream & outfile){

	cout << "\033[1;31mEnter Return to print to screen or file name to save: \033[0m";
	cin.getline(file1,256);

	if (file1[0] != '\0') {
               	outfile.open(file1);
        }

	return file1;
}
// (i used this from cs162 for error handling)
//******************************************************************
bool is_int(string num){
	bool c_num = 0;
	int len = 0;
	int l = num.length();
	
	while(num[len] != '\0'){
		if(((num[len] > 47) && (num[len] < 58)) || (num[len] == 45)){
			len++;
		}
		else{
			break;
		}
	c_num = 1;
	}
	return c_num;
}
//(from cs161)
//******************************************************************
int get_int(string bin){
	int res = 0;
	for (int i = 0; i < bin.length(); i++){
		int check = bin[i] - '0';
		int topower = int(bin.length()) -i -1;
		res = (int)((check*pow(10.0,topower)) + res);
	}
	return res;
}
//(from cs161)
//******************************************************************
int get_num_states( char*argv[], int argc){
	int check = 0;
	string enter_states = "";
	if(strcmp(argv[1],"-s") == 0) {
		if (is_int(argv[2]) == 0){
			cout << "Invalid number of states in Command line." << endl;
			do{
				cout << "Enter number of states: ";
				getline(cin,enter_states);
			}while (is_int(enter_states) == 0);
		}
		else{
			return get_int(argv[2]);
		}
	}
	else if(strcmp(argv[3],"-s") == 0) {
		if (is_int(argv[4]) == 0){
			cout << "Invalid number of states in Command line." << endl;
			do{
				cout << "Enter number of states: ";
				getline(cin,enter_states);
			}while (is_int(enter_states) == 0);
		}
		else{
			return get_int(argv[4]);
		}
	}

	return get_int(enter_states);
}
//function: is_valid-arguments
//description: checks if command line arguments has correct arguments
//parameters: checks command line 
//pre: user runs the program
//post: program continues or ends
//******************************************************************
bool is_valid_arguments(char *argv[], int argc){
	bool end = 0;

	if (argc == 5){
		if (strcmp(argv[1],"-s") == 0) {
			if (strcmp(argv[3],"-f") == 0){
				end = 1;
			}
		}

		else if(strcmp(argv[1],"-f") == 0) {
			if (strcmp(argv[3],"-s") == 0){
				end = 1;
			}
		}
	}
	return end;
}
//function create_states and create_counties
//description: creates array with their respective structs
//parameters: respective ints
//pre: user gives an int?
//post: array!!!
//******************************************************************
state * create_states(int num_states){
	state *states_db = new state[num_states];

        return states_db;
}
//look above
//******************************************************************
county * create_counties(int num_counties){
	county *counties_db = new county[num_counties];

	return counties_db;
}
//function: get_county_data
//description: reads from file to array
//paramters: arrays, number of counties, and stream file
//pre: theres a file and an array
//post: array filled out
//******************************************************************
void get_county_data(county* counties_db, int num_counties, ifstream & input){
	for (int i = 0; i < num_counties; i++){
		input >> counties_db[i].name >> counties_db[i].population >> counties_db[i].avg_income 
                      >> counties_db[i].avg_house >> counties_db[i].cities;

		counties_db[i].city = new string[counties_db[i].cities];        // Allocate city array memory
		for (int j = 0; j < counties_db[i].cities ; j++){
			input >> counties_db[i].city[j];
		}
	}
}
//function: get_stata_data
//description: reads from file to an array
//parameters: arrays number of states and file
//pre: states good counties good and theres an fstream
//post: array filled out
//******************************************************************
void get_state_data(state * states_db, county* counties_db, int num_states, ifstream & input){

	for (int i = 0; i < num_states; i++){
		input >> states_db[i].name >> states_db[i].population >> states_db[i].counties;
		counties_db = create_counties(states_db[i].counties);
		get_county_data(counties_db, states_db[i].counties, input);

		states_db[i].c = counties_db;

		for (int j = 0; j < states_db[i].counties; j++)
			delete [] counties_db[j].city;
	}
}


//function: delete_info
//description: deletes memory so no leaks
//parameters: takes in states array and number of states
//pre: takes in all of the arrays (and arrays in the arrays)
//post: no memory leaks!!
//******************************************************************
void delete_info(state **state_info, int num_states){
	for (int i = 0; i < num_states; i++){
		delete[] *state_info;
		*state_info = NULL;
	}
}
//function: state_largest_population
//description: finds the state with the largest population
//parameters: takes in the array with num of states and the output file
//pre: states array and num
//post: prints it out
//******************************************************************
void state_largest_population(state * states_db, int num_states, ofstream & outfile) {
	string largest_population_state;
	int largest_population;
                       
        if (outfile == 0)
		cout << endl << "State with largest population ";
	else
		outfile << endl << "State with largest population ";

	for (int i = 0; i < num_states-1; i++){
        	if (states_db[i].population > states_db[i+1].population) {
                	largest_population_state = states_db[i].name;
                	largest_population = states_db[i].population;
        	} else {
                	largest_population_state = states_db[i+1].name;
                	largest_population = states_db[i+1].population;
        	}
	}

        if (outfile == 0)
		cout << endl << largest_population_state << " has the Largest Population of "
             	<< largest_population << endl << endl;
	else
		outfile << endl << largest_population_state << " has the Largest Population of "
             	<< largest_population << endl << endl;
}
//function: county_largest_popuation
//parameters: takes in states array and numver of states and output file
//description: finds the county with the largest population
//pre: states array is filled
//post: finds and prints out the county with largest pop
//******************************************************************
void county_largest_population(state * states_db, int num_states, ofstream & outfile) {
	string largest_population_state;
	string largest_population_county;
	int largest_population = 0;

        if (outfile == 0)
	        cout << endl << "County with largest population ";
	else
                outfile << endl << "County with largest population ";

	for (int i = 0; i < num_states; i++){
		for (int j = 0; j < states_db[i].counties; j++){
        		if (states_db[i].c[j].population > largest_population) {
                		largest_population_state = states_db[i].name;
                		largest_population_county = states_db[i].c[j].name;
              		  	largest_population = states_db[i].c[j].population;
        		}
                }
	}

        if (outfile == 0)
	        cout << endl << largest_population_state << ": " << largest_population_county
                     << " County has the Largest Population of " << largest_population << endl << endl << endl;
	else
                outfile << endl << largest_population_state << ": " << largest_population_county
                     << " County has the Largest Population of " << largest_population << endl << endl << endl;
}
//function: county_income
//description: prints out county income
//parameters: states array number of states and stream
//pre: states array is created and stream
//post: printed out to file or scren
//******************************************************************
void county_income(state * states_db, int num_states, ofstream & outfile) {
	string enter_income = "";

        if (outfile == 0)
	        cout << "County with income above enter amount" << endl;
	else
                outfile << "County with income above enter amount" << endl;

	do{
		cout << "\033[1;31mEnter income amounts: \033[0m";
		getline(cin,enter_income);
	}while (is_int(enter_income) == 0);

	for (int i = 0; i < num_states; i++){
		for (int j = 0; j < states_db[i].counties; j++){
        		if (states_db[i].c[j].avg_income > float(get_int(enter_income))) {
                                if (outfile == 0)
				        cout << states_db[i].name << " has County " << states_db[i].c[j].name
                                             << " income " << states_db[i].c[j].avg_income << " above " << enter_income << endl;
				else
                                        outfile << states_db[i].name << " has County " << states_db[i].c[j].name
                                             << " income " << states_db[i].c[j].avg_income << " above " << enter_income << endl;
        		}
                }
	}

        if (outfile == 0)
	        cout << endl << endl;
	else
                outfile << endl << endl;
}
//function: countuy_avg_house
//description: prints out the average household cost in all counties
//parameters: states array number of states and the stream
//pre: states array num of states and stream
//post: printed out to file/screen
//******************************************************************
void county_avg_house(state * states_db, int num_states, ofstream & outfile) {
	float avg_house_state = 0;

        if (outfile == 0)
	        cout << "State average house cost for all County";
	else
                outfile << "State average house cost for all County";

	for (int i = 0; i < num_states; i++){
		for (int j = 0; j < states_db[i].counties; j++){
        		avg_house_state = avg_house_state + states_db[i].c[j].avg_house;
                }
                if (outfile == 0)
		        cout << endl << states_db[i].name << " average House cost = " << avg_house_state/states_db[i].counties;
		else
                        outfile << endl << states_db[i].name << " average House cost = " << avg_house_state/states_db[i].counties;
	}

        if (outfile == 0)
	        cout << endl << endl << endl;
	else
                outfile << endl << endl << endl;
}

//******************************************************************
//function:state_sort_name
//description: sorts states by alpha
//parameters: states array number of states and files
//pre: files are there and arrays
//post: states arranged and printed


void state_sort_name(state * states_db, int num_states, ofstream & outfile) {
	string state_name[num_states];
	string tmp1;

        if (outfile == 0)
	        cout << "State sort by name";
	else
                outfile << "State sort by name";

	for (int i = 0; i < num_states; i++)
		state_name[i] = states_db[i].name;

	for (int i = 0; i < num_states-1; i++){
		if (state_name[i] > state_name[i+1]) {
                	tmp1 = state_name[i];
                	state_name[i] = state_name[i+1];
        		state_name[i+1] = tmp1;
                }
	}

	for (int i = 0; i < num_states; i++) {
                if (outfile == 0)
		        cout << endl << state_name[i];
		else
                        outfile << endl << state_name[i];
        }

        if (outfile == 0)
	        cout << endl << endl << endl;
	else
	        outfile << endl << endl << endl;
}

//******************************************************************
//function: state_sort_population
//description: sorts states by population
//parameters: states array number of states and the file
//pre: states array is created and there is an fstream
//post: states are sorted by population

void state_sort_population(state * states_db, int num_states, ofstream & outfile) {
	string state_name[num_states];
	string tmp1;
        int population[num_states];
        int tmp2;

        if (outfile == 0)
	        cout << "State sort by population";
	else
	        outfile << "State sort by population";

	for (int i = 0; i < num_states; i++) {
		state_name[i] = states_db[i].name;
		population[i] = states_db[i].population;
        }

	for (int i = 0; i < num_states-1; i++){
		if (population[i] > population[i+1]) {
                	tmp2 = population[i];
                	population[i] = population[i+1];
        		population[i+1] = tmp2;
                	tmp1 = state_name[i];
                	state_name[i] = state_name[i+1];
        		state_name[i+1] = tmp1;
                }
	}

	for (int i = 0; i < num_states; i++) {
        	if (outfile == 0)
			cout << endl << state_name[i] << " has population: " << population[i];
                else
			outfile << endl << state_name[i] << " has population: " << population[i];
        }

        if (outfile == 0)
		cout << endl << endl << endl;
	else
		outfile << endl << endl << endl;
}

//******************************************************************
//program: county_sort_name
//description: sort counties by alphabetical order
//parameters: states array number of states and the files
//pre: states array has been created
//post: counties will be alphabatized and printed
void county_sort_name(state * states_db, int num_states, ofstream & outfile) {
	string county_name[num_states];
	string tmp1;

        if (outfile == 0)
		cout << "County sort by name" << endl;
	else
		outfile << "County sort by name" << endl;

	for (int i = 0; i < num_states; i++){
		for (int j = 0; j < states_db[i].counties; j++){
        		county_name[j] = states_db[i].c[j].name;
                }
                
		for (int j = 0; j < states_db[i].counties-1; j++){
			if (county_name[j] > county_name[j+1]) {
                		tmp1 = county_name[j];
                		county_name[j] = county_name[j+1];
        			county_name[j+1] = tmp1;
			}
		}

                if (outfile == 0)
		        cout << states_db[i].name << " has County: " << endl;
		else
		        outfile << states_db[i].name << " has County: " << endl;
		for (int j = 0; j < states_db[i].counties; j++){
                        if (outfile == 0)
			        cout << "    " << county_name[j] << endl;
			else
                                outfile << "    " << county_name[j] << endl;
                }
	}

        if (outfile == 0)
	        cout << endl << endl;
	else
	        outfile << endl << endl;
}



//******************************************************************
//function: county_sort_population
//description: sorts population by least to greatest
//parameters: the states array, how many states, and the fstream stuff
//pre: that the states array has been created
//post: the counties will be sorted and printed

void county_sort_population(state * states_db, int num_states, ofstream & outfile) {
	string county_name[num_states];
	string tmp1;
        int population[num_states];
        int tmp2;

        if (outfile == 0)
	        cout << "State sort by population" << endl;
	else
                outfile << "State sort by population" << endl;

	for (int i = 0; i < num_states; i++){
		for (int j = 0; j < states_db[i].counties; j++){
        		county_name[j] = states_db[i].c[j].name;
        		population[j] = states_db[i].c[j].population;
                }
                
		for (int j = 0; j < states_db[i].counties-1; j++){
			if (population[j] > population[j+1]) {
                		tmp2 = population[j];
                		population[j] = population[j+1];
        			population[j+1] = tmp2;
                		tmp1 = county_name[j];
                		county_name[j] = county_name[j+1];
        			county_name[j+1] = tmp1;
			}
		}

        	if (outfile == 0)
			cout << states_db[i].name << endl ;
                else
			outfile << states_db[i].name << endl ;
		for (int j = 0; j < states_db[i].counties; j++){
        		if (outfile == 0)
				cout << "    County " << county_name[j] << " has population " << population[j] << endl;
                        else
				outfile << "    County " << county_name[j] << " has population " << population[j] << endl;
                }
	}

        if (outfile == 0)
		cout << endl << endl;
        else
		outfile << endl << endl;
}
