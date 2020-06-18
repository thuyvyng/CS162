#include <iostream>
#include <string>
#include "pizza.h"
using namespace std;
#ifndef MENU_H
#define MENU_H

class Menu{
	private: 
		int num_pizzas;
		Pizza *pizzas;
	public:
	//include accessor functions and mutator functions for each private memember
	//include constructors, copy constructors, assignment overload
	//desttuctors where appropriate


	Menu();
	
	
	int get_num_pizzas()const;
	Pizza* get_pizzas()const;

	void set_num_pizzas(int);
	void set_pizzas(Pizza *);
		
	Menu search_pizza_by_cost(int, string);
	Menu search_pizza_by_ingredients_to_include(string *, int);
	Menu search_pizza_by_ingredients_to_exclude(string *, int);
	void add_to_menu(Pizza);
	void remove_from_menu(int);

	Menu(const Menu&);
	const Menu& operator =(const Menu &);
	~Menu();

};
#endif
