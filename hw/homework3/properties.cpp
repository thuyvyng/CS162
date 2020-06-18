#include <iostream>
#include <string>
#include <stdlib.h>
#include "properties.h"

using namespace std;

extern string property_location();
extern int property_mortgage();
extern int property_h();
extern int property_a();
extern int property_b();
extern string property_size();

//function: property constructor
//******************************************************************
Property::Property(){
	residents = NULL;
}


Property::Property(int prop_value, int tenants){
	property_value = prop_value;
	num_tenants = tenants;	

}



//function: proeprty copy constructor
//******************************************************************
Property:: Property(const Property & copy){
	property_value = copy.property_value;
	location = copy.location;
	mortgage = copy.mortgage;
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
//function: property assignment overload
//******************************************************************
const Property & Property:: operator= (const Property& copy){
	property_value = copy.property_value;
	location = copy.location;
	mortgage = copy.mortgage;
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

//house constructor

House::House():Property() {
	property_value = property_h();
	location = property_location();
	mortgage = property_mortgage();
	property_tax = 1.5;
	num_tenants = 1;

        tenants * tenants_db = new tenants[num_tenants];
        for (int i = 0; i < num_tenants; i++) {
		tenants_db[i].score = rand()%5;
		tenants_db[i].monthly_budget = 500 + rand()%4500;
	}

	residents = tenants_db;
	tenants_db = NULL;
	delete [] tenants_db;
};

//function: house copy constructor
//******************************************************************
House:: House(const House & copy):Property(copy){
	property_value = copy.property_value;
	location = copy.location;
	mortgage = copy.mortgage;
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
//function: house assignment overload
//******************************************************************
const House & House:: operator= (const House& other){
	Property::operator = (other);
}
Apartment::Apartment():Property(){
	property_value = property_a();
	location = property_location();
	mortgage = property_mortgage();
	property_tax = 1.5;
	num_tenants = (rand()% 9) + 1;

        tenants * tenants_db = new tenants[num_tenants];
        for (int i = 0; i < num_tenants; i++) {
		tenants_db[i].score = rand()%5;
		tenants_db[i].monthly_budget = 500 + rand()%4500;
	}
	residents = tenants_db;
	tenants_db = NULL;
	delete [] tenants_db;
};

//function: apartment copy constructor
//******************************************************************
Apartment:: Apartment(const Apartment & copy): Property(copy){
	property_value = copy.property_value;
	location = copy.location;
	mortgage = copy.mortgage;
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
//function: apartment  assignment overload
//******************************************************************
const Apartment & Apartment:: operator= (const Apartment& other){
	Property:: operator = (other);
}

//business copy construtor
Business::Business():Property(){
	property_value = property_b();
	location = property_location();
	mortgage = property_mortgage();
	property_tax = 1.5;
	num_tenants = (rand()% 4) + 1;
	size = property_size();

        tenants * tenants_db = new tenants[num_tenants];
        for (int i = 0; i < num_tenants; i++) {
		tenants_db[i].score = rand()%5;
		tenants_db[i].monthly_budget = 2000 + rand()%8000;
	}
	residents = tenants_db;
	tenants_db = NULL;
	delete [] tenants_db;
};

//function: business copy constructor
//******************************************************************
Business:: Business(const Business & copy): Property(copy){
	property_value = copy.property_value;
	location = copy.location;
	mortgage = copy.mortgage;
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
//function: business assignment overload
//******************************************************************
const Business & Business:: operator= (const Business& other){
	Property:: operator = (other);
	
	property_value = copy.property_value;
	location = copy.location;
	mortgage = copy.mortgage;
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

	return *this;*/
}

//function: populate_BLANK 
//description: populates array with given info
//parameters: house array and at which index
//pre: index is empty
//post: index is not empty
void populate_house(House * house_db, int index){
	house_db[index].property_value = property_h();
	house_db[index].location = property_location();
	house_db[index].mortgage = property_mortgage();
	house_db[index].property_tax = 1.5;
	house_db[index].num_tenants = 1;
};

void populate_apartment(Apartment * apartment_db, int index){
	apartment_db[index].property_value = property_a();
	apartment_db[index].location = property_location();
	apartment_db[index].mortgage = property_mortgage();
	apartment_db[index].property_tax = 1.5;
	apartment_db[index].num_tenants = (rand()% 9) + 1;
};

void populate_business(Business * business_db, int index){
	business_db[index].property_value = property_b();
	business_db[index].location = property_location();
	business_db[index].mortgage = property_mortgage();
	business_db[index].property_tax = 1.5;
	business_db[index].num_tenants = (rand()% 4) + 1;
	business_db[index].size = property_size();
};
//********************************************************

//accessors for property
int Property:: get_property_value()const{
	return property_value;
}

int Property:: get_num_tenants()const{
	return num_tenants;
}

string Property:: get_location()const{
	return location;
}

float Property:: get_property_tax() const{
	return property_tax;
}

int Property:: get_mortgage() const{
	return mortgage;
}

tenants * Property:: get_residents()const{
	return residents;
}

//mutators for property

void Property:: set_property_value(int p){
	property_value = p;
}

void Property:: set_location(string s){
	location = s;
}

void Property:: set_mortgage(int m){
	mortgage = m;
}

void Property:: set_property_tax( float pt){
	property_tax = pt;
}

void Property::set_residents(tenants * r){
	residents = r;
}

//function: property destructor
Property:: ~Property(){
	delete [] residents;

}

House:: ~House(){
//	residents = NULL;
	delete [] residents;
//	residents = NULL;
}


Apartment:: ~ Apartment(){
//	residents = NULL;
	delete [] residents;
//	residents = NULL;
}

Business:: ~ Business(){
//	residents = NULL;
	delete [] residents;
//	residents = NULL;
}

bool operator < (const Property& a, const Property& b){
	if ((a.get_property_value() < b.get_property_value()) && (a.get_num_tenants() < b.get_num_tenants()))
		return true;
	return false;
		
} 

bool operator > (const Property& a, const Property& b){
	if ((a.get_property_value() > b.get_property_value()) && (a.get_num_tenants() > b.get_num_tenants()))
		return true;
	return false;
		
} 
