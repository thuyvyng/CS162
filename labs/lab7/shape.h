#include <string>
#include <iostream>
#include <cmath>

using namespace std;


class Shape{
	public:
		string name;
		string color;
		//constructors
		Shape();
		Shape(string,string);

		//accessors

		string get_name()const;
		string get_color()const;

		//mutators

		void set_name(string);
		void set_color(string);

		virtual float calculate_area() = 0;
};



class Circle: public Shape{
	private:
		int radius;
	public:
		Circle();
		Circle(int,string,string);	
		
		//accessors
		int get_radius()const;
		//mutators
		void set_radius(int);

		float calculate_area();

};

class Rectangle: public Shape{
	private:
		int length;
		int width;
	public:
		Rectangle();
		Rectangle(int, int, string, string);
		
		//accessors
		int get_length()const;
		int get_width()const;
		
		//mutators
		void set_length(int);
		void set_width(int);

		float calculate_area();
};
