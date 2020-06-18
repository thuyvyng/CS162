#include <iostream>
#include "ant.h"
#include <vector>
#include "bee.h"
using namespace std;

class Wall: public Ant{
	public:
		string name;
		int armor;
		int location;
		int food_cost;

		Wall();
		Wall(const Wall &);

		string get_name() const;
		int get_armor() const;
		int get_food_cost() const;

		void attack(vector<Ant> [], vector<Bee> [], int *, int *, int,int);

		const Wall & operator = (const Wall&);
		~Wall();
};
