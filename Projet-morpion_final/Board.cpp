#include "Board.hpp"
#include <SFML/Audio.hpp>

Board::Board()
{
  mGameBoard[TOPLEFT]       = EMPTY;
  mGameBoard[TOPMIDDLE]     = EMPTY;
  mGameBoard[TOPRIGHT]      = EMPTY;
  mGameBoard[MIDDLELEFT]    = EMPTY;
  mGameBoard[CENTER]        = EMPTY;
  mGameBoard[MIDDLERIGHT]   = EMPTY;
  mGameBoard[BOTTOMLEFT]    = EMPTY;
  mGameBoard[BOTTOMMIDDLE]  = EMPTY;
  mGameBoard[BOTTOMRIGHT]   = EMPTY;
}

void Board::init()
{
  mGameBoard[TOPLEFT]       = EMPTY;
  mGameBoard[TOPMIDDLE]     = EMPTY;
  mGameBoard[TOPRIGHT]      = EMPTY;
  mGameBoard[MIDDLELEFT]    = EMPTY;
  mGameBoard[CENTER]        = EMPTY;
  mGameBoard[MIDDLERIGHT]   = EMPTY;
  mGameBoard[BOTTOMLEFT]    = EMPTY;
  mGameBoard[BOTTOMMIDDLE]  = EMPTY;
  mGameBoard[BOTTOMRIGHT]   = EMPTY;
}

bool Board::addMove(Player player,Square square)
{
  if(mGameBoard[square] == EMPTY)
  {
    if(player == X_PLAYER)
    {
      mGameBoard[square] = CROSS;
      return true;
    }
    if(player == O_PLAYER)
    {
      mGameBoard[square] = CIRCLE;
      return true;
    }
  }

  return false;
}

Outcome Board::checkOutcome()
{
  int row1 = (mGameBoard[TOPLEFT]*TOPLEFT) + (mGameBoard[TOPMIDDLE]*TOPMIDDLE) + (mGameBoard[TOPRIGHT]*TOPRIGHT);
  int row2 = (mGameBoard[MIDDLELEFT]*MIDDLELEFT) + (mGameBoard[CENTER]*CENTER) + (mGameBoard[MIDDLERIGHT]*MIDDLERIGHT);
  int row3 = (mGameBoard[BOTTOMLEFT]*BOTTOMLEFT) + (mGameBoard[BOTTOMMIDDLE]*BOTTOMMIDDLE) + (mGameBoard[BOTTOMRIGHT]*BOTTOMRIGHT);
  int col1 = (mGameBoard[TOPLEFT]*TOPLEFT) + (mGameBoard[MIDDLELEFT]*MIDDLELEFT) + (mGameBoard[BOTTOMLEFT]*BOTTOMLEFT);
  int col2 = (mGameBoard[TOPMIDDLE]*TOPMIDDLE) + (mGameBoard[CENTER]*CENTER) + (mGameBoard[BOTTOMMIDDLE]*BOTTOMMIDDLE);
  int col3 = (mGameBoard[TOPRIGHT]*TOPRIGHT) + (mGameBoard[MIDDLERIGHT]*MIDDLERIGHT) + (mGameBoard[BOTTOMRIGHT]*BOTTOMRIGHT);
  int diag1 = (mGameBoard[TOPLEFT]*TOPLEFT) + (mGameBoard[CENTER]*CENTER) + (mGameBoard[BOTTOMRIGHT]*BOTTOMRIGHT);
  int diag2 = (mGameBoard[BOTTOMLEFT]*BOTTOMLEFT) + (mGameBoard[CENTER]*CENTER) + (mGameBoard[TOPRIGHT]*TOPRIGHT);

  if (row1 == 15 || row2 == 15 || row3 == 15 || col1 == 15 || col2 == 15 || col3 == 15 || diag1 == 15 || diag2 == 15)
    return X_WINS;
  if (row1 == 30 || row2 == 30 || row3 == 30 || col1 == 30 || col2 == 30 || col3 == 30 || diag1 == 30 || diag2 == 30)
    return O_WINS;

  for (std::map<Square,State>::iterator it = mGameBoard.begin() ; it != mGameBoard.end() ; ++it)
  {
    if (it->second == EMPTY)
      return UNFINISHED;
  }

  return DRAW;
}
