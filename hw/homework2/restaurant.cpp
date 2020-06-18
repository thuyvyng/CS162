
//name: thuyvy nguyen
//program: assignment 2 (pizza)
//date: 29 april 2018
//input: file and userinput
//output: pizzas and file
//file: restaurant.cpp
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <stdio.h>
#include "restaurant.h"
#include "pizza.h"
#include "menu.h"

//#ifndef RESTAURANT_H
//#define RESTAURANT_H
using namespace std;

extern string prompt_input(string tmp);
extern int get_total_lines(char* file);
extern int get_int(string bin);
extern bool is_int(string num);
extern string ErrorHandlingInt(string tmp, string tmp1);
extern string ErrorHandlingSize(string tmp, string tmp1);


//******************************************************************
Restaurant::Restaurant(){
	employees = NULL;
	week = NULL;

	num_employees = get_total_lines("employee.txt");
	name = "NameofRestaurant";
	phone = "defaultnumber";
	address = "corvallis" ;

	load_restaurant_data();
}
//Restaurant copy constructor
Restaurant::Restaurant(const Restaurant& copy){
	menu = copy.menu;
	name = copy.name;
	phone = copy.phone;
	address = copy.address;

	if (num_employees == 0)
		employees = NULL;
	else{
		employees = new employee[num_employees];
		for (int i = 0; i< num_employees; i++){
			employees[i] = copy.employees[i];
		} 
	}


	if (num_days_open == 0)
		week = NULL;
	else{
		week = new hours[num_days_open];
		for (int i = 0; i< num_days_open; i++){
			week[i] = copy.week[i];	
		} 
	}
}

//Restaurant assignment overload
const Restaurant& Restaurant :: operator= (const Restaurant& copy){

	name = copy.name;
	phone = copy.phone;
	address = copy.address;
	if (employees != NULL)
		delete [] employees;
	if (num_employees == 0)
		employees = NULL;
	else{
		employees = new employee[num_employees];
		for (int i = 0; i< num_employees; i++){
			employees[i] = copy.employees[i];	
		} 
	}

	if (week != NULL)
		delete [] week;
	if (num_days_open == 0)
		week = NULL;
	else{
		week = new hours[num_days_open];
		for (int i = 0; i< num_days_open; i++){
			week[i] = copy.week[i];	
		} 
	}

	return *this;

}
//function: login
//description: checks if employee login is valid
//parameters: id and password
//pre: employee trys to log in
//post: returns whether or not it was valid
//******************************************************************
bool Restaurant::login(string in_id, string in_password) const{
	ifstream input;
	input.open("employee.txt");

	employee *employee_db = new employee[Restaurant::num_employees];
	for (int i = 0; i < Restaurant::num_employees; i++){
		input >> employee_db[i].id >> employee_db[i].first_name >> employee_db[i].last_name >> employee_db[i].password;
	}
	input.close();

	int done = 0;
	for ( int i = 0 ; i < Restaurant::num_employees; i++){
		if (in_id == employee_db[i].id){
			if (in_password == employee_db[i].password){
				cout << endl << "Welcome " << employee_db[i].first_name << employee_db[i].last_name << "! ";
				done = 1;
				break;
			}
		}	
	}

	if (done != 1){
		cout << endl << "Invalid id/password. Try again." << endl << endl;
	}
	
	delete [] employee_db;

	return done;
}
//function: get_employees
//description: gets input from employee for login
//parameters: none
//pre: user must select employee
//pos: will reprompt until valid
//******************************************************************
employee *Restaurant::get_employees()const{
        bool done;
        string id;
        string password;
	do{
		id = prompt_input("Please provide your ID number: ");
		password = prompt_input("Please provide your password: ");
		done = login(id, password);
	}while (!done);

}
//function: load_restaurant_data
//description: reads from restaurant text to fulfill data
//parameters: n/a
//pre: none
//post: data is loaded
//******************************************************************
void Restaurant::load_restaurant_data(){
	ifstream input;

	// Loading Restaurant Infomation from restaurant_info.txt
	input.open("restaurant_info.txt");

	getline(input, Restaurant::name);
	getline(input, Restaurant::phone);
	getline(input, Restaurant::address);
        input >> Restaurant::num_days_open;

	hours *weekday_db = new hours[Restaurant::num_days_open];
	for (int i = 0; i < Restaurant::num_days_open; i++){
		input >> weekday_db[i].day >> weekday_db[i].open_hour >> weekday_db[i].close_hour;
	}
	input.close();
	Restaurant::week = weekday_db;

        weekday_db = NULL;
	delete [] weekday_db;
}
//function: load_order_data
//description: reads order text to fulfill data
//parameters: n/a
//pre: none
//post: data is fulfilled
//******************************************************************
void Restaurant::load_order_data(){
	ifstream input;

	// Loading Restaurant Infomation from restaurant_info.txt
	input.open("order.txt");

	Restaurant::totalorder = get_total_lines("order.txt");

	order *order_db = new order [Restaurant::totalorder];

	for (int i = 0; i < Restaurant::totalorder; i++){
		input >> order_db[i].number >> order_db[i].first_name >> order_db[i].last_name >> order_db[i].reference >>
                         order_db[i].address >> order_db[i].phone >> order_db[i].name >> order_db[i].size >> order_db[i].qty;
	}

	Restaurant::orderinfo = order_db;

	input.close();
}
//function: save_rest_info
//description: writes to file
//parameters: none
//pre: change to file
//post: file changed woo
//******************************************************************
void Restaurant::save_rest_info(){
	ofstream outfile;;
	outfile.open("restaurant_info.txt");
        outfile << Restaurant::name << endl;
        outfile << Restaurant::phone << endl;
        outfile << Restaurant::address << endl;
        outfile << Restaurant::num_days_open << endl;
	for (int i = 0; i < Restaurant::num_days_open; i++){
		outfile << Restaurant::week[i].day << " " << Restaurant::week[i].open_hour << " " << Restaurant::week[i].close_hour << endl;
	}
	outfile.close();
}



//function: change_hours
//description: if the employee wants to change store hours
//parameters: none
//pre: user must have selected to change hours
//post: hours are changed (or not changed!)
//******************************************************************
void Restaurant::change_hours(){
	string day = prompt_input("Which day would you like to change the hours for (Sun Mon Tue Wed Thu Fri Sat)? ");
	string opening = prompt_input("What should the opening time be? ");
	string closing = prompt_input("What should the closing time be? ");
	int num = Restaurant::num_days_open;

	for (int i = 0; i < Restaurant::num_days_open; i++){
		if( (day == Restaurant::week[i].day) && (get_int(opening) < 13 ) && (get_int(closing) < 13) ) {
			Restaurant::week[i].open_hour = opening;
			Restaurant::week[i].close_hour = closing;
			break;
   		}
		else if( i == (num-1)){
			cout << "Invalid input" << endl;
		}
	}
		
	cout << endl << "Here are the hours:" << endl;
	for (int i = 0; i < Restaurant::num_days_open; i++){
		cout << Restaurant::week[i].day << " " << Restaurant::week[i].open_hour << " " << Restaurant::week[i].close_hour << endl;
	}
	save_rest_info();
}



//Functions: view_BLANK
//description: prints out the corresponding thing
//parameters: none
//pre: user selects the corresponding function
//post: prints to screen
//******************************************************************
void Restaurant::view_hours(){
	cout << endl << "Here are the Restaurant hours:" << endl;
	for (int i = 0; i < Restaurant::num_days_open; i++){
		cout << Restaurant::week[i].day << " " << Restaurant::week[i].open_hour << " " << Restaurant::week[i].close_hour << endl;
	}
	cout << endl;
}

//******************************************************************
void Restaurant::view_address(){
	cout << endl << "The Restaurant address:" << endl;
		cout << Restaurant::address << endl << endl;
}

//******************************************************************
void Restaurant::view_phone(){
	cout << endl << "Here are the Restaurant phone:" << endl;
		cout << Restaurant::phone << endl << endl;
}

//******************************************************************
void Restaurant::view_orders(){
	load_order_data();

	for (int i = 0; i < Restaurant::totalorder; i++){
		cout << Restaurant::orderinfo[i].number << " " << Restaurant::orderinfo[i].first_name << " "
                     << Restaurant::orderinfo[i].last_name << " " << Restaurant::orderinfo[i].reference << " "
                     << Restaurant::orderinfo[i].address << " " << Restaurant::orderinfo[i].phone << " "
                     << Restaurant::orderinfo[i].name << " " << Restaurant::orderinfo[i].size << " "
                     << Restaurant::orderinfo[i].qty << endl;
	}
	delete [] orderinfo;
}
//***************************************************************************************************************************


//function: remove_orders
//description: employee wants to remove order 
//parameters: none
//pre: employee must want to remove order
//post: order gone
void Restaurant::remove_orders(){
	load_order_data();
	string remove = prompt_input("Which order number you want to remove (1, 2, etc...)? ");

	ofstream outfile;;
	outfile.open("order.txt");

	for (int i = 0; i < Restaurant::totalorder; i++){
	        if (remove != Restaurant::orderinfo[i].number)
			outfile << Restaurant::orderinfo[i].number << " " << Restaurant::orderinfo[i].first_name << " " << Restaurant::orderinfo[i].last_name << " " <<
                                   Restaurant::orderinfo[i].reference << " " << Restaurant::orderinfo[i].address << " " << Restaurant::orderinfo[i].phone << " " <<
                                   Restaurant::orderinfo[i].name << " " << Restaurant::orderinfo[i].size << " " << Restaurant::orderinfo[i].qty << endl;
	}
	outfile.close();
	delete [] orderinfo;
}
//function: ErrorHandlingName
//description: error handles user typing in names wrong for pizzas
//parameters: pizza names
//pre: user inserts pizzas name
//post: yes/no
//******************************************************************
string ErrorHandlingName(string tmp, string tmp1) {

	Menu error;

        string tmp2;
        do {
       		tmp2 = prompt_input(tmp);

       		if (error.error_order_menu(tmp2) == 0)
                   	cout << endl << tmp1 << endl;
        	else 
			return tmp2;
	} while (1);
}
//function: orders_info
//description: takes info from user when they make an order
//parameters: none
//pre: user wants a pizza
//post: pizza added to order
//******************************************************************
int Restaurant::orders_info(){
	std::ofstream outfile;

	outfile.open("order.txt", std::ios_base::app);
	string PizzaOrderFirst = prompt_input("Enter First Name? ");
        string PizzaOrderLast = prompt_input("Enter Last Name? ");
	string PizzaCC = prompt_input("Enter credit card info");
        string PizzaOrderAddress = prompt_input("Enter address (123_Washington_Way)? ");
        string PizzaOrderPhone = prompt_input("Enter phone (5556768989)? ");
        
        string PizzaOrderTypeQty = ErrorHandlingInt("How many Pizza Type you want to order? ", "Pizza Type you want to order need to be a number, please re-enter: ");

	for (int i = 0; i < get_int(PizzaOrderTypeQty); i++){
        	string PizzaOrderName = ErrorHandlingName("Enter Pizza Name (The_Bent, Corvegas, etc...)? ", "Pizza Name does not exit, please re-enter: ");
        	string PizzaOrderSize = ErrorHandlingSize("Enter Pizza Size (S, M, L)? ", "Pizza Size does not exit, please re-enter: ");
        	string PizzaOrderQty = ErrorHandlingInt("Enter order Quantity? ", "Pizza Qty need to be a number, please re-enter: ");

		outfile << get_int(Restaurant::orderinfo[Restaurant::totalorder - 1].number)+1 << " " <<
                           PizzaOrderFirst << " " << PizzaOrderLast << " " <<
                          //get_int(Restaurant::orderinfo[Restaurant::totalorder - 1].number)+1 << " " <<
			   PizzaCC << " " <<
                           PizzaOrderAddress << " " << PizzaOrderPhone << " " << PizzaOrderName << " " <<
                           PizzaOrderSize << " " << PizzaOrderQty << endl;
	}

	outfile.close();
	return (get_int(PizzaOrderTypeQty));
}
//function: place_orders
//description: main function for user to placing orders
//parameters: nona
//pre: user wants to place an order
//post: order placed
//******************************************************************
void Restaurant::place_orders(){

	load_order_data();  // Load order to fill structure for order enter information
	int totalOrder = orders_info(); // Enter Order information
	delete [] orderinfo;

	load_order_data();  // Reload order
        int total_price = 0;
	for (int i = 0; i < totalOrder; i++){
        	int last_order = Restaurant::totalorder - i - 1;
		Menu size_price;
	}

	cout << "Thanks for ordering!"  << endl;

	delete [] orderinfo;
}
//function: view_menu
//description: prints out menu
//parameters: none
//pre: wants to print out menu
//post: menu printed
//******************************************************************
void Restaurant::view_menu(){
	Menu display;
	display.output_menu();
}



//function: remove_from_menu
//description: removes a pizza from the menu
//parameters: none
//pre: menu is filled
//post: new menu!
//******************************************************************
void Restaurant::remove_from_menu(){
	Menu remove;
	remove.remove_pizza_from_menu();
}
//function: search_by-cost
//description: sorts pizza by cost
//parameters: none
//pre: menu
//psot: new menu
//******************************************************************
void Restaurant::search_by_cost(){
	Menu search_cost;
	search_cost.search_pizza_by_cost();
}
//function: search_by_ingredients
//parameters: none
//description: user inserts ingredients to find
//pre: pizza
//post: pizza list
//******************************************************************
void Restaurant::search_by_ingredients(){
	Menu search_ingredients;
	string ans = prompt_input("Would you like to search for ingredients you want include (I) or exclude (E)? ");
	if (ans == "I") {
		search_ingredients.search_pizza_by_ingredients_to_include();
	} else if (ans == "E") {
        	search_ingredients.search_pizza_by_ingredients_to_exclude();
        } else
                cout << "Error" << endl;

}
//function: add_to_menu
//parameters: none
//description: employee gets to add to file
//pre:menu
//post: bigger menu!!
//******************************************************************
void Restaurant::add_to_menu(){
	std::ofstream outfile;;
	outfile.open("menu.txt", std::ios_base::app);

        outfile << prompt_input("Enter Name of item to add? ") << " ";
        outfile << prompt_input("Enter small_cost? ") << " ";
        outfile << prompt_input("Enter medium_cost? ") << " ";
        outfile << prompt_input("Enter large_cost? ") << " ";
        string num_ingredients = prompt_input("num_ingredients? ");
        outfile << num_ingredients << " ";

	for (int i = 0; i < get_int(num_ingredients); i++){
        	outfile << prompt_input("Enter ingredients? ") << " ";
	}

	outfile.close();
}

//Menu accessor and mutators

Menu Restaurant::get_menu()const{
	return menu;
}

hours * Restaurant::get_weeks()const{
	return week;
}

string Restaurant::get_name()const{
	return name;
}

string Restaurant::get_phone()const{
	return phone;
}

string Restaurant::get_address()const{
	return address;
}

void Restaurant::set_menu(Menu m){
	menu = m;
}

void Restaurant::set_employees(employee* e){
	employees = e;
}


void Restaurant::set_weeks(hours * w){
	week = w;
}


void Restaurant::set_name(string s){
	name = s;
}

void Restaurant::set_phone(string p){
	phone = p;
}

void Restaurant::set_address(string a){
	address = a;
}
//Restaurant destructor
Restaurant:: ~Restaurant(){
	delete [] employees;
	delete [] week;
//	delete [] orderinfo;
}
