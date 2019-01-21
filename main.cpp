#include "craps.h"

int main() {
  //seed the random generator based on the time the program was started
  srand(time(0));
  int die=0, turn_score=0, user_score=0, comp_score=0;
  int player = beginGame();
  //Keep looping through turns until one of the players wins
  while ((user_score < WIN) && (comp_score < WIN))
  {
    bool keep_going = true;
    //needs to be in switch format to allow the first player to be either the user or the computer
    switch (player)
    {
      //User
      case 0:
            cout << "Your turn:" <<endl;
            do
            {
              die = rollDie();
              //Stop user turn if they roll a 1
              if (die == 1)
              {
                cout << "You rolled a 1! Your turn score is 0. Better luck next turn." <<endl;
                turn_score = 0;
                keep_going = false;
              }
              //Otherwise, add die roll to turn score and ask if player wants to go again
              else
              {
                turn_score += die;
                cout << "Roll: " << die << "\nYour turn score is " << turn_score << ".";
                keep_going = getKeepGoing();
              }
            }
            while (keep_going);
            //Add turn score to permanent user score once user is done rolling
            user_score += turn_score;
            cout << "Current score: " << user_score << endl;
            //Reset turn score before used in next case by computer
            turn_score = endTurn();
      //Computer
      case 1:
            cout << "Computer's turn:" <<endl;
            do
            {
              die = rollDie();
              //Stop computer's turn if it rolls a 1
              if (die == 1)
              {
                cout << "The computer rolled a 1! The computer scores a 0 this turn." <<endl;
                turn_score = 0;
                keep_going = false;
              }
              //Otherwise, add die roll to turn score and determine if computer rolls again
              else
              {
                turn_score += die;
                cout << "Roll: " << die << "\nThe computer's turn score is " << turn_score << ". ";
                //Determine if computer rolls again by flipping coin
                keep_going = flipCoin();
                if (keep_going) cout << "The computer is going to roll again." <<endl;
                else cout << "The computer ends its turn." <<endl;
              }
            }
            while(keep_going);
            //Add turn score to permanent computer score once computer is done rolling
            comp_score += turn_score;
            cout << "Current score: " << comp_score << endl;
            //Reset turn score before used in next loop by user
            turn_score = endTurn();
    }
    //Give the next turn to the user in the next loop go-around
    player = 0;
  }

  //Declare winner
  if (user_score >= WIN) cout << "You win with a score of " << user_score << "! Good game!" <<endl;
  else cout << "The computer wins with a score of " << comp_score << "! Better luck next time!" <<endl;
  
  return 0;
}
