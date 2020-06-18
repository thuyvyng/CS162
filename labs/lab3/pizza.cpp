#include "pizza.h"
#include<string>

using namespace std;


Pizza::Pizza(){
	
	cout << "idk anymore" << endl;


	name = "default";
	small_cost = 5;
	medium_cost = 7;
	large_cost = 9;
	num_ingredients = 0;	
	ingredients = NULL;	
	
} 

Pizza::Pizza(const Pizza& copy){
	
	cout << "1" << endl;

	name = copy.name;
	small_cost = copy.small_cost;
	medium_cost = copy.medium_cost;
	large_cost = copy.large_cost;
	num_ingredients = copy.num_ingredients;
	if (num_ingredients == 0)
		ingredients = NULL;
	else{
		ingredients = new string[num_ingredients];
		for (int i = 0; i < num_ingredients; i++){
			ingredients[i] = copy.ingredients[i];
		}
	}
}

const Pizza& Pizza:: operator = (const Pizza& copy){	
	
	cout << "3" << endl;
	name = copy.name;
	small_cost = copy.small_cost;
	medium_cost = copy.medium_cost;
	large_cost = copy.large_cost;
	num_ingredients = copy.num_ingredients;
	cout << "whatever" << endl;

	if (ingredients != NULL)
		delete [] ingredients;
	if (num_ingredients == 0)
		ingredients = NULL;
	else{
		ingredients = new string[num_ingredients];
		for (int i = 0; i < num_ingredients; i++){
			ingredients[i] = copy.ingredients[i];
		}
	}
	cout << "sup" << endl;
	return *this;
}

string Pizza::get_name()const{
	return name;

}

int Pizza::get_small_cost()const{
	return small_cost;
}

int Pizza::get_medium_cost()const{
	return medium_cost;
}

int Pizza::get_large_cost()const{
	return large_cost;
}

int Pizza::get_num_ingredients()const{
	return num_ingredients;
}

string * Pizza::get_ingredients()const{
	return ingredients;

}

void Pizza:: set_name(string n){
	name = n;
}

void Pizza::set_small_cost(int s){
	small_cost = s;
}


void Pizza::set_medium_cost(int m){
	medium_cost = m;
}


void Pizza::set_large_cost(int l){
	large_cost = l;
}

void Pizza::set_num_ingredients(int ni){
	num_ingredients = ni;
}

void Pizza::set_ingredients(string * arr){
	ingredients = arr;
}

Pizza :: ~ Pizza(){
	delete [] ingredients;

}










