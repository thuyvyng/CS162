#include <iostream>
#include "big3.h"

using namespace std;

Blank::Blank(){
  num = 14;
  name = "yes";
  star = NULL;

}

Blank::Blank( int n, string na){
  num = n;
  name = na;
  star = new int[num];
  for (int i = 0; i < num; i++){
    star[i] = 3;
  }
}

int Blank::get_star(int i) const{
  return star[i];
}

int Blank::get_num() const{
  return num;
}

string Blank::get_name() const{
  return name;
}

void Blank::set_num( int n){
  num = n;
}

void Blank::set_name(string n){
  name = n;
}

void Blank::set_star(int i, int val){
  star[i] = val;

}

//copy constructor
Blank::Blank(const Blank& copy){
  num = copy.num;
  name = copy.name;
  if (num == 0)
    star = NULL;
  else{
    star = new int[num];
    for (int i = 0; i < num; i++){
      star[i] = copy.star[i];
    }
  }


}

const Blank & Blank:: operator = (const Blank & copy){
  num = copy.num;
  name = copy.name;
  if (star != NULL)
    delete [] star;
  if (num == 0)
    star = NULL;
  else{
    star = new int[num];
    for (int i = 0; i < num; i++){
      star[i] = copy.star[i];
    }
  }
  return *this;

}


Blank:: ~ Blank(){
  delete [] star;


}
