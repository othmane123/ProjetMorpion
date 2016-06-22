#ifndef BOARD_HPP
#define BOARD_HPP
#include <SFML/Audio.hpp>
#include <map>

enum Player  {X_PLAYER  = 1,
              O_PLAYER  = 2};

enum Square  {TOPLEFT       = 2,
              TOPMIDDLE     = 7,
              TOPRIGHT      = 6,
              MIDDLELEFT    = 9,
              CENTER        = 5,
              MIDDLERIGHT   = 1,
              BOTTOMLEFT    = 4,
              BOTTOMMIDDLE  = 3,
              BOTTOMRIGHT   = 8,
              UNKNOWN       = 0};

enum State   {EMPTY         = 0,
              CROSS         = 1,
              CIRCLE        = 2};

enum Outcome {UNFINISHED    = 0,
              X_WINS        = 1,
              O_WINS        = 2,
              DRAW          = 3};

class Board
{
public:

  Board();

  void init();
  bool addMove(Player player,Square square);
  Outcome checkOutcome();

private:

  std::map<Square,State> mGameBoard;
};

#endif
