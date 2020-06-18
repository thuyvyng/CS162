
//name: thuyvy nguyen
//program: assignment 2 (pizza)
//date: 29 april 2018
//input: file and userinput
//output: pizzas and file
//file: pizza.h

#include <iostream>
#include <string>
using namespace std;
#ifndef PIZZA_H
#define PIZZA_H

class Pizza {
	
	public:
	//include accessor functions and mutator functions for each private member
	//need to include constructors, copy construcors, assignment overload
	//destructors where appropriate

	Pizza();

	string get_name()const;
	int get_small_cost()const;
	int get_medium_cost()const;
	int get_large_cost()const;
	int get_num_ingredients()const;
	string* get_ingredients()const;


	void set_name(string);
	void set_small_cost(int);
	void set_medium_cost(int);
	void set_large_cost(int);
	void set_ingredients(string*);
	void set_num_ingredients(int);

	Pizza(const Pizza&); //copy constructor
	const Pizza& operator=(const Pizza &); // assignment overload
	~Pizza();

	private:
		string name;
		int small_cost;
		int medium_cost;
		int large_cost;
		int num_ingredients;
		string * ingredients;
};
#endif 
