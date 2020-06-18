#include <iostream>
#include "practice.h"

using namespace std;

Show::Show(){
	title = "defaultname";
	director = "randomdirector";
	time = 1.45;
	num_characters = 0;
	characters = NULL;
}

Show::Show(string title, string director, float time, int num_characters){
	this-> title = title;
	this-> director = director;
	this-> time = time;
	this-> num_characters = num_characters;
	characters = new string[num_characters];
	
	for (int i = 0; i < num_characters; i++){
		characters[i] = "Name";
	}

}

string Show::get_title() const{
	return title;
}

string Show::get_director() const{
	return director;
}
float Show::get_time() const{
	return time;
}
int Show::get_num_char() const{
	return num_characters;
}
string Show::get_name_char(int i) const{
	return characters[i];
}

		//mutators
		
void Show::set_title(string tit){
	title = tit;
}
void Show::set_director(string direct){
	director = direct;
}
void Show::set_time(float ti){
	time = ti;	
}
void Show::set_num_characters(int ch){
	num_characters = ch;
}
void Show::set_chars_name(int num_chars){
	for (int i = 0; i < num_chars; i++){
		cout << "Insert character name: ";
		getline(cin,characters[i]);
	}
}



