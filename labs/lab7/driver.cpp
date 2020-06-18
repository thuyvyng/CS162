#include <iostream>
#include "shape.h"

using namespace std;



void print_shape( Shape & yes){
	cout << "NAME: " << yes.get_name() << endl;
	cout << "COLOR: " << yes.get_color() << endl;
	cout << "AREA: " << yes.calculate_area() << endl;

}
int main(){


	Rectangle r(7,7,"purple", "me");

	cout << "Len:" << r.get_length() << endl;

	cout << "Area: " << r.calculate_area() << endl;

	cout << endl << endl <<  "Print " << endl << endl;
	print_shape(r);
	

	Circle w;
	
	cout << "uh oh" << w.get_color() << endl;	
	return 0;
}
