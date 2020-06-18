#include <iostream>
#include "demo.h"

using namespace std;

void Point::set_x(int num){
	x = num;
}

void Point:: set_y(int num){
	y = num;
}	

int Point:: get_x(){
	return x;
}

int Point:: get_y(){
	return y;
}

void Point::translate(int x_off,int y_off){
	x += x_off;
	y += y_off;
}

void Point:: print(){
	cout << "X: " << x << endl << "Y: " << y << endl;
}

Point::Point(){
	x = 0;
	y = 0;
}

Point::Point(int x_v, int y_val){
	x = x_v;
	y = y_val;
}
