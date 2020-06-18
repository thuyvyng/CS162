#include <iostream>
#include <string>

using namespace std;

struct tenants{
	string name;
	int score;
	int rent;
	int monthly_budget;
	string size; //unsure if this is important

};

class Property{
	
	public:
		int property_value;
		string location;
		int mortage;
		float property_tax;
		int num_tenants;
		tenants * residents;

		//constructor
		Property();

		//accessors
		int get_property_value() const;
		string get_location() const;
		int get_mortage() const;
		float get_property_tax() const;
		tenants * get_residents() const;
				

		//mutators
		void set_property_value(int);
		void set_location(string);
		void set_mortage(int);
		void set_property_tax(float);
		void set_residents(tenants *);

		//big three
		Property(const Property&);
		const Property & operator=(const Property &);
		~Property();

	
};

class House : public Property{
	private:
		House();

		House(const House&);
		const House & operator=(const House&);
		~House();

};

class Apartment: public Property{
	private:
		Apartment();
		
		Apartment(const Apartment&);
		const Apartment& operator=(const Apartment &);
		~Apartment();
};

class Business: public Property{
	private:
		Business();

		Business(const Business&);
		const Business & operator=(const Business &);
		~Business();
};
 
