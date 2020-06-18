//name: thuyvy nguyen
//program: assignment 2 (pizza)
//date: 29 april 2018
//input: file and userinput
//output: pizzas and file
//file: menu.cpp
#include <iostream>

#include <fstream>
#include "menu.h"
#include <string>
#include "pizza.h"
using namespace std;

extern string prompt_input(string tmp);
extern int get_total_lines(char* file);
extern int get_int(string bin);
extern string ErrorHandlingInt(string tmp, string tmp1);
extern string ErrorHandlingSize(string tmp, string tmp1);

//******************************************************************
Menu::Menu(){
	pizzas = NULL;

	set_num_pizzas(get_total_lines("menu.txt"));

	pizzamenu pizzamenu_db;
        Pizza TmpPizza_db;
        Pizza *Pizza_db = new Pizza[get_num_pizzas()];

	ifstream input;
	input.open("menu.txt");


	for (int i = 0; i < get_num_pizzas(); i++){
	        // Get Pizza data for menu.txt file
		input >> pizzamenu_db.name >> pizzamenu_db.small_cost >> pizzamenu_db.medium_cost
                      >> pizzamenu_db.large_cost >> pizzamenu_db.num_ingredients;

		string *ingredients_db = new string[pizzamenu_db.num_ingredients];

		for (int j = 0; j < pizzamenu_db.num_ingredients; j++)
			input >> ingredients_db[j];

                // Assign each element from TmpPizza_db to Pizza class
		TmpPizza_db.set_name(pizzamenu_db.name);
		TmpPizza_db.set_small_cost(pizzamenu_db.small_cost);
		TmpPizza_db.set_medium_cost(pizzamenu_db.medium_cost);
		TmpPizza_db.set_large_cost(pizzamenu_db.large_cost);
		TmpPizza_db.set_num_ingredients(pizzamenu_db.num_ingredients);
		TmpPizza_db.set_ingredients(ingredients_db);

                // Copy TmpPizza_db to Pizza_db...  Need to check ---const Pizza& Pizza:: operator = (const Pizza& copy)---
                Pizza_db[i] = TmpPizza_db;

                if (i < (get_num_pizzas()-1)) delete [] ingredients_db;
	}

        // Reassign temporary TmpPizza_db to Menu::pizzas
	Menu::pizzas = Pizza_db;

	input.close();

	Pizza_db = NULL;
	delete [] Pizza_db;
}

//menu copy constructor
Menu::Menu(const Menu& copy){
	num_pizzas = copy.num_pizzas;
	if (num_pizzas == 0)
		pizzas = NULL;
	else {
		pizzas = new Pizza[num_pizzas];
		for (int i = 0; i < num_pizzas; i++){
			pizzas[i] = copy.pizzas[i];
		}
	}
}

//menu assignment overload
const Menu & Menu:: operator=(const Menu& copy){

	num_pizzas = copy.num_pizzas;
	if (pizzas != NULL)
		delete [] pizzas;
	if (num_pizzas == 0)
		pizzas = NULL;
	else {
		pizzas = new Pizza[num_pizzas];
		for (int i = 0; i < num_pizzas; i++){
			pizzas[i] = copy.pizzas[i];
		}
	}
	return *this;
}
//Menu accessors****************************************************
int Menu:: get_num_pizzas()const{
	return num_pizzas;
}

Pizza * Menu:: get_pizzas()const{
	return pizzas;
}

void Menu:: set_num_pizzas(int pizzas){
	num_pizzas = pizzas;
}

void Menu:: set_pizzas(Pizza * food){
	pizzas = food;
}

//******************************************************************
//function: output_menu
//description: prints out the menu
//parameters: n/a
//pre: user/customer selects to print out pizza
//post: menu is printed out

void Menu:: output_menu(){
	for (int i = 0; i < Menu::get_num_pizzas(); i++){
        	cout << " " << Menu::pizzas[i].get_name() << " " << Menu::pizzas[i].get_small_cost() 
                     << " " << Menu::pizzas[i].get_medium_cost() << " " << Menu::pizzas[i].get_large_cost() 
                     << " " << Menu::pizzas[i].get_num_ingredients();

                string * ingredients_tmp = Menu::pizzas[i].get_ingredients();
		for (int j = 0; j <  Menu::pizzas[i].get_num_ingredients(); j++){
        		cout << " " << ingredients_tmp[j];
		}
        	cout << endl;
	}
}

//******************************************************************
//function: error_order_menu
//description: check if the pizza customer orders is valid
//parameters: pizza name
//pre: needs to select a pizza
//post: returns whether or not pizza is valid

int Menu:: error_order_menu(string name){
	for (int i = 0; i < Menu::get_num_pizzas(); i++){
	        if (name == Menu::pizzas[i].get_name()){
			return 1;
                }
        }
        return 0;
}

//******************************************************************
//function: order_total
//description: calculates how much the order costs
/*
int Menu:: order_total(string name, string size, int qty){
        int total_price;
	for (int i = 0; i < Menu::get_num_pizzas(); i++){
	        if (name == Menu::pizzas[i].get_name()) {
			if (size == "S")
				total_price = Menu::pizzas[i].get_small_cost() * qty;
			else if (size == "M")
				total_price = Menu::pizzas[i].get_medium_cost() * qty;
			else if (size == "L")
				total_price = Menu::pizzas[i].get_large_cost() * qty;
                }
        }
        return total_price;
}
*/


//function: remove_pizza_from_menu
//description: removes pizza from menu
//parameters: none
//pre: employee selects to remove pizza type
//post: no more of that pizza!
//******************************************************************
void Menu:: remove_pizza_from_menu(){
	string remove = prompt_input("Which item you want to remove (The_Bent, Corvegas, etc...)? ");

	ofstream outfile;;
	outfile.open("menu.txt");

	for (int i = 0; i < Menu::get_num_pizzas(); i++){
	        if (remove != Menu::pizzas[i].get_name()) {
        		outfile << " " << Menu::pizzas[i].get_name() << " " << Menu::pizzas[i].get_small_cost()
			     << " " << Menu::pizzas[i].get_medium_cost() << " " << Menu::pizzas[i].get_large_cost()
                     	     << " " << Menu::pizzas[i].get_num_ingredients();

                	string * ingredients_tmp = Menu::pizzas[i].get_ingredients();
			for (int j = 0; j <  Menu::pizzas[i].get_num_ingredients(); j++){
        			outfile << " " << ingredients_tmp[j];
			}
        		outfile << endl;
                }
	}

	outfile.close();
}
//function: swap_data
//description: this is used to find pizzas that fulfill
//		search pizza by cost
//parameters: index of pizza found
//pre: pizza fulfills index
//post: puts pizza in new list
//******************************************************************
void Menu::swap_data(int i){
        int tmp2 = Menu::pizzas[i].get_small_cost();
        Menu::pizzas[i].set_small_cost(Menu::pizzas[i+1].get_small_cost());
        Menu::pizzas[i+1].set_small_cost(tmp2);

        tmp2 = Menu::pizzas[i].get_medium_cost();
        Menu::pizzas[i].set_medium_cost(Menu::pizzas[i+1].get_medium_cost());
        Menu::pizzas[i+1].set_medium_cost(tmp2);

        tmp2 = Menu::pizzas[i].get_large_cost();
        Menu::pizzas[i].set_large_cost(Menu::pizzas[i+1].get_large_cost());
        Menu::pizzas[i+1].set_large_cost(tmp2);

        tmp2 = Menu::pizzas[i].get_num_ingredients();
       	Menu::pizzas[i].set_num_ingredients(Menu::pizzas[i+1].get_num_ingredients());
       	Menu::pizzas[i+1].set_num_ingredients(tmp2);

       	string tmp1 = Menu::pizzas[i].get_name();
       	Menu::pizzas[i].set_name(Menu::pizzas[i+1].get_name());
       	Menu::pizzas[i+1].set_name(tmp1);

       	string * tmp = Menu::pizzas[i].get_ingredients();
       	Menu::pizzas[i].set_ingredients(Menu::pizzas[i+1].get_ingredients());
       	Menu::pizzas[i+1].set_ingredients(tmp);
}
//function: search_pizza_by_cost
//description: function to search pizza by cost and size
//parameters: n/a
//pre: user selected this funciton
//post: pizza list is printed out
//******************************************************************
void Menu:: search_pizza_by_cost(){
       	string size = ErrorHandlingSize("Would you like to search for Small (S), Medium (M), or Large (L)? ", "Pizza Size does not exit, please re-enter:");
	for (int j = 0; j < Menu::get_num_pizzas(); j++){
		for (int i = 0; i < Menu::get_num_pizzas() - 1; i++){
                	if ((size == "S") && (Menu::pizzas[i].get_small_cost() > Menu::pizzas[i+1].get_small_cost()))
                		swap_data(i);
                	if ((size == "M") && (Menu::pizzas[i].get_medium_cost() > Menu::pizzas[i+1].get_medium_cost()))
                		swap_data(i);
                	if ((size == "L") && (Menu::pizzas[i].get_large_cost() > Menu::pizzas[i+1].get_large_cost()))
                		swap_data(i);
		}
        }

        string price = ErrorHandlingInt("What is the Maximum Price? ", "What is the Maximum Price need to be a number, please re-enter:");
	for (int i = 0; i < Menu::get_num_pizzas(); i++){

               if (((size == "S") && (Menu::pizzas[i].get_small_cost() < get_int(price))) ||
                    ((size == "M") && (Menu::pizzas[i].get_medium_cost() < get_int(price))) ||
                    ((size == "L") && (Menu::pizzas[i].get_large_cost() < get_int(price)))) {
        	        cout << " " << Menu::pizzas[i].get_name() << " " << Menu::pizzas[i].get_small_cost()
                             << " " << Menu::pizzas[i].get_medium_cost() << " " << Menu::pizzas[i].get_large_cost()
                             << " " << Menu::pizzas[i].get_num_ingredients();

                        string * ingredients_tmp = Menu::pizzas[i].get_ingredients();
		        for (int j = 0; j <  Menu::pizzas[i].get_num_ingredients(); j++){
        		        cout << " " << ingredients_tmp[j];
		        }
        	        cout << endl;
	        }
	}
}


//function: ErrorHandlingYesNo2 and ErrorHandlingYesNo
//description: error handles user inputs valid
//parameters: checks string (ignore the double i was lazy to fix)
//pre: asks user to input
//post: reprompts
//******************************************************************
string ErrorHandlingYesNo2(string tmp, string tmp1) {
        string tmp2;
        do {
       		tmp2 = prompt_input(tmp);
                if (!((tmp2 == "No") || (tmp2 == "Yes")))
                   	cout << endl << tmp1 << endl;
	} while (!((tmp2 == "Yes") || (tmp2 == "No")));
	
	return tmp2;
}

string ErrorHandlingYesNo(string tmp, string tmp1) {
        string tmp2;
        do {
       		tmp2 = prompt_input(tmp);
                if (!((tmp2 == "S") || (tmp2 == "M") ||(tmp2 == "L")))
                   	cout << endl << tmp1 << endl;
	} while (!((tmp2 == "S") || (tmp2 == "M") ||(tmp2 == "L")));
	
	return tmp2;
}

//function: search_pizza_by_ingredients_to_include
//description: sorts pizza by ingredients customer likes
//parameters: n/a
//pre: user wants to include items
//post: pizzas are printed out to the user
//******************************************************************
void Menu:: search_pizza_by_ingredients_to_include(){
        int count = 0;
	string *Ingredients = new string[10];
        do {
		Ingredients[count++] = prompt_input("What item would you like to include? ");
		if (ErrorHandlingYesNo2("Do you want to include another item (Yes/No)? ", "Input must be Yes or No, please re-enter:") == "No") {
			if (ErrorHandlingYesNo2("Do you want to exclude item (Yes/No)? ", "Input must be Yes or No, please re-enter:") == "Yes") {
                        	search_pizza_by_ingredients_to_exclude();
                        	break;
                        }
       			cout << endl << "Here are the pizzas we found:" << endl;

			for (int i = 0; i < Menu::get_num_pizzas(); i++){
        			int k, found = 0;
                		string * ingredients_tmp = Menu::pizzas[i].get_ingredients();
				for (int j = 0; j < Menu::pizzas[i].get_num_ingredients(); j++){
					for (k = 0; k < count; k++){
						if (Ingredients[k] == ingredients_tmp[j])
                                               		found++;
					}
				}
	       			if (found == k) {
					cout << Menu::pizzas[i].get_name() << " " << Menu::pizzas[i].get_small_cost() << " "
					<< Menu::pizzas[i].get_medium_cost() << " " << Menu::pizzas[i].get_large_cost() << " "
                                             << Menu::pizzas[i].get_num_ingredients();
					for (int j = 0; j < Menu::pizzas[i].get_num_ingredients(); j++){
						cout << " " << ingredients_tmp[j];
             				}
               			        cout << endl;
                                }
			}
                       	break;
  	        }
	} while (1);
	delete [] Ingredients;
}
//function: search_pizza_by_ingredients_to_exclude
//description: sorts pizza by ingredients customer dislikes
//parameters: n/a
//pre: user wants to include items
//post: pizzas are printed out to the user
//******************************************************************
void Menu:: search_pizza_by_ingredients_to_exclude(){
        int count = 0;
	string *Exgredients = new string[10];
        do {
		Exgredients[count++] = prompt_input("What item would you like to exclude? ");

		if (ErrorHandlingYesNo2("Do you want to exclude another item (Yes/No)? ", "Input must be Yes or No, please re-enter:") == "No") {
			if (ErrorHandlingYesNo2("Do you want to include item (Yes/No)? ", "Input must be Yes or No, please re-enter:") == "Yes") {
                        	search_pizza_by_ingredients_to_include();
                        	break;
                        }
       			cout << "Here are the pizzas we found:" << endl;

			for (int i = 0; i < Menu::get_num_pizzas(); i++){
        			int k, found = 1;
                		string * ingredients_tmp = Menu::pizzas[i].get_ingredients();
				for (int j = 0; j < Menu::pizzas[i].get_num_ingredients(); j++){
					for (k = 0; k < count; k++){
						if (Exgredients[k] == ingredients_tmp[j])
                                               		found = 0;
					}
				}
	       			if (found) {
					cout << Menu::pizzas[i].get_name() << " " << Menu::pizzas[i].get_small_cost() << " "
					<< Menu::pizzas[i].get_medium_cost() << " " << Menu::pizzas[i].get_large_cost() << " "
                                             << Menu::pizzas[i].get_num_ingredients();
					for (int j = 0; j < Menu::pizzas[i].get_num_ingredients(); j++){
						cout << " " << ingredients_tmp[j];
             				}
               			        cout << endl;
                                }
			}
                       	break;
  	        }
	} while (1);
	delete [] Exgredients;
}
//menu destructor
//******************************************************************
Menu :: ~Menu(){
	delete [] pizzas;
}


