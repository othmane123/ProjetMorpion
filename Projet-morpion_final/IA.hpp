 #ifndef IA_HPP
 #define IA_HPP

 #include <iostream>
 #include <vector>
 #include <SFML/Graphics.hpp>
 #include "Board.hpp"
 #include "menu.hpp"
 #include <SFML/Audio.hpp>

 class IA
 {
 public:

   IA();
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
   void Xwin();
   void Owin();
   void musiccc();

 private:


   sf::RenderWindow                  mWindow;

   sf::Texture                       mXTexture;
   sf::Texture                       mOTexture;
   std::vector<sf::Sprite>           mShapes;

   std::vector<sf::RectangleShape>   mGrid;

   Player                            mPlayer;
   Outcome                           mOutcome;
   Board                             mBoard;
   sf::Text                          text;
   sf::Font                          font;
   sf::Event                         event;
 };

 #endif
