#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#include "properties.h"
#include "functions.h"
#include "players.h"
#include "random_event.h"

using namespace std;

extern void populate_house(House * house_db, int index);
extern void populate_apartment(Apartment * apartment_db, int index);
extern void populate_business(Business * business_db, int index);

//******************************************************************
//function: end_statement
//description: win/lose statement
//parameters: checks the user's bank_statement
//pre:user must be still player
//post: game ends
void end_statement(PlayGame * player_db){
	if (player_db[0].bank_balance > 1000000){
		cout << "Congrats! You have accumulated over a million dollars." << endl;

	}
	else {
		cout << "Yikes! You've gone bankrupt. Better luck next time." << endl;
	}

}

//function: prompt_input
//description: takes in input for ordering
//parameters: string input from user
//pre: user must have to be orompted for something
//post: returns
//******************************************************************
string prompt_input(string tmp) {
	string additems = "";
	cout << tmp;
	getline(cin,additems);

        return additems;
}
//these have been reused from past assignments
//******************************************************************
int get_int(string bin){
	int res = 0;
	for (int i = 0; i < bin.length(); i++){
		int check = bin[i] - '0';
		int topower = int(bin.length()) -i -1;
		res = (int)((check*pow(10.0,topower)) + res);
	}
	return res;
}

bool is_int(string num){
	bool c_num = 0;
	int len = 0;
	int l = num.length();

	while(num[len] != '\0'){
		if(((num[len] >47) && (num[len] <58)) || (num[len] == 45)){
			len++;
		}
		else{
			break;
		}
		c_num = 1;
	}
	return c_num;
}

string ErrorHandlingInt(string tmp, string tmp1) {
        string tmp2;
        do {
       		tmp2 = prompt_input(tmp);
                if (!is_int(tmp2))
                   	cout << endl << tmp1 << endl;
	} while (!is_int(tmp2));
	
	return tmp2;
}

string ErrorHandlingEntry(string tmp, string tmp1) {
        string tmp2;
        do {
       		tmp2 = prompt_input(tmp);
                if (tmp2 == "")
                   	cout << endl << tmp1 << endl;
               	else
                   	break;
	} while (1);

	return tmp2;
}

int ErrorHandlingRange(string tmp, int tmp1, int tmp2) {
	string ans = "";
	do{
	       cout << tmp ;
               getline(cin,ans);
	}while ((get_int(ans) < tmp1) || (get_int(ans) > tmp2));

	return get_int(ans);
}

//******************************************************************
//function: selectAvailableProperty
//description: prints out possible properties
//parameters: all of the possible properties arrays and an array of the ones that will be given to the user
//pre: user wants to buy a property
//post: user either buys or doesnt buy a proepery but its printed out
int SelectAvailableProperty(House * house_db, Apartment * apartment_db, Business * business_db, int x[3]) {
	cout << "Available Properties: " << endl;
	
	for (int i = 0; i < 3; i++) {
//cout << "random value = " << x[i] << " x%3 = " << x[i]%3 << endl;
		if (x[i] < 3) {
                	cout << i+1 << ": House cost: " << house_db[x[i]].property_value
                	     << " location " << house_db[x[i]].location
                	     << " mortgage " << house_db[x[i]].mortgage
                	     << " num_tenants " << house_db[x[i]].num_tenants << endl;
		} else if (x[i] < 6) {
                	cout << i+1 << ": Apartment cost: " << apartment_db[x[i]%3].property_value
                	     << " location " << apartment_db[x[i]%3].location
                	     << " mortgage " << apartment_db[x[i]%3].mortgage
                	     << " num_tenants " << apartment_db[x[i]%3].num_tenants << endl;
		} else {
                	cout << i+1 << ": Business cost: " << business_db[x[i]%3].property_value
                	     << " location " << business_db[x[i]%3].location
                	     << " mortgage " << business_db[x[i]%3].mortgage
                	     << " num_tenants " << business_db[x[i]%3].num_tenants
                	     << " size " << business_db[x[i]%3].size << endl;
                }
	}

	return(ErrorHandlingRange("Which Property you want to buy (1-4, 4-do nothing)? ", 1, 4) - 1);
}
//function: reassignpreviousinfo
//description: reassigns old info to new properties array
//		when the user buys more proerty
//parameters: how many properties the user owns the player db, and the other player db
//pre: user buys property
//post: user's property array has a new proeprty
//******************************************************************
void ReAssignPreviousInfo(int total_property, players_info * player_info_db, PlayGame * player_db) {

	for (int i = 0; i < total_property-1; i++) {
//                player_info_db[i] = player_db[0].player[i];

               	player_info_db[i].property_type = player_db[0].player[i].property_type;
               	player_info_db[i].property_value = player_db[0].player[i].property_value;
               	player_info_db[i].location = player_db[0].player[i].location;
               	player_info_db[i].mortgage = player_db[0].player[i].mortgage;
               	player_info_db[i].num_tenants = player_db[0].player[i].num_tenants;

       	       	tenants_info *tenants_info_db = new tenants_info[player_info_db[i].num_tenants];
        	for (int j = 0; j < player_info_db[i].num_tenants; j++) {
        		tenants_info_db[j].score = player_db[0].player[i].tenants[j].score;
        		tenants_info_db[j].monthly_budget = player_db[0].player[i].tenants[j].monthly_budget;
        		tenants_info_db[j].rent = player_db[0].player[i].tenants[j].monthly_budget;
      	  	}
		player_info_db[i].tenants = tenants_info_db;

               tenants_info_db = NULL;
                delete [] tenants_info_db;	
     //           tenants_info_db = NULL;
        }
}
//function: assignBLANKinfo
//description: assigns the new property over to the old property
//parameters: int at which the new property will be, the user's database (how much they have and such)
//		database that contains the property they have just bought
//pre: user buys property
//post: property has been added
//******************************************************************
void AssignHouseInfo(int i, players_info * player_info_db, House * house_db, int x) {
	player_info_db[i].property_type = "House";
	player_info_db[i].property_value = house_db[x].property_value;
	player_info_db[i].location = house_db[x].location;
      	player_info_db[i].mortgage = house_db[x].mortgage;
    	player_info_db[i].num_tenants = house_db[x].num_tenants;

       	tenants_info *tenants_info_db = new tenants_info[player_info_db[i].num_tenants];
        for (int j = 0; j < player_info_db[i].num_tenants; j++) {
        	tenants_info_db[j].score = house_db[x].residents[j].score;
        	tenants_info_db[j].monthly_budget = house_db[x].residents[j].monthly_budget;
        	tenants_info_db[j].rent = house_db[x].residents[j].monthly_budget;
        }

	player_info_db[i].tenants = tenants_info_db;

//cout << "Property Value Pre " << house_db[x].property_value << endl;
	tenants_info_db = NULL;
 	delete [] tenants_info_db;

//	tenants_info_db = NULL;
//	house_db[x] = House();
	populate_house(house_db, x);
//cout << "Property Value Post " << house_db[x].property_value << endl;
}


void AssignApartmentInfo(int i, players_info * player_info_db, Apartment * apartment_db, int x) {
	player_info_db[i].property_type = "Apartment";
	player_info_db[i].property_value = apartment_db[x%3].property_value;
	player_info_db[i].location = apartment_db[x%3].location;
	player_info_db[i].mortgage = apartment_db[x%3].mortgage;
	player_info_db[i].num_tenants = apartment_db[x%3].num_tenants;

       	tenants_info *tenants_info_db = new tenants_info[player_info_db[i].num_tenants];
        for (int j = 0; j < player_info_db[i].num_tenants; j++) {
        	tenants_info_db[j].score = apartment_db[x%3].residents[j].score;
        	tenants_info_db[j].monthly_budget = apartment_db[x%3].residents[j].monthly_budget;
        	tenants_info_db[j].rent = apartment_db[x%3].residents[j].monthly_budget;
        }

	player_info_db[i].tenants = tenants_info_db;

//cout << "Property Value Pre " << apartment_db[x%3].property_value << endl;
	tenants_info_db = NULL;
	delete [] tenants_info_db;
	
//	tenants_info_db = NULL;
//	apartment_db[x%3] = Apartment();
	populate_apartment(apartment_db, x%3);
//cout << "Property Value Post " << apartment_db[x%3].property_value << endl;
}


void AssignBusinessInfo(int i, players_info * player_info_db, Business * business_db, int x) {
	player_info_db[i].property_type = "Business";
	player_info_db[i].property_value = business_db[x%3].property_value;
	player_info_db[i].location = business_db[x%3].location;
	player_info_db[i].mortgage = business_db[x%3].mortgage;
	player_info_db[i].num_tenants = business_db[x%3].num_tenants;

       	tenants_info *tenants_info_db = new tenants_info[player_info_db[i].num_tenants];
        for (int j = 0; j < player_info_db[i].num_tenants; j++) {
        	tenants_info_db[j].score = business_db[x%3].residents[j].score;
        	tenants_info_db[j].monthly_budget = business_db[x%3].residents[j].monthly_budget;
        	tenants_info_db[j].rent = business_db[x%3].residents[j].monthly_budget;
        }

	player_info_db[i].tenants = tenants_info_db;

//cout << "Property Value Pre " << business_db[x%3].property_value << endl;
	tenants_info_db = NULL;
	delete [] tenants_info_db;
	
//	tenants_info_db = NULL;
//	business_db[x%3] = Business();
	populate_business(business_db, x%3);
//cout << "Property Value Post " << business_db[x%3].property_value << endl;
}

//function: assignPurchaseproperty
//description: assigns the purchase propety over
//parameters: all of the proeprtyies arrays and the user's info array
//pre: usr purchases a property
//post: purchased moved ober
//******************************************************************
void AssignPurchaseProperty(PlayGame * player_db, int total_property, House * house_db, Apartment * apartment_db, Business * business_db, int x) {

     	// Memory Leak Here when add more than 1 property

     	players_info *player_info_db = new players_info[total_property];

	ReAssignPreviousInfo(total_property, player_info_db, player_db);

	for (int i = total_property-1; i < total_property; i++) {
		if ((x < 3) && (player_db[0].bank_balance > house_db[x].mortgage)) {
                	AssignHouseInfo(i, player_info_db, house_db, x);
		} else if ((x < 6) && (player_db[0].bank_balance > apartment_db[x%3].mortgage)){
                	AssignApartmentInfo(i, player_info_db, apartment_db, x);
		} else if ((x < 9) && (player_db[0].bank_balance > business_db[x%3].mortgage)){
                	AssignBusinessInfo(i, player_info_db, business_db, x);
                } else {
                	cout << "          Not sufficient fund in Bank" << endl;
                	total_property--;
               	}
	}

	player_db[0].num_property = total_property;
	player_db[0].player = player_info_db;

	player_info_db = NULL;
	delete [] player_info_db;
//	player_info_db = NULL;
}
//function: buyproperty
//description: main function that calls other proeptty functions
//parameters: the properties databases and the user's database (to add to)
//pre: property could be bought
//post: property bought
//******************************************************************
void BuyProperty(PlayGame * player_db, House * house_db, Apartment * apartment_db, Business * business_db) {
        int x[3], done;

	x[0] = rand()%9;
	for (int i = 1; i < 3; i++) {
		do {
	        	done = 1;
                	x[i] = rand()%9;
                	for (int j = 0; j < i; j++)
                		if (x[i] == x[j])
                                	done = 0;
                } while (done == 0);

	}

        int tmp = SelectAvailableProperty(house_db, apartment_db, business_db, x);

	if (tmp != 3) {
        	int total_property =  player_db[0].num_property + 1;

       		AssignPurchaseProperty(player_db, total_property, house_db, apartment_db, business_db, x[tmp]);
        }
}
//function: removeproperty
//description: deleted the property that the user selected
//parameters:which property they want to buy and the size of the array and the users db
//pre: user selects property
//post: proeprty is sold
//******************************************************************
void RemoveProperty(PlayGame * player_db, int sell_index, int last_property) {
	player_db[0].player[sell_index].property_type = player_db[0].player[last_property].property_type;
	player_db[0].player[sell_index].property_value = player_db[0].player[last_property].property_value;
	player_db[0].player[sell_index].location = player_db[0].player[last_property].location;
	player_db[0].player[sell_index].mortgage = player_db[0].player[last_property].mortgage;
	player_db[0].player[sell_index].num_tenants = player_db[0].player[last_property].num_tenants;

	for (int j = 0; j < player_db[0].player[sell_index].num_tenants; j++) {
		player_db[0].player[sell_index].tenants[j].score = player_db[0].player[last_property].tenants[j].score;
		player_db[0].player[sell_index].tenants[j].monthly_budget = player_db[0].player[last_property].tenants[j].monthly_budget;
		player_db[0].player[sell_index].tenants[j].rent = player_db[0].player[last_property].tenants[j].rent;
	}
}

//function: sellproperty
//description: main selling property function
//parameters: the database of whaat properties the user owns
//pre: user wants to sell proeprty
//post: the user if they want to sell the proeprty or not
//******************************************************************
void SellProperty(PlayGame * player_db) {
	int total_property =  player_db[0].num_property;
        int last_property = total_property - 1;

        if (total_property > 0) {

		for (int i = 0; i < total_property; i++)
			cout << "Property #" << i << " value = " << player_db[0].player[i].property_value << endl;

		int sell_index = ErrorHandlingRange("Which Property # you want to sell? ", 0, last_property);
		
		int price = get_int(ErrorHandlingInt("Which price you want to sell? ", "Please re-enter number:"));

		if (player_db[0].player[sell_index].num_tenants == 0) { // ok to sell
			int x = rand()%3;
			if (x == 1){
				player_db[0].bank_balance = player_db[0].bank_balance + (0.9*player_db[0].player[sell_index].property_value);
				cout << endl << "You sold the property at 10 percent below it's property value..." << endl;
			}
			else if (x == 2){
				player_db[0].bank_balance = player_db[0].bank_balance + (1.0*player_db[0].player[sell_index].property_value);
				cout << endl << "Property sold at property value. " << endl;
			}
			else {
				cout << endl << "YAY PROPERTY SOLD AT SELLING PRICE! " << endl;
				player_db[0].bank_balance = player_db[0].bank_balance + price;
			}
			if (sell_index != last_property)
				RemoveProperty(player_db, sell_index, last_property);

			player_db[0].num_property = last_property;
		}
		else cout << "Have Tenant, can't sell." << endl;

	} else cout << "No Property to sell." << endl;
}
//function: changerent
//description: user decided to change rent
//parameters database of the properties the user has
//pre: user wants to
//post: rent is changed or not changed
//******************************************************************
void ChangeRent(PlayGame * player_db) {

	int total_property =  player_db[0].num_property;

	for (int i = 0; i < total_property; i++) {
		cout << "Property #: " << i << endl;
		for (int j = 0; j < player_db[0].player[i].num_tenants; j++) {
			cout << "    tenants #" << j << " score: " << player_db[0].player[i].tenants[j].score
			     << " monthly rent: " << player_db[0].player[i].tenants[j].rent << endl;
		}
	}

	int property_raise = ErrorHandlingRange("Which Property you want change rent? ", 0, total_property-1);
	int tenant_raise = ErrorHandlingRange("Which Tenant you want change rent? ", 0, player_db[0].player[property_raise].num_tenants-1);
	int value = get_int(ErrorHandlingInt("What a new rent value? ", "Please re-enter number:"));
        player_db[0].player[property_raise].tenants[tenant_raise].rent = value;
}
//function: property_tax
//description: yearly property tax
//parameterS: user's database
//pre: before tax
//post: after tax
//******************************************************************
void property_tax(PlayGame * player_db) {

	int total_property =  player_db[0].num_property;

	cout << "     bank balance before tax: " << player_db[0].bank_balance << endl;

	for (int i = 0; i < total_property; i++) {
		player_db[0].bank_balance = player_db[0].bank_balance - 0.015*player_db[0].player[i].property_value;
	}

	cout << "     bank balance after tax: " << player_db[0].bank_balance << endl;
}
//function: removetenant
//description: removes tenant (when sold)
//parameters: tenants whereabouts
//pre: user selects which tenant
//post: removes tenant
//******************************************************************
void RemoveTenant(PlayGame * player_db, int index_property, int index_tenant_remove, int num_tenants) {
	int last_tenant = num_tenants - index_tenant_remove;

	player_db[0].player[index_property].tenants[index_tenant_remove].score = player_db[0].player[index_property].tenants[last_tenant].score;
	player_db[0].player[index_property].tenants[index_tenant_remove].monthly_budget = player_db[0].player[index_property].tenants[last_tenant].monthly_budget;
	player_db[0].player[index_property].tenants[index_tenant_remove].rent = player_db[0].player[index_property].tenants[last_tenant].rent;
}

//function: property_monthly
//description:  deducts/adds the montly things rent and mortage
//parameters: the player's database with what they own and their bank
//pre: happens montly
//post: bank account changes
//******************************************************************
void property_monthly(PlayGame * player_db) {

	int total_property =  player_db[0].num_property;

	cout << endl << "     bank balance: " << player_db[0].bank_balance << endl;

	for (int i = 0; i < total_property; i++) {
		player_db[0].bank_balance = player_db[0].bank_balance - player_db[0].player[i].mortgage;
	}
	cout << "     bank balance after mortgage: " << player_db[0].bank_balance << endl;

	for (int i = 0; i < total_property; i++) {
//cout << endl << "player_db[0].player[i].property_type ==== " << player_db[0].player[i].property_type;
//cout << endl << "# Tenant ==== " << player_db[0].player[i].num_tenants;
        	if (player_db[0].player[i].property_type == "Business")
			player_db[0].player[i].property_value = int(player_db[0].player[i].property_value *1.01);

        	int num_tenant_remove = 0;
		for (int j = 0; j < player_db[0].player[i].num_tenants; j++) {

//cout << endl << "rent ==== " << player_db[0].player[i].tenants[j].rent << " Budget === " << player_db[0].player[i].tenants[j].monthly_budget;

			if (player_db[0].player[i].tenants[j].rent <= player_db[0].player[i].tenants[j].monthly_budget) {
				player_db[0].bank_balance = player_db[0].bank_balance + player_db[0].player[i].tenants[j].rent;
			} else {
//cout << endl << "score ==== " << player_db[0].player[i].tenants[j].score;
                        	if (player_db[0].player[i].tenants[j].score > 1) { // Remove Renant
					num_tenant_remove++;

//cout << endl << "num_tenant_removet ==== " << num_tenant_remove;
//cout << endl << "player_db[0].player[i].tenants[j].rent ==== " << player_db[0].player[i].tenants[j].rent;

					RemoveTenant(player_db, i, j, player_db[0].player[i].num_tenants);
/*
	int last_tenant = player_db[0].player[i].num_tenants - j;
	player_db[0].player[i].tenants[j].score = player_db[0].player[i].tenants[last_tenant].score;
	player_db[0].player[i].tenants[j].monthly_budget = player_db[0].player[i].tenants[last_tenant].monthly_budget;
	player_db[0].player[i].tenants[j].rent = player_db[0].player[i].tenants[last_tenant].rent;
*/
                        	}
                        }

                }
                player_db[0].player[i].num_tenants = player_db[0].player[i].num_tenants - num_tenant_remove;
	}
	cout << "     bank balance after Rent: " << player_db[0].bank_balance << endl;

}
//function: printproperty
//description: prints out the property that the user owns
//parameters: the player's properties
//pre: user wants to see their properties
//post: properties are shown
//******************************************************************
void PrintProperty(PlayGame * player_db) {

	int total_property =  player_db[0].num_property;

	cout << player_db[0].name << "bank balance: " << player_db[0].bank_balance << " total property: " << total_property << endl;

	for (int i = 0; i < total_property; i++) {
		cout << "Property #: " << i << endl;
		cout << "   property type: " << player_db[0].player[i].property_type << endl;
		cout << "   property value: " << player_db[0].player[i].property_value << endl;
		cout << "   location: " << player_db[0].player[i].location << endl;
		cout << "   mortgage: " << player_db[0].player[i].mortgage << endl;
		cout << "   num_tenants: " << player_db[0].player[i].num_tenants << endl;

		for (int j = 0; j < player_db[0].player[i].num_tenants; j++) {
			cout << "   tenants score: " << player_db[0].player[i].tenants[j].score << endl;
			cout << "   tenants monthly budget: " << player_db[0].player[i].tenants[j].monthly_budget << endl;
			cout << "   tenants monthly rent: " << player_db[0].player[i].tenants[j].rent << endl;
		}

	}
}


//function: call_BLANK
//description: calls the corresponding random event
//parameters: the database of the event and the users database
//pre: random_event is called
//post: user's property values are changed
void call_Hurricane(PlayGame * player_db, Hurricane Hurricane_db[1]){
	int total_property =  player_db[0].num_property;

	for (int i = 0; i < total_property; i++) {
		if (player_db[0].player[i].location == Hurricane_db[0].location)
			player_db[0].player[i].property_value = int(player_db[0].player[i].property_value * Hurricane_db[0].percentage);
	}
}

void call_Tornado(PlayGame * player_db, Tornado Tornado_db[1]){
	int total_property =  player_db[0].num_property;

	for (int i = 0; i < total_property; i++) {
		if (player_db[0].player[i].location == Tornado_db[0].location)
			player_db[0].player[i].property_value = int(player_db[0].player[i].property_value * Tornado_db[0].percentage);
	}
}

void call_Earthquake(PlayGame * player_db, Earthquake Earthquake_db[1]){
	int total_property =  player_db[0].num_property;

	for (int i = 0; i < total_property; i++) {
		if (player_db[0].player[i].location == Earthquake_db[0].location)
			player_db[0].player[i].property_value = int(player_db[0].player[i].property_value * Earthquake_db[0].percentage);
	}
}

void call_Wildfire(PlayGame * player_db, Wildfire Wildfire_db[1]){
	int total_property =  player_db[0].num_property;

	for (int i = 0; i < total_property; i++) {
		if (player_db[0].player[i].location == Wildfire_db[0].location)
			player_db[0].player[i].property_value = int(player_db[0].player[i].property_value * Wildfire_db[0].percentage);
	}
}

void call_StockMarket(PlayGame * player_db, StockMarket StockMarket_db[1]){
	int total_property =  player_db[0].num_property;

	for (int i = 0; i < total_property; i++) {
		player_db[0].player[i].property_value = int(player_db[0].player[i].property_value * StockMarket_db[0].percentage);
	}
}


void call_Gentrification(PlayGame * player_db, Gentrification Gentrification_db[1]){
	int total_property =  player_db[0].num_property;
	string address = "";
	int x = rand()% 5;
	if( x == 0)
		address = "SE";
	else if (x == 1)
		address = "NE";
	else if (x == 2)
		address = "MIDWEST";
	else if (x == 3)
		address = "SW";
	else if (x == 4)
		address = "NW";

	for (int i = 0; i < total_property; i++) {
		if (player_db[0].player[i].location == address)
			player_db[0].player[i].property_value = int(player_db[0].player[i].property_value * Gentrification_db[0].percentage);
		//if (player_db[0].player[i].location == Wildfire_db[0].location)
	}

	cout << "Random = " << address << endl;
}
//*****************************************************************************************





//function: Random_Event
//description: runs the random event
//parameters: takes in the player's database of the stuff they own
//pre: its time for random event
//post: random event funs
//******************************************************************
void Random_Event(PlayGame * player_db){
	
	cout << endl << "RANDOM EVENT!" << endl;

	int event = rand()%6;

	if (event == 0) {
                Hurricane Hurricane_db[1];
                call_Hurricane(player_db, Hurricane_db);
	} else if (event == 1) {
                Tornado Tornado_db[1];
                call_Tornado(player_db, Tornado_db);
	} else if (event == 2) {
                Earthquake Earthquake_db[1];
                call_Earthquake(player_db, Earthquake_db);
	} else if (event == 3) {
                Wildfire Wildfire_db[1];
                call_Wildfire(player_db, Wildfire_db);
	} else if (event == 4) {
                StockMarket StockMarket_db[1];
                call_StockMarket(player_db, StockMarket_db);
	} else if (event == 5) {
                Gentrification Gentrification_db[1];
                call_Gentrification(player_db, Gentrification_db);
        }
};

//function: Player_selection
//description: prints and takes error handles input for menu
//parameters: n/a
//pre: what player wants to do
//post: will either reprompt or move to next function
//******************************************************************
int Player_selection(){
	string ans = "";

	do{
		cout << endl << "What would you like to do? " << endl;
		cout << "1. Buy Property" << endl;
		cout << "2. Sell Property" << endl;
		cout << "3. Change Rent Property" << endl;
		cout << "4. Print Property Inventory" << endl;
		cout << "5. End Month" << endl;
		cout << "6. Quit" << endl;
		cout << "Selection: " ;
                getline(cin,ans);
		cout << endl;
	}while ((get_int(ans) < 1) || (get_int(ans) > 6));
	
	return (get_int(ans));
}
//function: execute selected
//description: runs the function that the user selected
//parameters: n/a
//pre: user selects 
//post: will run the function
//******************************************************************
void Execute_selected(PlayGame * player_db, House * house_db, Apartment * apartment_db, Business * business_db) {
	int count = 0, next_month = 0;;
        do {

		if ((player_db[0].num_property > 0) && (next_month == 1)) {
			count++;
			if (count%12 == 0)
                        	property_tax(player_db);
                	property_monthly(player_db);
                	Random_Event(player_db);
                }
		if (next_month == 1)
			next_month = 0;
        	switch (Player_selection()) {
        		case 1: BuyProperty(player_db, house_db, apartment_db, business_db);	break;
        		case 2: SellProperty(player_db);					break;
        		case 3: ChangeRent(player_db); 						break;
        		case 4: PrintProperty(player_db);					break;
        		case 5: next_month = 1;							break;
        		case 6: player_db[0].bank_balance = -1;					break;
       	 	}
                if ((player_db[0].bank_balance < 0) || (player_db[0].bank_balance > 1000000))
                	break;
        } while (1);
}

bool operator > (const Property& p1, const Property & p2){
//	if ((property.



}

bool operator < (const Property&, const Property &){


}



//function: letplaygame
//description: main game function
//parameters: none
//pre: user plays game
//post: game is over
//******************************************************************
void LetPlayGame() {
        PlayGame * player_db = new PlayGame[1];
	player_db[0].name = "Player";
	player_db[0].bank_balance = 500000.0;
	player_db[0].num_property = 0;
	House * house_db = new House[3];
	Apartment * apartment_db = new Apartment[3];
	Business * business_db = new Business[3];


//        Execute_selected( player_db, house_db, apartment_db, business_db);
 //       end_statement(player_db);
        delete [] house_db;
        delete [] apartment_db;
        delete [] business_db;
	for (int j = 0; j < player_db[0].num_property; j++) {
		delete [] player_db[0].player[j].tenants;
	}
	delete [] player_db[0].player;
        delete [] player_db;

}

