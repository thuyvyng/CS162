#include <iostream>
#include "big3.h"

using namespace std;

int main(){
  Blank w(4,"UH oh");
  //w.set_name("WHATEVER");
  cout << "NAME: " << w.get_name() << endl;

  cout << "Woo: "<< w.get_star(1) << endl;
  w.set_star(1,12);
  cout << "uh oh:"<< w.get_star(1) << endl;


  return 0;

}
