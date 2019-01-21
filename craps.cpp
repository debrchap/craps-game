#include "craps.h"

int beginGame() {
  cout << "Craps Game\n\n";
  //randomly assign first player
  int player = flipCoin();
  //let user know who's going first
  cout << "Let's begin! The first player is " << namePlayer(player) << ".\n\n";
  return player;
}

int flipCoin() {
  return rand()%2;
}

string namePlayer(int player) {
  if (player==0)
    return "the user";
  else
    return "the computer";
}

int rollDie() {
  return ((rand()%6) + 1);
}

int getKeepGoing() {
  int keep_going;
  cout << " Do you want to roll again this turn? (1 for yes, 0 for no) ";
  cin >> keep_going;
  //Make sure user entered good data
  while ((cin.fail()) || !( (keep_going==0) || (keep_going==1) ))
  {
    //Clear the buffer and have cin ignore any bad data entered
    cin.clear();
    cin.ignore();
    cout << "<!> You did not enter 1 or 0. Please enter 1 to roll again, 0 to stop: ";
    cin >> keep_going;
  }
  return keep_going;
}

int endTurn() {
  string s="";
  s.assign(75,'-');
  //display a line at end of each turn
  cout << s << endl;
  return 0;
}
