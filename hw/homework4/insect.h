#include <iostream>
#include <string>

#ifndef INSECT_H
#define INSECT_H

using namespace std;

class Insect{
	public:
		int armor;
		int location;

		//constructor
		virtual void attack() = 0;
		Insect();
		Insect(const Insect&);
		const Insect & operator = (const Insect &);
		~Insect();
};

#endif
