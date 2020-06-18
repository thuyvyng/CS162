#include <iostream>
#include <string>
#include <stdlib.h>
#include "insect.h"

using namespace std;

//function: constructor for insect
//description: creates insect
//parameters: none
//pre: no obj
//post: obj
Insect::Insect(){
	//armor = 1;
	//location = 0;

}
//function: copy constructor for insect
//description: copies values for the insect
//parameters: none
//pre: cnot copied over
//post: copied over
Insect::Insect(const Insect & copy){
	armor = copy.armor;
	location = copy.location;
}
//function: aoo for insect
//description: aoo for insect
//parameters: none
//pre: cnot copied over
//post: copied over
const Insect & Insect:: operator = (const Insect & copy){
	armor = copy.location;
	location = copy.location;

	return *this;

}
//not used
Insect:: ~Insect(){

}
