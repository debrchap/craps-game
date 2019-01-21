#ifndef craps_h
#define craps_h
#include <iostream>
#include <time.h>
#include <string>

using namespace std;

#define WIN 100

//function prototypes
int beginGame();
int flipCoin();
string namePlayer(int);
int rollDie();
int getKeepGoing();
int endTurn();

#endif
