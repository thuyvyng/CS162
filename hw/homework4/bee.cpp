#include <iostream>
#include <vector>
#include "bee.h"

using namespace std;
//function: bee constructor
//description: creates bee object
//parameters: none
//pre: no object
//post: object made
Bee::Bee(){
	name = "bee";
	armor = 3;
	location = 9;

}
//function: copy constructor for bee
//description: copies values for the bee
//parameters: none
//pre: cnot copied over
//post: copied over
Bee::Bee(const Bee & copy){
	armor = copy.armor;
	location = copy.location;


}
//function: assignment overload for Bee
//description: copies values overs for the Bee
//parameters: none
//pre: none
//post: copied over
const Bee & Bee:: operator = (const Bee & copy){
	armor = copy.armor;
	location = copy.location;

	return *this;

}
//destructor but its not used
Bee:: ~Bee(){

}
