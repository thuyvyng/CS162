//name: thuyvy nguyen
//program: assignment 2 (pizza)
//date: 29 april 2018
//input: file and userinput
//output: pizzas and file
//file: driver.cpp


#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include <cmath>

#include "pizza.h"
#include "menu.h"
#include "restaurant.h"

using namespace std;


//function: prompt_input
//description: takes in input for ordering
//parameters: string input from user
//pre: user must have to be orompted for something
//post: returns
//******************************************************************
string prompt_input(string tmp) {
	string additems = "";
	cout << tmp;
	getline(cin,additems);

        return additems;
}
//GET_INT and IS_INT are reused functions to check for valid ints
//and to return strings as ints from cs161 assignment 3
//******************************************************************
int get_int(string bin){
	int res = 0;
	for (int i = 0; i < bin.length(); i++){
		int check = bin[i] - '0';
		int topower = int(bin.length()) -i -1;
		res = (int)((check*pow(10.0,topower)) + res);
	}
	return res;
}
bool is_int(string num){
	bool c_num = 0;
	int len = 0;
	int l = num.length();

	while(num[len] != '\0'){
		if(((num[len] >47) && (num[len] <58)) || (num[len] == 45)){
			len++;
		}
		else{
			break;
		}
		c_num = 1;
	}
	return c_num;
}
//****************************************************************

//function: get_total_lines
//description: reads file and return how long the file is
//parameters: the file
//pre: must have file
//post: return lengths of file
//******************************************************************
int get_total_lines(char* file) {
	ifstream input;
	input.open(file);
	string line;
	int total_employee = 0;
	while (getline(input, line)) {
        	total_employee++;
	}
	input.close();	                    // close the file
	
	return total_employee;
}
//function: ErrorHandlingInt
//description: error handles for ordering to make sure it is a valid int
//paramters: the order strings
//pre: user selected to order
//post: will reprompt until valid
//******************************************************************
string ErrorHandlingInt(string tmp, string tmp1) {
        string tmp2;
        do {
       		tmp2 = prompt_input(tmp);
                if (!is_int(tmp2))
                   	cout << endl << tmp1 << endl;
	} while (!is_int(tmp2));
	
	return tmp2;
}
//function: ErrorHandlingSize
//description: error handles to make sure user orders correctly
//parameters: takes in the size and price
//pre: user selected order by size
//post: will reprompt until valid
//******************************************************************
string ErrorHandlingSize(string tmp, string tmp1) {
        string tmp2;
        do {
       		tmp2 = prompt_input(tmp);
                if (!((tmp2 == "S") || (tmp2 == "M") ||(tmp2 == "L")))
                   	cout << endl << tmp1 << endl;
	} while (!((tmp2 == "S") || (tmp2 == "M") ||(tmp2 == "L")));
	
	return tmp2;
}
//function: employee_selection
//description: prints and error handles employee selection
//parameters: n/a
//pre: user wants to be an employee
//post: functions will run
//******************************************************************
int employee_selection(){
	string ans = "";

	do{
		cout << endl << "What would you like to do? " << endl;
		cout << "1. Change hours" << endl;
		cout << "2. View Orders" << endl;
		cout << "3. Remove Order" << endl;
		cout << "4. Add Item to Menu" << endl;
		cout << "5. Remove Item from Menu" << endl;
		cout << "6. View Menu" << endl;
		cout << "7. View Hours" << endl;
		cout << "8. View Address" << endl;
		cout << "9. View Phone" << endl;
		cout << "10. Log out" << endl;		
                
		cout << "Selection: " ;
                getline(cin,ans);
		cout << endl;
	}while ((get_int(ans) < 1) || (get_int(ans) > 10));
	
	return (get_int(ans));
}
//function:employee_selected
//description: will run corresponding functions based on users input
//parameters: n/a
//pre: user selected to be employee (and passed)
//post: functions will run
//******************************************************************
void Employee_Selected() {
	Restaurant empl;
	empl.get_employees();
        int done = 1;
        do {
        	switch (employee_selection()) {

        		case 1: empl.change_hours();		break;
        		case 2: empl.view_orders(); 		break;
        		case 3: empl.remove_orders(); 		break;
        		case 4: empl.add_to_menu(); 		break;
        		case 5: empl.remove_from_menu(); 	break;
        		case 6: empl.view_menu(); 		break;
        		case 7: empl.view_hours(); 		break;
        		case 8: empl.view_address(); 		break;
        		case 9: empl.view_phone(); 		break;
        		case 10: done = 0; 			break;
       	 	}
        } while (done);

}
//function: customer_selection
//description: prints and takes error handles input for menu
//parameters: n/a
//pre: user wants to be customer
//post: will either reprompt or move to next function
//******************************************************************
int customer_selection(){
	string ans = "";

	do{
		cout << endl << "What would you like to do? " << endl;
		cout << "1. View Menu" << endl;
		cout << "2. Search by Cost" << endl;
		cout << "3. Search by Ingredients" << endl;
		cout << "4. Place Order" << endl;
		cout << "5. View Hours" << endl;
		cout << "6. View Address" << endl;
		cout << "7. View Phone" << endl;
		cout << "8. Log out" << endl;

		cout << "Selection: " ;
                getline(cin,ans);
		cout << endl;
	}while ((get_int(ans) < 1) || (get_int(ans) > 10));
	
	return (get_int(ans));
}

//function: customer_selected
//description: runs the program based on customer selection
//parameters: n/a
//pre: user decided to be a customer
//post: the selection runs
//******************************************************************
void Customer_Selected() {
	Restaurant cust;
        int done = 1;
        do {
        	switch (customer_selection()) {
        		case 1: cust.view_menu();		break;
        		case 2: cust.search_by_cost(); 		break;
        		case 3: cust.search_by_ingredients(); 	break;
        		case 4: cust.place_orders(); 		break;
        		case 5: cust.view_hours(); 		break;
        		case 6: cust.view_address(); 		break;
        		case 7: cust.view_phone(); 		break;
        		case 8: done = 0; 			break;
       	 	}
        } while (done);
}

//******************************************************************
int main(){
	string ans = "";
	do{
		cout << "Welcome!" << endl << endl;
		cout << "Are you a customer (C) or employee (E) or would you like to quit (Q)? ";
		getline(cin,ans);
		if (ans[0] == 'C' && ans.length() == 1) {
			Customer_Selected();
		}
 		else if (ans[0] == 'E' && ans.length() == 1) {
			Employee_Selected();
		}
 		else if (ans[0] == 'Q' && ans.length() == 1) {
			break;
		}
	}while (1);


	return 0;
}
