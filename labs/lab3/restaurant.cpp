#include "restaurant.h"
#include "pizza.h"
#include "menu.h"
//#include "lab3.h"

//#ifndef RESTAURANT_H
//#define RESTAURANT_H
using namespace std;


Restaurant::Restaurant(){
	//how do i do the menu menu one
	
//	for (int i = 0; i < num_employees; i++){
//		employees[i] = ///????????
//	}
	Menu menu; //fix this here!!!!!
	num_employees = 0; //fix these laters
	num_days_open = 7; //fix these laters

	employees = NULL;
	week = NULL;


//	for (int i = 0; i < num_days; i++){
//		week[i] = ////?????
//	}

	name = "NameofRestaurant";
	phone = "541idkidkidk";
	address = "osu";
}

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

Menu Restaurant::get_menu()const{
	return menu;
}

employee *Restaurant::get_employees()const{
	return employees;
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

Restaurant:: ~Restaurant(){
	delete [] employees;
	delete [] week;
}
