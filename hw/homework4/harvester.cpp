#include <iostream>
#include "harvester.h"
using namespace std;

//function: constructor for the harvester
//description: constructor for the harvester
//parameters: none
//pre: no obj
//post: obj
Harvester::Harvester(){
	name = "Har";
	armor = 1;
	location = 0;
	food_cost = 2;
}
//function: copy constructor for har
//description: copies values for the har
//parameters: none
//pre: cnot copied over
//post: copied over
Harvester::Harvester(const Harvester& copy){
	name = copy.name;
	armor = copy.armor;
	location = copy.location;
	food_cost = copy.food_cost;

}
//function: aoo for har
//description: copies values for the har
//parameters: none
//pre: cnot copied over
//post: copied over
const Harvester & Harvester:: operator = (const Harvester & copy){
	name = copy.name;
	armor = copy.armor;
	location = copy.location;
	food_cost = copy.food_cost;

	return *this;
}
//function: attack function for harvester
//description: attack function for harvester
//parameters: none
//pre: cnot copied over
//post: copied over
int Harvester::attack_Harvester(){
	location = 1;
	return location;
}

//destructor not used
Harvester:: ~Harvester(){

}
//getters______________________________---
string Harvester::get_name() const {
  return name;
}

int Harvester::get_armor() const {
  return armor;
}

int Harvester::get_food_cost() const {
  return food_cost;
}
