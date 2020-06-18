#include <iostream>
#include "thrower.h"
using namespace std;


Thrower::Thrower(){
	name = "Thr";
	armor = 1;
	location = 0;
	food_cost = 2;
}

Thrower::Thrower(const Thrower& copy){
	name = copy.name;
	armor = copy.armor;
	location = copy.location;
	food_cost = copy.food_cost;

}

const Thrower & Thrower:: operator = (const Thrower & copy){
	name = copy.name;
	armor = copy.armor;
	location = copy.location;
	food_cost = copy.food_cost;

	return *this;
}

Thrower:: ~Thrower(){

}

//function: thrower attack
//description: does nothing
//parameters:
//pre
//post:
void Thrower:: attack(vector <Ant> ant_array[10], vector <Bee> bee_array[10], int *total_row, int *bank, int i, int j){

}
void Thrower:: attack_thrower(){
	armor = armor -1;
}

string Thrower::get_name() const {
  return name;
}

int Thrower::get_armor() const {
  return armor;
}

int Thrower::get_food_cost() const {
  return food_cost;
}
