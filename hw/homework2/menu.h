
//name: thuyvy nguyen
//program: assignment 2 (pizza)
//date: 29 april 2018
//input: file and userinput
//output: pizzas and file
//file: menu.h


#include <iostream>
#include <string>
#include "pizza.h"
using namespace std;
#ifndef MENU_H
#define MENU_H

struct pizzamenu{
	string name;
	int small_cost;
	int medium_cost;
	int large_cost;
	int num_ingredients;
	string * ingredients;
};

class Menu{
	private: 
		int num_pizzas;
		Pizza *pizzas;
	public:
	//include accessor functions and mutator functions for each private memember
	//include constructors, copy constructors, assignment overload
	//desttuctors where appropriate


	Menu();
	
	void output_menu();
	int order_total(string,string,int);
	int error_order_menu(string);

	int get_num_pizzas()const;
	Pizza* get_pizzas()const;

	void set_num_pizzas(int);
	void set_pizzas(Pizza *);

	//Menu search_pizza_by_cost(int, string);
	//Menu search_pizza_by_ingredients_to_exclude(string *, int);
	//Menu search_pizza_by_ingredients_to_include(string *, int);
	void swap_data(int i);
	void search_pizza_by_cost();
	void search_pizza_by_ingredients_to_include();
	void search_pizza_by_ingredients_to_exclude();
	void add_to_menu(Pizza);
	void remove_pizza_from_menu();

	Menu(const Menu&);
	const Menu& operator =(const Menu &);
	~Menu();

};
#endif
