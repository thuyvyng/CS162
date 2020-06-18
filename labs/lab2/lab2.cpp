#include <fstream>
#include <iostream>
#include <string>
#include "lab2.h"

using namespace std;

student * create_student_db(int fromfile){
	student *student_db = new student[fromfile];

	return student_db;
}

void get_student_db_info(struct student* student_db, int fromfile, fstream& input){
	for (int i = 0; i < fromfile; i++){
		input >> (student_db[i]).id >> student_db[i].firstname >> student_db[i].lastname >> student_db[i].major;
	}

}

void print( student* student_db, int fromfile, fstream&output){
	for (int i = 0; i < fromfile; i++){
		output << student_db[i].id << "\t" << student_db[i].firstname << "\t" << student_db[i].lastname << "\t" << student_db[i].major <<  endl;
	
	}
	output << endl << endl;
	
}

void sort(student*student_db, int fromfile){
	int j, i, flag = 1;
	struct student temp;

	for ( i = 1; (i < fromfile)&&flag ; i++){
		flag = 0;
		for (j = 0; j < fromfile-1; j++){
			if (student_db[j+1].lastname < student_db[j].lastname){
				temp = student_db[j];
				student_db[j] = student_db[j+1];
				student_db[j+1] = temp;
				flag = 1;
			}
		}

	}

}

void sort_id(student*student_db, int fromfile){
	int j, i, flag = 1;
	struct student temp;

	for ( i = 1; (i < fromfile)&&flag ; i++){
		flag = 0;
		for (j = 0; j < fromfile-1; j++){
			if (student_db[j+1].id < student_db[j].id){
				temp = student_db[j];
				student_db[j] = student_db[j+1];
				student_db[j+1] = temp;
				flag = 1;
			}	
		}
	}	
}

void sort_majors(student* student_db, int fromfile){
	for (int i = 0; i < fromfile-1; i++){

		for (int j = i+1; j < fromfile; j++){
			if (student_db[i].major == student_db[j].major){
				student_db[i].major = "";
				student_db[j].major = "";
			}
		}
	}

}




int counter(student* student_db, int fromfile){
	int count = 0;

	for( int i = 0; i < fromfile; i++){
		if (student_db[i].major != ""){
			count++;
		}
	}
	return count;
}

void delete_student_db_info( student ** student_db, int fromfile){
	
	delete [] *student_db;

	student_db = NULL;

}

