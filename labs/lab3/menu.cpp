#include "menu.h"
#include <string>
#include "pizza.h"
using namespace std;

Menu::Menu(){
	num_pizzas = 0;
	pizzas = NULL;
}

Menu::Menu(const Menu& copy){
	num_pizzas = copy.num_pizzas;
	if (num_pizzas == 0)
		pizzas = NULL;
	else {
		pizzas = new Pizza[num_pizzas];
		for (int i = 0; i < num_pizzas; i++){
			pizzas[i] = copy.pizzas[i];
		}

	}

}


const Menu & Menu:: operator=(const Menu& copy){

	num_pizzas = copy.num_pizzas;
	if (pizzas != NULL)
		delete [] pizzas;
	if (num_pizzas == 0)
		pizzas = NULL;
	else {
		pizzas = new Pizza[num_pizzas];
		for (int i = 0; i < num_pizzas; i++){
			pizzas[i] = copy.pizzas[i];
		}

	}
	return *this;


}
int Menu:: get_num_pizzas()const{
	return num_pizzas;
}

//i think i did this wrong
Pizza * Menu:: get_pizzas()const{
	return pizzas;
}

void Menu:: set_num_pizzas(int pizzas){
	num_pizzas = pizzas;
}


void Menu:: set_pizzas(Pizza * food){
	pizzas = food;
}
Menu :: ~Menu(){
	delete [] pizzas;

}


