#include <iostream>
#include <string>
#ifndef BEE_H
#define BEE_H


using namespace std;

class Bee{
	public:
		string name;
		int armor;
		int location;

		Bee();
		//Bee(int,int);
		Bee(const Bee&);
		const Bee & operator = (const Bee&);
		~Bee();

};

#endif
