//  Created by Othmane Haddou on 11/06/2016.
//  Copyright © 2016 Othmane Haddou. All rights reserved.
//

#include "Board.hpp"

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
}
