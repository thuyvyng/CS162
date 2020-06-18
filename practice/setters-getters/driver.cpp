#include "practice.h"
#include <iostream>

using namespace std;

int main(){

	Show Jane("Jane the virgin","Dude",10.111, 5); 
	
	cout << Jane.get_title() << endl;

	Jane.set_chars_name(5);
	
	cout << Jane.get_name_char(2) << endl;

	return 0;
}
