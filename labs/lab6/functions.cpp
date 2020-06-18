#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "properties.h"
#include "functions.h"
#ifndef PROPERTIES_H
#define PROPERTIES_H

using namespace std;

int property_value_h(){
	int range = 0;
	range = rand()% 500000;
	range = 100000 + range;
	return range;

}


int property_value_b(){
	int range = 0;
	range = rand()% 200000;
	range = 400000 + range;
	return range;

}

int property_value_a(){
	int range = 0;
	range = rand()% 300000;
	range = 300000 + range;
	return range;


}

string location(){
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

int mortage(){
	int monthly = 1000;
	int yes = 0;

	yes = rand()%3500;

	monthly = monthly + yes;
	return monthly;

}

void populate_potential_business(Business *b, int num_complexes){

	more_business * business_tenants = new more_business[num_complexes];	

	for (int i = 0, i < num_complexes, i++){
		int yo = 0;
		yo = rand()%3;
		if (yo == 0)
			business_tenants[i].size = "S";
		else if (yo == 1)
			business_tenants[i].size = "M";
		else if (yo == 2)
			business_tenants[i].size = "L";
		business_tenants[i].rent = 0;

	}

	b[i] = (property_value_b(), location, mortage(), 1.5, num_complexes, business_tenants); //add an array here);
	//go into header file and make it also point to an array

}


void populate_potential_properties(House * h, Apartment * a, Business* b, int size){	
	for (int i = 0, i< size, i++){
		h[i] = House(property_value_h() , location , mortage() , 1.5,1);
	}
	for (int i = 0, i< size, i++){
//		b[i] = Business(property_value_b() , location , mortage() , 1.5,1);
		int num_complexes = 0;
		num_complexes = (rand()%4) +1;
		b[i] = populate_potential_business(b,num_complexes);
	
	}
	for (int i = 0, i < size, i++){
		int room_size = 0;
		room_size = (rand()% 9) + 1;
		a[i] = Apartment(property_value_a(), location, mortage(), 1.5, room_size);
	}
}



#endif
