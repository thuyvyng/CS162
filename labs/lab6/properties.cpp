#include <iostream>
#include <string>
#include "properties.h"

using namespace std;


Property::Property(){
	property_value = 0;
	location = "somewhere";
	mortage = 0;
	property_tax = 1.5;
	num_tenants = 0;
	residents = NULL;
}

House::House():Property{

};


Apartment::Apartment():Property{

};

Business::Business():Property{

};

Property:: Property(const Property & copy){
	property_value = copy.property_value;
	location = copy.location;
	mortage = copy.mortage;
	property_tax = copy.property_tax;

	if (num_tenants == 0)
		residents == NULL;
	else{
		residents = new tenants[num_tenants];
		for (int i = 0; i < num_tenants; i++){
			residents[i] = copy.residents[i];
		}
	}
}

const Property & Property:: operator= (const Property& copy){
	property_value = copy.property_value;
	location = copy.location;
	mortage = copy.mortage;
	property_tax = copy.property_tax;
	if (residents != NULL)
		delete [] residents;
	if (num_tenants == 0)
		residents == NULL;
	else{
		residents = new tenants[num_tenants];
		for (int i = 0; i < num_tenants; i++){
			residents[i] = copy.residents[i];

		}
	}

	return *this;
}


//accessors
int Property:: get_property_value()const{
	return property_value;
}

string Property:: get_location()const{
	return location;
}

float Property:: get_property_tax() const{
	return property_tax;
}

int Property:: get_mortage() const{
	return mortage;
}

tenants * Property:: get_residents()const{
	return residents;
}

//mutators

void Property:: set_property_value(int p){
	property_value = p;
}

void Property:: set_location(string s){
	location = s;
}

void Property:: set_mortage(int m){
	mortage = m;
}

void Property:: set_property_tax( float pt){
	property_tax = pt;
}

void Property::set_residents(tenants * r){
	residents = r;
}

//destructor
Property:: ~Property(){
	delete [] residents;

}
