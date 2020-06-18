#include <iostream>
#include <cmath>

#include "game.h"


using namespace std;

//these have been reused from past assignments
//******************************************************************
int get_int(string bin){
	int res = 0;
	for (int i = 0; i < bin.length(); i++){
		int check = bin[i] - '0';
		int topower = int(bin.length()) -i -1;
		res = (int)((check*pow(10.0,topower)) + res);
	}
	return res;
}

/**********************************************************/

//function: game default constructor
//description: game cosntructor for game class (makes driver cleaner)
//parameters: none
//pre: starts game
//post: plays game
Game::Game(){
  num_bees = 0;
  num_ants = 0;
}

//function: DefaultBoard
//description: creates and initializes the initial board
//parameters: ant & board arrays
//pre: no board
//post: board is created
void Game::DefaultBoard(vector<Ant> ant_array[10], vector<Bee> bee_array[10]){
  for (int i = 0; i < 10; i++)
      cout << "|      " << i << "     ";
  cout << "|" << endl;

  for (int i = 0; i < 10; i++) {
    ant_array[i].resize(1);
    bee_array[i].resize(1);
    if (i == 0) {
      ant_array[i][0].name = "ANT";
      ant_array[i][0].armor = 1;
    } else {
      ant_array[i][0].name = "   ";
      ant_array[i][0].armor = 0;
    }

    if (i == 9) {
      bee_array[i][0].name = "   ";
      bee_array[i][0].armor = 0;
    } else {
      bee_array[i][0].name = "   ";
      bee_array[i][0].armor = 0;
    }
  }

  for (int i = 0; i < 10; i++)
      cout << "|" << ant_array[i][0].name << ":" << ant_array[i][0].armor << ", " << bee_array[i][0].name << ":" << bee_array[i][0].armor;

  cout << "|" << endl << endl;
}


//function: reorg
//description: cleans up array so there aren't empty spaces
//parameters: ant and bee arrays and number of total rows
//pre: arrays
//post: makes array cleaner
void Game:: reorg(vector<Ant> ant_array[10], vector<Bee> bee_array[10],int *total_row){

	for (int i = 0; i < 10; i++){
		for (int j = 0; j <= *total_row; j++){
			if ( j == 1){
				if ( ant_array[i][j].name == "Bod"){
					int w = ant_array[i][j].armor;

					ant_array[i][j].name = ant_array[i][0].name;
					ant_array[i][j].armor = ant_array[i][0].armor;
					ant_array[i][0].name = "Bod";
					ant_array[i][0].armor = w;



				}
			}
			if (ant_array[i][j].armor == 0){
				for (int k = j + 1; k<= *total_row; k++){
					if (ant_array[i][k].armor > 0){
						ant_array[i][j].armor = ant_array[i][k].armor;
						ant_array[i][j].name = ant_array[i][k].name;
						ant_array[i][k].armor = 0;
						ant_array[i][k].name = "   ";


					}
				}
			}
		}
	}

	for (int i = 0; i < 10; i++){
		for (int j = 0; j <= *total_row; j++){
			if (bee_array[i][j].armor == 0){
				for (int k = j + 1; k<= *total_row; k++){
					if (bee_array[i][k].armor > 0){
						bee_array[i][j].armor = bee_array[i][k].armor;
						bee_array[i][j].name = bee_array[i][k].name;
					}
				}
			}
		}
	}
}

//function: UpdateBoard
//description: updates board and prints it out
//parameters: ant and bee array and number of rows it has
//pre: board is not up to date
//post: prints and updates board to user
void Game::UpdateBoard(vector<Ant> ant_array[10], vector<Bee> bee_array[10], int *total_row){
	for (int i = 0; i < 10; i++)
      cout << "|      " << i << "     ";
  cout << "|" << endl;

   reorg(ant_array, bee_array, total_row);


  for (int j = 0; j <= *total_row; j++) {
    for (int i = 0; i < 10; i++){
		if (ant_array[i][j].armor < 1){
			if (ant_array[i][j].name == "Fir"){
				for (int a = 0; a < *total_row+1; a++){
					if ( (bee_array[i][a].name == "bee") && (bee_array[i][a].armor > 0))
						bee_array[i][a].armor = bee_array[i][a].armor -1;
				}
			}
			ant_array[i][j].armor = 0;
			ant_array[i][j].name = "   ";
		}

		if (bee_array[i][j].armor < 1){
			bee_array[i][j].armor = 0;
			bee_array[i][j].name = "   ";
		}

      cout << "|" << ant_array[i][j].name << ":" << ant_array[i][j].armor << ", " << bee_array[i][j].name << ":" << bee_array[i][j].armor;
      }
    cout << "|" << endl;

 }
}

//function: Update_add_Ant
//description: returns the row that the ant can be placed at
//parameters: ant and bee array, total_row, and the column user wants to place ant on
//pre: no ant
//post: still no ant but where it is valid to place the ant
int Game::Update_add_Ant(vector<Ant> ant_array[10], vector<Bee> bee_array[10], int *total_row, int ant_col){
    int row = -1;
    for (int i = 0; i <= *total_row; i++) {
      if (ant_array[ant_col][i].name == "   ") { // add Bodyguard ant
        row = i;
        break;
      }
    }

    int temp = *total_row;
    if (row == -1) {

      row = temp +1;
      temp = (*total_row)++;
      upsize_array(ant_array, bee_array, total_row);
    }
    return row;
}

//************************************************************************************************************************************
//function: add_ant_BLANK
//description: adds the specific type of ant that the user selects
//parameters: ant and bees array, number of total row, where user wants to add ant, and the food count
//pre: ant is not there
//post:ant is there
void Game::add_Ant_Harvester(vector<Ant> ant_array[10], vector<Bee> bee_array[10], int *total_row, int ant_col, int *balance){
  Harvester h;
  if (*balance < h.get_food_cost()) {
    cout << "Not enough in Food Bank to add Ant" << endl;
  } else {
    *balance = *balance - h.get_food_cost();

    int row = Update_add_Ant(ant_array, bee_array, total_row, ant_col);

    ant_array[ant_col][row].name = h.get_name();
    ant_array[ant_col][row].armor = h.get_armor();
  }
}

void Game::add_Ant_Thrower(vector<Ant> ant_array[10], vector<Bee> bee_array[10], int *total_row, int ant_col, int *balance){
  Thrower h;
  if (*balance < h.get_food_cost()) {
    cout << "Not enough in Food Bank to add Ant" << endl;
  } else {
    *balance = *balance - h.get_food_cost();

    int row = Update_add_Ant(ant_array, bee_array, total_row, ant_col);

    ant_array[ant_col][row].name = h.get_name();
    ant_array[ant_col][row].armor = h.get_armor();
  }
}

void Game::add_Ant_Fire(vector<Ant> ant_array[10], vector<Bee> bee_array[10], int *total_row, int ant_col, int *balance){
  Fire h;
  if (*balance < h.get_food_cost()) {
    cout << "Not enough in Food Bank to add Ant" << endl;
  } else {
    *balance = *balance - h.get_food_cost();

    int row = Update_add_Ant(ant_array, bee_array, total_row, ant_col);

    ant_array[ant_col][row].name = h.get_name();
    ant_array[ant_col][row].armor = h.get_armor();
  }
}


void Game::add_Ant_LongThrower(vector<Ant> ant_array[10], vector<Bee> bee_array[10], int *total_row, int ant_col, int *balance){
  LongThrower h;
  if (*balance < h.get_food_cost()) {
    cout << "Not enough in Food Bank to add Ant" << endl;
  } else {
    *balance = *balance - h.get_food_cost();

    int row = Update_add_Ant(ant_array, bee_array, total_row, ant_col);

    ant_array[ant_col][row].name = h.get_name();
    ant_array[ant_col][row].armor = h.get_armor();
  }
}


void Game::add_Ant_ShortThrower(vector<Ant> ant_array[10], vector<Bee> bee_array[10], int *total_row, int ant_col, int *balance){
  ShortThrower h;
  if (*balance < h.get_food_cost()) {
    cout << "Not enough in Food Bank to add Ant" << endl;
  } else {
    *balance = *balance - h.get_food_cost();

    int row = Update_add_Ant(ant_array, bee_array, total_row, ant_col);

    ant_array[ant_col][row].name = h.get_name();
    ant_array[ant_col][row].armor = h.get_armor();
  }
}


void Game::add_Ant_Wall(vector<Ant> ant_array[10], vector<Bee> bee_array[10], int *total_row, int ant_col, int *balance){
  Wall h;
  if (*balance < h.get_food_cost()) {
    cout << "Not enough in Food Bank to add Ant" << endl;
  } else {
    *balance = *balance - h.get_food_cost();

    int row = Update_add_Ant(ant_array, bee_array, total_row, ant_col);

    ant_array[ant_col][row].name = h.get_name();
    ant_array[ant_col][row].armor = h.get_armor();
  }
}

void Game::add_Ant_Ninja(vector<Ant> ant_array[10], vector<Bee> bee_array[10], int *total_row, int ant_col, int *balance){
  Ninja h;
  if (*balance < h.get_food_cost()) {
    cout << "Not enough in Food Bank to add Ant" << endl;
  } else {
    *balance = *balance - h.get_food_cost();

    int row = Update_add_Ant(ant_array, bee_array, total_row, ant_col);

    ant_array[ant_col][row].name = h.get_name();
    ant_array[ant_col][row].armor = h.get_armor();
  }
}

void Game::add_Ant_Bodyguard(vector<Ant> ant_array[10], vector<Bee> bee_array[10], int *total_row, int ant_col, int *balance){
  Bodyguard h;
  if (*balance < h.get_food_cost()) {
    cout << "Not enough in Food Bank to add Ant" << endl;
  } else {
    *balance = *balance - h.get_food_cost();

    int row = Update_add_Ant(ant_array, bee_array, total_row, ant_col);

    ant_array[ant_col][row].name = h.get_name();
    ant_array[ant_col][row].armor = h.get_armor();

//  cout << endl << endl <<  "WOO" << endl;


  }
}
//********************************************************************************************************************************


//function: Ant_selection
//description: prints and takes error handles input for menu
//parameters: n/a
//pre: what player wants to do
//post: will either reprompt or move to next function
int Ant_selection(){
	string ans = "";
  do{
    cout << endl << "   Ant       Food Cost  Armor  Action" << endl;
    cout << "1. Harvester     2        1    Adds one food to the colony each turn that it lives" << endl;
    cout << "2. Thrower       4        1    Throws a leaf at one bee sharing its square and inflicts 1 damage to that bee" << endl;
    cout << "3. Fire          4        1    Upon the death of this ant (when armor is zero or less), it reduces all armor values" << endl;
    cout << "                               of bees on the same square to zero." << endl;
    cout << "4. Long Thrower  3        1    Inflicts 1 damage on each bee which is closest to it but at least 4 squares away." << endl;
    cout << "5. Short Thrower 3        1    Inflicts damage on each bee which is closest to it but no more than 2 squares away." << endl;
    cout << "6. Wall          4        4    Occupies a space to block the bees. Cannotattack bees." << endl;
    cout << "7. Ninja         6        1    Cannot block bees and bees cannot attack the ninja. Bees pass by the ninja and incur 1 damage." << endl;
    cout << "8. Bodyguard     4        2    The only ant which may occupy another square which has an ant on it. The bodyguard will be the" << endl;
    cout << "                               ant to incur the damage from any bee which also occupies the square. When the bodyguard ant dies," << endl;
    cout << "                               the next bee attack will hit the other ant on the square. There can only be one bodyguard on a square." << endl << endl;
  //  cout << "9. Quit " << endl;
    cout << "Enter Selection: " ;
    getline(cin,ans);
  }while ((get_int(ans) < 1) || (get_int(ans) > 8));

  return (get_int(ans));
}

//function: ant_colation
//description: prints and takes error handles input for menu
//parameters: n/a
//pre: what player wants to do
//post: will either reprompt or move to next function
int ant_colation(){
  string ans = "";
  do{
    cout << "Enter Ant Location (1 - 9): " ;
    getline(cin,ans);
  }while ((get_int(ans) < 1) || (get_int(ans) > 9));

  return (get_int(ans));
}

//function: add_Ant
//description: prints and takes error handles input for menu
//parameters: n/a
//pre: what player wants to do
//post: will either reprompt or move to next function
bool Game::add_Ant(vector<Ant> ant_array[10], vector<Bee> bee_array[10], int *balance, int *total_row){
	int ant_sel, ant_col;
  int count = 0;

  do{
    ant_sel = Ant_selection();
    ant_col = ant_colation();

    for (int i = 0; i < *total_row +1; i++){
	if (ant_array[ant_col][i].name == "Bod"){
		count++;
	}
}
    if ((ant_array[ant_col][0].name == "   ") || ( (ant_sel == 8) && (count < 1)) || ((ant_sel<8) && (ant_array[ant_col][0].name == "Bod") ))
      break;
    else
      cout << "Ant already exit in this location" << endl;
  }while (1);

  switch (ant_sel) {
    case 1: add_Ant_Harvester(ant_array, bee_array, total_row, ant_col, balance);         break;
    case 2: add_Ant_Thrower(ant_array, bee_array, total_row, ant_col, balance);           break;
    case 3: add_Ant_Fire(ant_array, bee_array, total_row, ant_col, balance);              break;
    case 4: add_Ant_LongThrower(ant_array, bee_array, total_row, ant_col, balance);       break;
    case 5: add_Ant_ShortThrower(ant_array, bee_array, total_row, ant_col, balance);      break;
    case 6: add_Ant_Wall(ant_array, bee_array, total_row, ant_col, balance);              break;
    case 7: add_Ant_Ninja(ant_array, bee_array, total_row, ant_col, balance);             break;
    case 8: add_Ant_Bodyguard(ant_array, bee_array, total_row, ant_col, balance);         break;
  }

  //  cout << "BALANCE = " << *balance << endl << endl;
  return 1;
}

//function: up_Ant_array
//description: copies things over to ant array and makes it one size bigger (columns)
//parameters: ant array and rows
//pre: array is same size
//post: same array but one bigger
void Game::up_Ant_array(vector<Ant> ant_array[10], int *total_row){
  vector <Ant> tmp_array[10];

  for (int i = 0; i < 10; i++) {
    tmp_array[i].resize(*total_row+1);
    for (int j = 0; j < *total_row; j++) {
      tmp_array[i][j].name = ant_array[i][j].name;
      tmp_array[i][j].armor = ant_array[i][j].armor;
      tmp_array[i][j].food_cost = ant_array[i][j].food_cost;
    }

    tmp_array[i][*total_row].name = "   ";
    tmp_array[i][*total_row].armor = 0;
    tmp_array[i][*total_row].food_cost = 0;
  }

  for (int i = 0; i < 10; i++) {
    ant_array[i].resize(*total_row+1);
    for (int j = 0; j <= *total_row; j++) {
      ant_array[i][j].name = tmp_array[i][j].name;
      ant_array[i][j].armor = tmp_array[i][j].armor;
      ant_array[i][j].food_cost = tmp_array[i][j].food_cost;
    }
  }
}
//function: up_bee_array
//description: copies things over to bee array and makes it one size bigger (columns)
//parameters: bee array and rows
//pre: array is same size
//post: same array but one bigger
void Game::up_Bee_array(vector<Bee> bee_array[10], int *total_row){
  vector <Bee> tmp_array[10];

  for (int i = 0; i < 10; i++) {
    tmp_array[i].resize(*total_row+1);
    for (int j = 0; j < *total_row; j++) {
      tmp_array[i][j].name = bee_array[i][j].name;
      tmp_array[i][j].armor = bee_array[i][j].armor;
    }

    tmp_array[i][*total_row].name = "   ";
    tmp_array[i][*total_row].armor = 0;
  }

  for (int i = 0; i < 10; i++) {
    bee_array[i].resize(*total_row+1);
    for (int j = 0; j <= *total_row; j++) {
      bee_array[i][j].name = tmp_array[i][j].name;
      bee_array[i][j].armor = tmp_array[i][j].armor;
    }
  }
}


//function:up_size_array
//description: makes arrays bigger size
//parameters: the arrays and how many rows the array is
//pre: arrays of usual size
//post: array with one row more
void Game::upsize_array(vector<Ant> ant_array[10], vector<Bee> bee_array[10], int *total_row){

  up_Ant_array(ant_array, total_row);
  up_Bee_array(bee_array, total_row);
}

//function: add_bee
//description: adds bee (actually it moves bee over)
//also where ninja "attack" is called
//parameters: arrays and size
//pre: no bee
//post:bee
void Game::add_Bee(vector<Ant> ant_array[10], vector<Bee> bee_array[10], int *total_row){
	for (int i = 0; i < 10; i++){
	  if (bee_array[i][0].name == "bee"){
		if ( (ant_array[i-1][0].name == "   ")  ||  (ant_array[i-1][0].name == "Nin")  ){
			for (int j = 0; j < *total_row + 1; j++){
				if ((j == *total_row) && (bee_array[i-1][j].name == "bee")){
					(*total_row)++;
          upsize_array(ant_array, bee_array, total_row);
          bee_array[i-1][*total_row].name = bee_array[i][0].name;
			    bee_array[i-1][*total_row].armor = bee_array[i][0].armor;
					bee_array[i][0].name = "   ";
					bee_array[i][0].armor = 0;
					for (int k = 0; k < 2; k++){
						if (ant_array[i][k].name == "Nin"){
							bee_array[i-1][*total_row].armor = bee_array[i-1][*total_row].armor -1;
						}
					}
					break;
	   	}
				else if (bee_array[i-1][j].name == "   ") {
          bee_array[i-1][j].name = bee_array[i][0].name;
          bee_array[i-1][j].armor = bee_array[i][0].armor;
					bee_array[i][0].name = "   ";
					bee_array[i][0].armor = 0;
					for (int k = 0; k <= *total_row; k++){
						if (ant_array[i][k].name == "Nin"){
							bee_array[i-1][j].armor = (bee_array[i-1][j].armor) -1;
						}
					}
					break;
				}
			}
	  	 }
	   }
}
}
//function: a_bee
//description: adds the bee at the end of the board
//parameters: vector arrays
//pre: no bee
//post:yes bee
void Game::a_bee(vector<Ant> ant_array[10], vector<Bee> bee_array[10], int *total_row){
	if (ant_array[9][0].name == "   "){
		for (int i = 0; i < *total_row + 1; i++){
			if ( (i == *total_row) && (bee_array[9][*total_row].name == "bee")){
  				(*total_row)++;
 			 	upsize_array(ant_array, bee_array, total_row);
				bee_array[9][*total_row].name == "bee";
				bee_array[9][*total_row].armor == 3;
				break;
			}
			else if (bee_array[9][i].name == "   "){
				bee_array[9][i].name = "bee";
				bee_array[9][i].armor = 3;
				break;

			}
		}
	}

}

//function: attack_bee
//description: handles the attack for beer
//parameters: arrays rows, and index
//pre: no attack from bee
//post: bees attack on column infront of them
void Game::attack_bee(vector<Ant> ant_array[10], vector<Bee> bee_array[10], int *total_row){

		for (int i = 0; i < 10 ; i++){
			for (int j = 0; j <= *total_row ; j++){
				if (bee_array[i][j].name == "bee"){

						if (ant_array[i-1][0].name == "Bod"){
							ant_array[i-1][0].armor = ant_array[i-1][0].armor -1;

							break;
						}
						else if (ant_array[i-1][j].name == "Nin")
							ant_array[i-1][j].armor = ant_array[i-1][j].armor;
						else if (ant_array[i-1][j].name != "   ")	{
							ant_array[i-1][j].armor = ant_array[i-1][j].armor -1;
						}
				}
			}
		}
	}

	void Game::attack_har(vector <Ant> ant_array[10], vector <Bee> bee_array[10], int *total_row, int *bank, int i, int j){
		Harvester h;
		*bank = *bank + h.attack_Harvester();
	}


	//function: attack_thrower
	//description: handles the attack for Thrower
	//parameters: arrays rows, and index
	//pre: no attack from Thrower
	//post: possible damage to bee
	void Game::attack_thr(vector <Ant> ant_array[10], vector <Bee> bee_array[10], int *total_row, int *bank, int i, int j){
		Thrower t;
		for (int a = 0; a < *total_row+1; a++){
			if ( (bee_array[i][a].name == "bee") && (bee_array[i][a].armor > 0)){
				bee_array[i][a].armor = bee_array[i][a].armor -1;
			}
		}
	}

	//void Game::attack_fire(vector <Ant> ant_array[10], vector <Bee> bee_array[10], int *total_row, int *bank, int i, int j){

//	}

	//function: attack_shortthrower
	//description: handles the attack for add_Ant_ShortThrower
	//parameters: arrays rows, and index
	//pre: no attack from ShortThrower
	//post: possible damage to bee
	void Game::attack_longthrower(vector <Ant> ant_array[10], vector <Bee> bee_array[10], int *total_row, int *bank, int i, int j){

		LongThrower t;

		int hold = 12, b = 0, small = 0, u = 12, s = 0;
		for (int x = i+4; x < 10; x++){
			for (int w = 0; w < *total_row+1; w++){
				if (bee_array[x][w].name == "bee"){

					hold = x;
					b = 1;
					break;
				}
			if (b == 1)
				break;
			}
		}


	if (hold < 11){
		for (int t = 0; t < *total_row+1; t++){
			if (bee_array[hold][t].armor > 0){
				bee_array[hold][t].armor = bee_array[hold][t].armor -1;
			}
		}
	}

	}

	void Game::attack_shortthrower(vector <Ant> ant_array[10], vector <Bee> bee_array[10], int *total_row, int *bank, int i, int j){
			ShortThrower s;
	//		cout << "WHAT THE SHIT " << endl;
			for (int x = i; x < i +3; x++){
				for (int o = 0; o < *total_row+1; o++){
						if ((bee_array[x][o].name == "bee") && (bee_array[x][o].armor >0))
							bee_array[x][o].armor = bee_array[x][o].armor -1;
					}
				}
			}


			//function: attack_ants
			//description: main attack function
			//parameters: ants array and bee array
			//pre: no attack
			//post:yes attack
	void Game::attack_ants(vector <Ant> ant_array[10], vector <Bee> bee_array[10], int *total_row, int *bank){

		for (int i = 0; i < 10 ; i++){
			for (int j = 0; j < *total_row+1; j++){
				if (ant_array[i][j].name != "   "){
						if (ant_array[i][j].name == "Har")
							attack_har(ant_array,bee_array,total_row, bank,i,j);
						else if (ant_array[i][j].name == "Thr"){
							attack_thr(ant_array,bee_array,total_row, bank,i,j);
						}
	//					else if (ant_array[i][j].name == "Fir")
	//						attack_fire(ant_array,bee_array,total_row, bank,i,j);
						else if (ant_array[i][j].name == "Lon"){
							attack_longthrower(ant_array,bee_array,total_row, bank,i,j);
					//		cout << "AHHHHHHHHHHHHHHHHHHHHHHHHH" << endl << endl << endl << endl;
						}
						else if (ant_array[i][j].name == "Sho")
							attack_shortthrower(ant_array,bee_array,total_row, bank,i,j);
				}
			}
		}
	}

	//function: check_win
	//description: checks if game has been won
	//parameters: arrayd and totoal size and amount in bank
	//pre: game is still being played
	//post: whether or not the game is done
int Game::check_win(vector<Ant> ant_array[10], vector<Bee> bee_array[10], int *total_row, int* bank){
	int end = 0;
	int woop = 0;

	if (*bank < 2){
		cout << "OUT OF MONEY TO BUY ANT" << endl;
	}

	for (int i = 0; i < 10; i++){
		if (woop == 1)
			break;
		if (*total_row > 0){
			for (int r = 0; r <2; r++){
				if (ant_array[i][r].name == "   ")
					break;
				if ( (i == 1) && (r == 9)){
					if (ant_array[i][r].name != "   "){
						end =1;
					}
				}
			}
		}
		for (int j = 0; j <= *total_row; j++){
			if(bee_array[1][j].name == "bee"){
				cout << "Uh oh. The bees won.." << endl;
				end = 1;
				woop = 1;
				break;
			}
			else if ( bee_array[i][j].name == "bee"){
				end = 0;
				woop = 1;
				break;
			}
			else if ((i == 9) && ( j == *total_row) && ( bee_array[i][j].name == "   ")){
				end = 1;
				woop = 1;
				cout << "ALL THE BEES HAVE DEFEATED. YOU WON!" << endl;
				break;
			}
		}
	}
	return end;
}


//function: lets play game
//description: main function to call other function, acts like a main
//parameters: none
//pre: no game
//post: game gets played
void Game::letsplaygame(){

  int * bank;
  int initial = 50;
  bank = &initial;
  int * total_row;
  int initial1 = 0;
  total_row = &initial1;

  vector <Bee> bee_array[10];
  vector <Ant> ant_array[10];


	DefaultBoard(ant_array, bee_array);

  do {

	a_bee(ant_array, bee_array, total_row);
  if (bool continuegame = add_Ant(ant_array, bee_array, bank, total_row) == 0) break;
	cout << "Bank: " << *bank << endl << endl;
	cout << endl << "Board after adding ant" << endl;
	UpdateBoard(ant_array, bee_array, total_row);
	add_Bee(ant_array, bee_array, total_row);
	attack_ants(ant_array,bee_array,total_row, bank);
	cout << endl <<"Board after ant attacks & new bee" << endl;

	UpdateBoard(ant_array, bee_array, total_row);

	attack_bee(ant_array, bee_array, total_row);
	cout << endl <<  "Board after bee attacks" << endl;

	UpdateBoard(ant_array, bee_array, total_row);

} while ( check_win(ant_array,bee_array,total_row,bank) == 0 );


}
