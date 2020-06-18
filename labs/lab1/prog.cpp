#include <iostream>
#include <string>
#include "./mult_div.h"
#include <cmath>
#include <cstdlib>
using namespace std;


int main(int argc, char **argv){

	int col = checkCol(argc, argv);
	int row = checkRow(argc,argv);
	int ans = 1;

	while (ans == 1){

	mult_div_values ** table = create_table(row,col);
	set_mult_values( table, row, col);
	set_div_values(table, row, col);
	print_table(table,row,col);
	delete_table(table, row);
	
	cout << "Do you want to go again? 1 for yes 0 for no" << endl;
	cin >> ans;
	if (ans == 1){
		cout << "Insert row:" << endl;
		cin >> row;
		cout << "Insert col:" << endl;
		cin >> col;
	}
	}
	return 0;

}
