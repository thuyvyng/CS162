#include <iostream>
#include <string>
using namespace std;

class Blank{
  public:
    int num;
    string name;
    int * star;

    //accessors
    int get_num() const;
    string get_name() const;
    int get_star(int)const;

    //mutators
    void set_num(int);
    void set_name(string);
    void set_star(int,int);

    //big 3
    Blank();
    Blank(int, string);
    Blank(const Blank&);
    const Blank & operator = (const Blank&);
    ~Blank();





};
