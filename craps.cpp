int flipCoin() {
  int coin = 0;
  coin = rand()%2;
  return coin;
}

string namePlayer(int player) {
  if (player==0) player_name = "the user";
  else player_name = "the computer";
  return player_name;
}

int rollDie() {
  die = (rand()%6) + 1;
  return die;
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

void endTurn(string s) {
  turn_score = 0;
  cout << s <<endl;
}
