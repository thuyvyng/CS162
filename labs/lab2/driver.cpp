#include <iostream>
#include <string>
#include <fstream>
#include "lab2.h"
using namespace std;


int main(){
	
	fstream input;
	fstream output;

	char filename[256];
	int num;
	string first_name;
	string last_name;
	string major;
	string id;

	struct student *student_table;
	do{
		cout << "What file do you want to open?: ";
		cin.getline(filename, 256);
		input.open(filename);
	} while (!input.is_open());

	if (input.is_open()){
		output.open("end.txt");
		input >> num;
		student_table = create_student_db(num);
		get_student_db_info(student_table, num, input);
		cout << endl << endl;
	
		sort(student_table, num);
		output << "LAST NAMES" << endl;
		print(student_table,num,output);
		
		output << endl << endl;
		sort_id(student_table,num);
		output << "ID" << endl;
		print(student_table,num,output);

		
	
		sort_majors(student_table,num);
	
		output << "There are " <<  counter(student_table,num) << " unique majors" << endl << endl;

		cout << "Your output file is end.txt" << endl;	


	}

	delete_student_db_info(&student_table, num);


	input.close();
	output.close();
	return 0;

}
