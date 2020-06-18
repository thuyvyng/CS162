#include "pizza.h"
#include "menu.h"
#include "restaurant.h"
#include <string>
#include <stdlib.h>
#include <cmath>
using namespace std;


bool is_valid(string num){
	bool valid = 0;
	int i = 0;

	if (num.length() == 1){
		if((num[i] > 47) && (num[i] < 51)){
			valid = 1;
		}
	}
	
	return valid;
}

int get_int(string bin){
	int res = 0;
	for (int i = 0; i <bin.length(); i++){
		int check = bin[i] - '0';
		int topower = int(bin.length()) -i -1;
		res = (int)((check*pow(10.0,topower)) + res);
	}

	return res;

}

int main(){
//	Pizza p;
//	cout << p.get_small_cost() << endl;
//	p.set_small_cost(13);
		
//	cout << p.get_small_cost() << endl;
//	Menu m;
//	Restaurant r;	
//	Pizza p;
//	p.set_name("PIZZA YAY");
//	p.set_num_ingredients(5);
//
//	Pizza f;
	
//	cout << p.get_name() << endl;
//	cout << f.get_name() << endl;	
//	f = p;
	//cout << f.get_name();

	string ans = "";
	do{
		cout << "Hello!" << endl << "Do you want to continue as a customer(1) or as an employee(3)? Or would you like to quit (0)";
		cout << endl << endl << "Enter the corresponding option to continue: ";
		getline(cin,ans);		
		//cout << ans << endl << endl; 
	} while (is_valid(ans) == 0);
	
	int selection = get_int(ans);



	return 0;
}
