#include <iostream>
#include <string>
#include "pizza.h"
#include "menu.h"
//#include "lab3.h"

using namespace std;

#ifndef RESTAURANT_H
#define RESTAURANT_H



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
		Menu menu;
		int num_days_open;
		int num_employees;
		employee * employees;
		hours * week;
		string name;
		string phone;
		string address;
	public:
	//need to include accessor functions and mutator functions for each pri memb
	

//	Menu menu;
	Restaurant();

	Menu get_menu() const;
	employee * get_employees() const;
	hours * get_weeks() const;
	string get_name() const;
	string get_phone() const;
	string get_address() const;

	void set_menu(Menu);
	void set_employees(employee*);
	void set_weeks(hours*);
	void set_name(string);
	void set_phone(string);
	void set_address(string);



	void load_data();
	bool login(string, string);
	void view_menu();
	void view_hours();
	void view_address();
	void view_phone();
	void search_menu_by_price();
	void search_by_ingredients();
	void place_order(Pizza *);
	void change_hours();
	void add_to_menu();
	void remove_from_menu();
	void view_orders();
	void remove_orders();
	
	Restaurant(const Restaurant&);
	const Restaurant & operator =(const Restaurant &);

	~Restaurant();
};



#endif
