#include <iostream>
#include "bodyguard.h"
using namespace std;

//function: body guard default constructor
//description: bodyguard default constructor
//parameters: none
//pre: nothing made
//post: object made
Bodyguard::Bodyguard(){
	name = "Bod";
	armor = 2;
	location = 0;
	food_cost = 4;
}
//function: copy constructor for bd
//description: copies values for the bd
//parameters: none
//pre: cnot copied over
//post: copied over
Bodyguard::Bodyguard(const Bodyguard& copy){
	name = copy.name;
	armor = copy.armor;
	location = copy.location;
	food_cost = copy.food_cost;
}

//function: aoo for bd
//description: copies values for the bd
//parameters: none
//pre: cnot copied over
//post: copied over
const Bodyguard & Bodyguard:: operator = (const Bodyguard & copy){
	name = copy.name;
	armor = copy.armor;
	location = copy.location;
	food_cost = copy.food_cost;

	return *this;
}
//destructor,not used
Bodyguard:: ~Bodyguard(){

}
//function: attack function for bodyguard
//description: doesnt attack so its empty
//parameters: none
//pre: cnot copied over
//post: copied over
void Bodyguard:: attack(vector <Ant> ant_array[10], vector <Bee> bee_array[10], int *total_row, int *bank, int i, int j){
//nothing
}
// getters_________________________________________________________________
string Bodyguard::get_name() const {
  return name;
}

int Bodyguard::get_armor() const {
  return armor;
}

int Bodyguard::get_food_cost() const {
  return food_cost;
}
