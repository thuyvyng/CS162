#include <iostream>
#include "fire.h"
using namespace std;

//function: constructor for fire
//description: constructor for fire
//parameters: none
//pre: no object
//post: object
Fire::Fire(){
	name = "Fir";
	armor = 1;
	location = 0;
	food_cost = 4;
}
//function: copy constructor for fire
//description: copies values for the fire
//parameters: none
//pre: cnot copied over
//post: copied over
Fire::Fire(const Fire& copy){
	name = copy.name;
	armor = copy.armor;
	location = copy.location;
	food_cost = copy.food_cost;

}
//function: aoo for fire
//description: copies values for the bee
//parameters: none
//pre: cnot copied over
//post: copied over
const Fire& Fire:: operator = (const Fire & copy){
	name = copy.name;
	armor = copy.armor;
	location = copy.location;
	food_cost = copy.food_cost;

	return *this;
}
//does nothing as  it attacks when it does
void Fire::attack(vector<Ant> [], vector<Bee> [], int *, int *,int,int){

}

//destructor not used
Fire:: ~Fire(){

}
//gettters-____----
string Fire::get_name() const {
  return name;
}

int Fire::get_armor() const {
  return armor;
}

int Fire::get_food_cost() const {
  return food_cost;
}
