#include <iostream>
#include "ninja.h"
using namespace std;


Ninja::Ninja(){
	name = "Nin";
	armor = 1;
	location = 0;
	food_cost = 6;
}

Ninja::Ninja(const Ninja& copy){
	name = copy.name;
	armor = copy.armor;
	location = copy.location;
	food_cost = copy.food_cost;

}

const Ninja & Ninja:: operator = (const Ninja & copy){
	name = copy.name;
	armor = copy.armor;
	location = copy.location;
	food_cost = copy.food_cost;

	return *this;
}
//function: ninja attack
//description: does nothing
//parameters:
//pre
//post:
void Ninja:: attack(vector<Ant> [], vector<Bee> [], int *, int *, int,int){
	//nothing it gets called somewhere else because it gets called when bee passes by
}

Ninja:: ~Ninja(){

}


//getters____________________________________________________
string Ninja::get_name() const {
  return name;
}

int Ninja::get_armor() const {
  return armor;
}

int Ninja::get_food_cost() const {
  return food_cost;
}
