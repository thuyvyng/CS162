#include <iostream>
#include <string>
#include <stdlib.h>
#include "random_event.h"

using namespace std;

//random_event constructor
Random_Event::Random_Event(){
	location = "everywhere";
	event = "something";
	percentage = 0;
}

//random_event copy constructor
Random_Event::Random_Event(const Random_Event & copy){
	location = copy.location;
	event = copy.event;
	percentage = copy.percentage;
}
//random event assignment overload
const Random_Event& Random_Event:: operator = (const Random_Event & copy){
	location = copy.location;
	event = copy.event;
	percentage = copy.percentage;
	return *this;
}
//hurricane constructor
Hurricane::Hurricane():Random_Event(){
	location = "SE";
	event = "Hurricane";
	percentage = 0.5;

	cout << "Oh no! You've been hit by a hurricane. " <<
	"All your properties in the SE have been hit." <<
	" Their property value has been decreased by 50%." << endl;
}

//tornado constructor
Tornado::Tornado():Random_Event(){
	location = "Midwest";
	event = "Tornado";
	percentage = 0.7;

	cout << "Oh no! You've been hit by a Tornado. " <<
	"All your properties in the MIDWEST have been hit." <<
	" Their property value has been decreased by 30%." << endl;
}

//earthquake constructor
Earthquake::Earthquake():Random_Event(){
	location = "NW";
	event = "Earthquake";
	percentage = 0.9;

	cout << "Oh no! You've been hit by a earthquake. " <<
	"All your properties in the NW have been hit." <<
	" Their property value has been decreased by 10%." << endl;
}
//wildfire constructor
Wildfire::Wildfire():Random_Event(){
	location = "SW";
	event = "Wildfire";
	percentage = 0.75;

	cout << "Oh no! You've been hit by a wildfire. " <<
	"All your properties in the SW have been hit." <<
	" Their property value has been decreased by 25%." << endl;

}
//stockmarket constructor
StockMarket::StockMarket():Random_Event(){
	location = "all properties";
	event = "Stock Market Crash";
	percentage = 0.7;

	cout << "The stock market has crashed.." <<
	"All your properties have had their values decreased by 30%." << endl;
}

//gentrification constructor
Gentrification::Gentrification():Random_Event(){
	location = "random";
	event = "gentrification";
	percentage = 1.2;

	//insert this function here for random location
	cout << "Woohooooo! Businesses in " << location <<
	" are doing super well!" <<
	"Property value has increased by 20%!" << endl;
}

//random_event destructor
Random_Event::~Random_Event(){

};

