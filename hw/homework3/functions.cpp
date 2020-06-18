#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "properties.h"
#include "functions.h"

using namespace std;

//function: property_value_BLANK
//description: determines the random property value for the corresponding property type
//parameters: none
//pre: there needs to be a property filled
//post: property value has been filled
//******************************************************************
int property_h(){
	int range = 0;
	range = rand()% 500000;
	range = 100000 + range;
	return range;
}

int property_a(){
	int range = 0;
	range = rand()% 300000;
	range = 300000 + range;
	return range;
}

int property_b(){
	int range = 0;
	range = rand()% 200000;
	range = 400000 + range;
	return range;
}

//******************************************************************
//function: property_location
//description: randomizes a location
//parameters: nona
//pre: need a location
//post: location given

string property_location(){
	int x = rand()% 5;
	string address = "";

	if( x == 0)
		address = "SE";
	else if (x == 1)
		address = "NE";
	else if (x == 2)
		address = "MIDWEST";
	else if (x == 3)
		address = "SW";
	else if (x == 4)
		address = "NW";

	return address;
}

//******************************************************************
//function: property_mortage
//description: assigns a mortage for each property the user buys
//parameters: none
//pre: user buys a property
//post: user has to pay mortage the next turn
int property_mortgage(){
	int monthly = 1000;
	int yes = 0;

	yes = rand()%3500;

	monthly = monthly + yes;
	return monthly;

}

//******************************************************************
//function: property_size
//description: randomizes size of business complez
//parameters: nona
//pre: has to be a business complex
//post: size given
string property_size(){
	int x = rand()%3;
	string size = "";

	if (x == 0)
		size = "S";
	else if (x == 1)
		size = "M";
	else if (x == 2)
		size = "L";
	return size;

}


