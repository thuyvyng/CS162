#include <iostream>
#include "demo.h"

using namespace std;

int main(){
	
	Point a(0,0), b(5,5);

	cout << "a ";
	a.print();

	cout << "b ";
	b.print();

	a.translate(1,1);
	b.translate(5,5);


	cout << "a ";
	a.print();

	cout << "b ";
	b.print();


	return 0;
}
