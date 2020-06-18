#include <iostream>
using namespace std;


bool is_int(string );
int get_int(string );
int checkCol(int , char ** );
int checkRow(int , char ** );



struct mult_div_values{
	int mult;
	float div;

};


mult_div_values** create_table(int, int);

void set_mult_values(mult_div_values ** ar, int , int) ;
void set_div_values(mult_div_values**, int , int );

void print_table(mult_div_values**, int , int );

void delete_table(mult_div_values**, int);



