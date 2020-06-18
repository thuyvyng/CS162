#include <iostream>
#include <string>

using namespace std;

struct tenants{
	int score;           //  randomly assigned agreeability score ranging from 1 to 5
	int monthly_budget;  // randomly assigned monthly budget
};

class Property{
	
	public:
		int property_value; // randomly assigned a property value, House >=100,000; Apartment >= 300,000; Business >= 400,000
		string location;    // randomly assigned a location (United States: SE, NE, Midwest, SW, and NW)
		int mortgage;        // randomly assigned monthly (turn) price (not to exceed 5000) 
					//and a calculated duration of mortgage based on the monthly price (exclude interest)
		float property_tax; // fixed at 1.5%
		int num_tenants;    // random number Apartment max 10, Business max 5
		string size;         //unsure if this is important
		tenants * residents;

		//constructor
		Property();
		Property(int,int);

		//accessors
		int get_property_value() const;
		string get_location() const;
		int get_mortgage() const;
		float get_property_tax() const;
		int get_num_tenants() const;
		tenants * get_residents() const;
				
		
		friend bool operator <(const Property&, const Property &);
		friend bool operator >(const Property&, const Property &);

		//mutators
		void set_property_value(int);
		void set_location(string);
		void set_mortgage(int);
		void set_property_tax(float);
		void set_residents(tenants *);

		//big three
		//Property(const Property&);
//		const Property & operator=(const Property &);
//		~Property();

		
};

class House : public Property{
	public:
		House();
		int property_value_h();

		House(const House&);
		const House & operator=(const House&);
/*		~House();
*/

		void populate_house(House * house_db, int index);
//void populate_apartment(Apartment * apartment_db, int index);
//void populate_business(Business * business_db, int index);
		~House();
};
class Apartment: public Property{
	public:
		Apartment();
		int property_value_a();
		Apartment(const Apartment&);
		const Apartment& operator=(const Apartment &);
/*		~Apartment();
*/

//void populate_house(House * house_db, int index);
		void populate_apartment(Apartment * apartment_db, int index);
//void populate_business(Business * business_db, int index);
		~Apartment();
};

class Business: public Property{
	public:
		Business();
		int property_value_b();

		Business(const Business&);
		const Business & operator=(const Business &);
/*		~Business();
*/
//void populate_house(House * house_db, int index);
//void populate_apartment(Apartment * apartment_db, int index);
		void populate_business(Business * business_db, int index);
		~Business();


};
