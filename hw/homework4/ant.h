#include <iostream>
#include "insect.h"
//#include "game.h"

#ifndef ANT_H
#define ANT_H


using namespace std;

class Ant{
	public:
		string name;
		int armor;
		int location;
		int food_cost;

		void attack();

		Ant();
		Ant(const Ant &);
		const Ant & operator = (const Ant&);
		~Ant();
};
#endif
