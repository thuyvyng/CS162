#include <iostream>
#include "ant.h"
#include <vector>
#include "bee.h"
using namespace std;

class Fire: public Ant{
	public:
		string name;
		int armor;
		int location;
		int food_cost;

		Fire();
		Fire(const Fire &);

		void attack(vector<Ant> [], vector<Bee> [], int *, int *, int,int);


		string get_name() const;
		int get_armor() const;
		int get_food_cost() const;

		const Fire & operator = (const Fire&);
		~Fire();
};
