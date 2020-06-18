
//name: thuyvy nguyen
//program: assignment 2 (pizza)
//date: 29 april 2018
//input: file and userinput
//output: pizzas and file
//file: pizza.cpp


#include <fstream>
#include <iostream>

#include "pizza.h"
#include "menu.h"
#include<string>

using namespace std;


Pizza::Pizza(){
	ingredients = NULL;
} 
//copy constructor
Pizza::Pizza(const Pizza& copy){

//	cout << "1" << endl;

	name = copy.name;
	small_cost = copy.small_cost;
	medium_cost = copy.medium_cost;
	large_cost = copy.large_cost;
	num_ingredients = copy.num_ingredients;
	if (num_ingredients == 0)
		ingredients = NULL;
	else{
		ingredients = new string[num_ingredients];
		for (int i = 0; i < num_ingredients; i++){
			ingredients[i] = copy.ingredients[i];
		}
	}
}
//Pizza assignment overload
const Pizza& Pizza:: operator = (const Pizza& copy){	
	
//	cout << "const Pizza& Pizza:: operator = (const Pizza& copy)" << endl;
	name = copy.name;
	small_cost = copy.small_cost;
	medium_cost = copy.medium_cost;
	large_cost = copy.large_cost;
	num_ingredients = copy.num_ingredients;

	if (ingredients != NULL)
		delete [] ingredients;
	if (num_ingredients == 0)
		ingredients = NULL;
	else{
		ingredients = new string[num_ingredients];
		for (int i = 0; i < num_ingredients; i++){
			ingredients[i] = copy.ingredients[i];
		}
	}

	return *this;
}
//accessors
string Pizza::get_name()const{
	return name;

}

int Pizza::get_small_cost()const{
	return small_cost;
}

int Pizza::get_medium_cost()const{
	return medium_cost;
}

int Pizza::get_large_cost()const{
	return large_cost;
}

int Pizza::get_num_ingredients()const{
	return num_ingredients;
}

string * Pizza::get_ingredients()const{
	return ingredients;
}
// mutators
void Pizza:: set_name(string n){
	name = n;
}

void Pizza::set_small_cost(int s){
	small_cost = s;
}


void Pizza::set_medium_cost(int m){
	medium_cost = m;
}


void Pizza::set_large_cost(int l){
	large_cost = l;
}

void Pizza::set_num_ingredients(int ni){
	num_ingredients = ni;
}

void Pizza::set_ingredients(string * arr){
	ingredients = arr;
}

//Pizza destructor
Pizza :: ~ Pizza(){
	delete [] ingredients;

}










