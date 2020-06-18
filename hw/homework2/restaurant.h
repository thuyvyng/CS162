
//name: thuyvy nguyen
//program: assignment 2 (pizza)
//date: 29 april 2018
//input: file and userinput
//output: pizzas and file
//file: restaurant.cpp

#include <iostream>
#include <string>
#include "pizza.h"
#include "menu.h"

using namespace std;

#ifndef RESTAURANT_H
#define RESTAURANT_H


struct order{
	string number;
	string first_name;
	string last_name;
	string reference;
	string address;
	string phone;
	string name;
	string size;
	string qty;
};

struct employee{
	string id;
	string first_name;
	string last_name;
	string password;
};

struct hours{
	string day;
	string open_hour;
	string close_hour;
};

class Restaurant{

	private:
		int num_days_open;
		int num_employees;
		employee * employees;
		hours * week;
		string name;
		string phone;
		string address;
		int totalorder;
		order * orderinfo;

	public:
	//need to include accessor functions and mutator functions for each pri memb
	

	Menu menu;
	Restaurant();

	employee * get_employees() const;
	hours * get_weeks() const;

	Menu get_menu() const;
	string get_name() const;
	string get_phone() const;
	string get_address() const;

	void set_menu(Menu);
	void set_employees(employee*);
	void set_weeks(hours*);
	void set_name(string);
	void set_phone(string);
	void set_address(string);

	void load_order_data();
	void load_restaurant_data();

	bool login(string, string) const;
	void view_menu();
	void view_hours();
	void view_address();
	void view_phone();

//	void place_order(Pizza *);

	void change_hours();
	void add_to_menu();
	void remove_from_menu();
	void view_orders();
	void remove_orders();

	void save_rest_info();
	int orders_info();
	void place_orders();
	void search_by_cost();
	void search_by_ingredients();
	void Include_ingredients();
	void Exclude_ingredients();

	Restaurant(const Restaurant&);
	const Restaurant & operator =(const Restaurant &);

	~Restaurant();
};



#endif
