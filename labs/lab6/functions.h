#include <iostream>
#include <string>

using namespace std;

struct more_business{
	string size;
	int rent;

};

int property_value_b();
int property_value_h();
int property_value_a();
string location();
int mortage();
void populate_potential_business(Business *, int);
void populate_potential_properties(House *, Apartment *, Business*, int);
