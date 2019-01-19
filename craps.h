#include <iostream>
#include <time.h>
#include <string>
#ifndef CRAPS_H
#define CRAPS_H
using namespace std;

#define WIN 100
//initializing variables needed by multiple functions
int die=0, turn_score=0;
string player_name="";

//function prototypes
int flipCoin();
string namePlayer(int);
int rollDie();
int getKeepGoing();
void endTurn(string);

#endif
