#include <iostream>
#include <string>
#include <vector>
#include "bee.h"
#include "ant.h"
#include "insect.h"

#include "harvester.h"
#include "thrower.h"
#include "fire.h"
#include "longthrower.h"
#include "shortthrower.h"
#include "wall.h"
#include "ninja.h"
#include "bodyguard.h"

#ifndef GAME_H
#define GAME_H

using namespace std;

class Game{
	public:
    int num_ants;
    int num_bees;
    Game();
    void letsplaygame();
    int Update_add_Ant(vector<Ant> [], vector<Bee> [], int *, int);
    void add_Ant_Harvester(vector<Ant> [], vector<Bee> [], int *, int, int *);
    void add_Ant_Thrower(vector<Ant> [], vector<Bee> [], int *, int, int *);
    void add_Ant_Fire(vector<Ant> [], vector<Bee> [], int *, int, int *);
    void add_Ant_LongThrower(vector<Ant> [], vector<Bee> [], int *, int, int *);
    void add_Ant_ShortThrower(vector<Ant> [], vector<Bee> [], int *, int, int *);
    void add_Ant_Wall(vector<Ant> [], vector<Bee> [], int *, int, int *);
    void add_Ant_Ninja(vector<Ant> [], vector<Bee> [], int *, int, int *);
    void add_Ant_Bodyguard(vector<Ant> [], vector<Bee> [], int *, int, int *);
    bool add_Ant(vector<Ant> [], vector<Bee> [], int *, int *);
    void up_Ant_array(vector<Ant> [], int *);
    void up_Bee_array(vector<Bee> [], int *);
    void upsize_array(vector<Ant> [], vector<Bee> [], int *);
    void add_Bee(vector<Ant> [], vector<Bee> [], int *);
    void DefaultBoard(vector<Ant> [], vector<Bee> []);
    void UpdateBoard(vector<Ant> [], vector<Bee> [], int *);

    void a_bee(vector<Ant> [], vector<Bee> [], int *);
    void attack_bee(vector<Ant> [], vector<Bee> [], int *);

    void reorg(vector<Ant> [], vector<Bee> [], int *);
    void attack_ants(vector<Ant> [], vector<Bee> [], int *, int *);
		void attack_har(vector<Ant> [], vector<Bee> [], int *, int *, int,int);
		void attack_thr(vector<Ant> [], vector<Bee> [], int *, int *,int,int);
	//	void attack_fire(vector<Ant> [], vector<Bee> [], int *, int *,int,int);
		void attack_longthrower(vector<Ant> [], vector<Bee> [], int *, int *,int,int);
		void attack_shortthrower(vector<Ant> [], vector<Bee> [], int *, int *,int,int);
    int check_win(vector<Ant> [], vector<Bee> [], int *, int *);
   // add_Bee(ant_array, bee_array, total_row);
};

int get_int(string bin);
int Ant_selection();
int Ant_location();

#endif
