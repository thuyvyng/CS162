#include <iostream>
#include <string>

using namespace std;


class Random_Event{
	public:
		string location;
		string event;
		float percentage;

	//constructor
	Random_Event();
	Random_Event(const Random_Event&);
	const Random_Event& operator = (const Random_Event&);
	~ Random_Event();
};


class Hurricane: public Random_Event{
	public:
		Hurricane();
};

class Tornado: public Random_Event{
	public:
		Tornado();
};

class Earthquake: public Random_Event{
	public:
		Earthquake();
};

class Wildfire: public Random_Event{
	public:
		Wildfire();
};

class StockMarket: public Random_Event{
	public:
		StockMarket();
};

class Gentrification: public Random_Event{
	public:
		Gentrification();
};


