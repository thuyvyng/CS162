#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;


bool is_int(string num){
	bool c_num = 0;
	int len = 0;
	int l = num.length();

	while(num[len] != '\0'){
		if (((num[len] >47) && (num[len] <58 )) || (num[len] == 45)){
			len++;
		}
		else{
			break;
		}
	c_num = 1;
	}
	return c_num;

}

int get_int(string bin){
	int res = 0;
	for (int i = 0; i < bin.length(); i++){

		int check = bin[i] - '0';
		int topower = int(bin.length()) - i - 1;
		res = (int)((check*pow(10.0,topower)) + res);
	}
	return res;

}


int checkCol(int argc, char ** argv){
	int check = 0;
	string coord1 =  "";
	string coord2 = "";

	if ( is_int(argv[2]) == 0){
		do{
			cout << "Insert column: ";
			getline(cin,coord2);
		} while ( is_int(coord2) == 0);


	}
	else{
		coord2 = argv[2];
	}
	
	check = get_int(coord2);

	return check;


}

int checkRow(int argc, char ** argv){
	int check = 0;
	string coord1 = "";

	if (is_int(argv[1]) == 0){
		do{
			cout << "Insert row: ";
			getline(cin,coord1);
		}while (is_int(coord1) == 0 );
	}
	else{
		coord1 = argv[1];
	}

	check = get_int(coord1);
	return check;
}
/////////////////////////////////////////////////////////////////////////////




struct mult_div_values{
	int mult;
	float div;

};


mult_div_values** create_table(int rows, int cols){
	mult_div_values ** ar = new mult_div_values *[rows];
	for (int i = 0;i < rows; i++){
		ar[i] = new mult_div_values[cols];
	}

	return ar;
}


void set_mult_values(mult_div_values ** ar, int rows, int cols){
	for(int i = 0; i < rows; i ++){
		for (int j = 0; j < cols; j++){
			ar[i][j].mult = (i+1)*(j+1);
		}

	}

}

void set_div_values(mult_div_values**ar, int rows, int cols){
	for (int i = 0; i < rows ; i++){
		for (int j = 0; j < cols; j++){
			ar[i][j].div = (float)(i+1)/(j+1);
		}

	}

}


void print_table(mult_div_values**ar, int rows, int cols){
	cout << "Multiplication table" << endl;
	for (int i = 0; i < rows; i ++){
		for (int j = 0; j < cols; j++){
			cout << ar[i][j].mult << " " ;

		}
	cout << endl;
	}

	cout << "Division table" << endl;
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			cout << ar[i][j].div << " ";
		}
	cout << endl;
	}


}



void delete_table(mult_div_values**ar,int rows){
	for (int i = 0; i < rows; i++){
		delete [] ar[i];
	}
	delete [] ar;
}



////////////////////////////////////////////////////////////////////////////
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
