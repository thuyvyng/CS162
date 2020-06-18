#include <iostream>
#include "shortthrower.h"
using namespace std;


ShortThrower::ShortThrower(){
	name = "Sho";
	armor = 1;
	location = 0;
	food_cost = 3;
}

ShortThrower::ShortThrower(const ShortThrower& copy){
	name = copy.name;
	armor = copy.armor;
	location = copy.location;
	food_cost = copy.food_cost;

}

const ShortThrower & ShortThrower:: operator = (const ShortThrower & copy){
	name = copy.name;
	armor = copy.armor;
	location = copy.location;
	food_cost = copy.food_cost;

	return *this;
}
//function: shortthrower attack
//description: does nothing
//parameters:
//pre
//post:
void ShortThrower::attack(vector <Ant> ant_array[10], vector <Bee> bee_array[10], int *total_row, int *bank, int i, int j){
	ShortThrower s;
//		cout << "WHAT THE SHIT " << endl;
	for (int x = i; x < i +3; x++){
		for (int o = 0; o < *total_row+1; o++){
				if ((bee_array[x][o].name == "bee") && (bee_array[x][o].armor >0))
					bee_array[x][o].armor = bee_array[x][o].armor -1;
			}
		}
}

ShortThrower:: ~ShortThrower(){

}
//getters_________________---
string ShortThrower::get_name() const {
  return name;
}

int ShortThrower::get_armor() const {
  return armor;
}

int ShortThrower::get_food_cost() const {
  return food_cost;
}
