#include <iostream>
#include "ant.h"
using namespace std;

//function: ant constructor
//description: ant constructor
//parameters: none
//pre: creates object
//post: object is there
Ant::Ant(){
	name = "ANT";
	armor = 1;
	location = 0;
	food_cost = 2;
}

//function: ant copy constructor
//description: ant copy constructor
//parameters: none
//pre: not copied
//post: copy
Ant::Ant(const Ant& copy){
	name = copy.name;
	armor = copy.armor;
	location = copy.location;
	food_cost = copy.food_cost;
}
//function: parent attack function
//description: does nothing
//parameters: none
//pre: does nothing
//post: does nothing
void Ant::attack(){

}
//function: ant assignment overload operator
//description: ass
//parameters:
//pre:
//post:
const Ant & Ant:: operator = (const Ant & copy){
	name = copy.name;
	armor = copy.armor;
	location = copy.location;
	food_cost = copy.food_cost;

	return *this;
}
//function: ant destructor
//description:
//parameters:
//pre:
//post:
Ant:: ~Ant(){

}
