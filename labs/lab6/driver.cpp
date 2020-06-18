#include <iostream>
#include "properties.h"
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef PROPERTIES_H
#define PROPERTIES_H
using namespace std;


bool winner(int * bank_account){
	bool end = 0;

	if ( (*bank_account > 1000000) || (*bank_account < 0)){
		end  = 1;
	}

	return end;
}

void end_statement(int * bank_account){
	if (*bank_account > 1000000){
		cout << "Congrats! You have accumulated over a million dollars." << endl;

	}
	else if (*bank_account < 0){
		cout << "Yikes! You've gone bankrupt. Better luck next time." << endl;
	}

}

int main(){
	srand(time(NULL));

	int * bank_account;
	int x = 500000;
	bank_account = &x;

	//create arrays of potential properties
	
	House * potential_house = new House[3];
	Apartment * potential_apartment	= new Apartment[3];
	Business * potential_business = new Business[3];

	//populate_potential_properties(potential_house, potential_apartment, potential_business, 3);
	
	 		
	do{
		cout << "Your bank account balance: " << *bank_account << endl;
		cin >> x;

	} while ( winner(bank_account) == 0);

	end_statement(bank_account);

	return 0;
}



# endif
