#include <iostream>
#include <string>
#include "shape.h"
#ifndef SHAPE_H
#define SHAPE_H

using namespace std;


Shape::Shape(){
	color = "blank";
	name = "blank";

}

Shape::Shape(string c, string n){
	color = c;
	name = n;
	
}



string Shape::get_name()const{
	return name;
}

string Shape::get_color()const{
	return color;	
}

void Shape::set_name(string n){
	name = n;
}

void Shape::set_color(string c){
	color = c;
}

Circle::Circle():Shape(){
	radius = 0;
	color = "YES";
	name = "BLANK";

}

Circle::Circle(int r,string c, string n):Shape(c, n){
	radius = r;
	color = c;
	name = n;
}

Rectangle::Rectangle():Shape(){
	length = 0;
	width = 0;
	color = "BLANK";
	name = "BLANK";
}

Rectangle::Rectangle(int l, int w, string c, string n): Shape(c,n){
	length = l;
	width = w;
	color = c;
	name = n;
}


//virtual float Shape::calculate_area(){

//}
int Circle::get_radius()const{
	return radius;
}

int Rectangle::get_length()const{
	return length;
}

int Rectangle::get_width()const{
	return width;
}

void Circle::set_radius(int r){
	radius = r;
}

void Rectangle::set_length(int l){
	length = l;
}

void Rectangle::set_width(int w){
	width = w;
}


float Circle::calculate_area(){
	float area = 0;
	area = radius*3.14*radius;
	return area;
}


float Rectangle::calculate_area(){
	float area = 0;
	area = length*width;
	return area;
}














#endif
