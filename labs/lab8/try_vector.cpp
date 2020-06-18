#include "./vector.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;

int main(){
	
	vector<int> v;
	std::vector<int> stdv;

	vector <int>p;

	v.push_back(23);
	stdv.push_back(23);
	
	v.push_back(2);

	p = v;


	cout << "our vector size: " << v.size() << endl;
	cout << "STL vector size: " << stdv.size() << endl;

	cout << "our vector size: " << p.size() << endl;
	

	cout << "AT 1" << endl;
	p.at(1);

	try{
		cout << "TESTING BAD CASE" << endl;
		p.at(43);
	}
	catch(std::out_of_range e){
			cout << "its bad" << endl;
	}

	return 0;
}
