#include <iostream>
#include "longthrower.h"
using namespace std;

//function: constructor for lon
//description: constructor for lon
//parameters: none
//pre: cnot copied over
//post: copied over
LongThrower::LongThrower(){
	name = "Lon";
	armor = 1;
	location = 0;
	food_cost = 3;
}

//function: copy constructor for lon
//description: copies values for the lon
//parameters: none
//pre: cnot copied over
//post: copied over
LongThrower::LongThrower(const LongThrower& copy){
	name = copy.name;
	armor = copy.armor;
	location = copy.location;
	food_cost = copy.food_cost;

}
//function: aoo for lon
//description: copies values for the bee
//parameters: none
//pre: cnot copied over
//post: copied over
const LongThrower & LongThrower:: operator = (const LongThrower & copy){
	name = copy.name;
	armor = copy.armor;
	location = copy.location;
	food_cost = copy.food_cost;

	return *this;
}
//destructor not used
LongThrower:: ~LongThrower(){

}

//function: longrthrower attack
//description: attacks from a distance
//parameters:
//pre
//post:
void LongThrower::attack(vector <Ant> ant_array[10], vector <Bee> bee_array[10], int *total_row, int *bank, int i, int j){

			LongThrower t;

			int hold = 12, b = 0, small = 0, u = 12, s = 0;
			for (int x = i+4; x < 10; x++){
				for (int w = 0; w < *total_row+1; w++){
					if (bee_array[x][w].name == "bee"){

						hold = x;
						b = 1;
						break;
					}
				if (b == 1)
					break;
				}
			}


		if (hold < 11){
			for (int t = 0; t < *total_row+1; t++){
				if (bee_array[hold][t].armor > 0){
					bee_array[hold][t].armor = bee_array[hold][t].armor -1;
				}
			}
		}

}
//getters__________________________________________________
string LongThrower::get_name() const {
  return name;
}

int LongThrower::get_armor() const {
  return armor;
}

int LongThrower::get_food_cost() const {
  return food_cost;
}
