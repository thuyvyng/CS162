#include <iostream>
#include "wall.h"
using namespace std;


Wall::Wall(){
	name = "Wal";
	armor = 4;
	location = 0;
	food_cost = 4;
}

Wall::Wall(const Wall& copy){
	name = copy.name;
	armor = copy.armor;
	location = copy.location;
	food_cost = copy.food_cost;

}
//function: wall attack
//description: does nothing
//parameters:
//pre
//post:
void Wall:: attack(vector <Ant> ant_array[10], vector <Bee> bee_array[10], int *total_row, int *bank, int i, int j){
	//nothing it doesnt attack
}

const Wall & Wall:: operator = (const Wall & copy){
	name = copy.name;
	armor = copy.armor;
	location = copy.location;
	food_cost = copy.food_cost;

	return *this;
}

Wall:: ~Wall(){

}


//getters__________________________
string Wall::get_name() const {
  return name;
}

int Wall::get_armor() const {
  return armor;
}

int Wall::get_food_cost() const {
  return food_cost;
}
