#include <iostream>
#include "ant.h"

#include <vector>
#include "bee.h"
using namespace std;

class LongThrower: public Ant{
	public:
		string name;
		int armor;
		int location;
		int food_cost;

		LongThrower();
		LongThrower(const LongThrower &);

		string get_name() const;
		int get_armor() const;
		int get_food_cost() const;

		void attack(vector<Ant> [], vector<Bee> [], int *, int *,int,int);

		const LongThrower & operator = (const LongThrower&);
		~LongThrower();
};
