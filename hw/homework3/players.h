#include <iostream>
#include <string>

using namespace std;

struct tenants_info{
	int score;
	int monthly_budget;
	int rent;
};

struct players_info{
	string property_type;
	int property_value;
	string location;
	int mortgage;
	int num_tenants;
       	tenants_info * tenants;
};

struct PlayGame{
	string name;
	float bank_balance;
	int num_property;
       	players_info * player;
};

void LetPlayGame();




