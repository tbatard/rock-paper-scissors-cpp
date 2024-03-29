#ifndef ROCK_PAPER_SCISSORS_C___ROCKPAPERSCISSORSAPP_H
#define ROCK_PAPER_SCISSORS_C___ROCKPAPERSCISSORSAPP_H

#include "RockPaperScissors.h"

class RockPaperScissorsApp {
protected:
  RockPaperScissors* rockPaperScissors;
public:
  void start(std::istream& input);

  explicit RockPaperScissorsApp(RockPaperScissors* rps)
  {
    rockPaperScissors = rps;
  }

  void displayChoices();
  static Choice mapInputToChoice(int input);

  void determineWinner(Choice playerChoice, Choice iaChoice);
};


#endif //ROCK_PAPER_SCISSORS_C___ROCKPAPERSCISSORSAPP_H
