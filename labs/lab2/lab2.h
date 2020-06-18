#include <iostream>
#include <string>

using namespace std;

struct student{
	string id;
	string firstname;
	string lastname;
	string major;
};

student * create_student_db(int);

void get_student_db_info(struct student*, int, fstream&);

void print( struct student*,int, fstream&);


void sort (struct student*, int);


void sort_id(struct student*, int);

void sort_majors(struct student*, int);

int counter(struct student*, int);


void delete_student_db_info(student**, int);

