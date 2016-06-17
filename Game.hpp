//  Created by Othmane Haddou on 15/06/2016.
//  Copyright © 2016 Othmane Haddou. All rights reserved.
//

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Board.hpp"

class Game
{
public:

  Game();
  void run();

private:

  void processEvents();
  void render();
  void displayOutcome();
  void resetGame();

  Square squareClicked(int x, int y);
  void addSprite(Square square);
  void updateOutcome();
  void swapPlayer();

private:

  sf::RenderWindow                  mWindow;

  sf::Texture                       mXTexture;
  sf::Texture                       mOTexture;
  std::vector<sf::Sprite>           mShapes;

  std::vector<sf::RectangleShape>   mGrid;

  Player                            mPlayer;
  Outcome                           mOutcome;
  Board                             mBoard;
};

#endif
