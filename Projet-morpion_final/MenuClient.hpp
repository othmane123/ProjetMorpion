 #ifndef MENUCLIENT_HPP
 #define MENUCLIENT_HPP

 #include <iostream>
 #include <vector>
 #include <SFML/Graphics.hpp>
 #include "Board.hpp"
 #include "menu.hpp"
 #include <SFML/Audio.hpp>
 #include <SFML/Network.hpp>

 class MenuClient
 {
 public:

   MenuClient();
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
   void send(sf::Packet &paquet);
   void receive(sf::Packet &paquet);
   void test();

 private:


 unsigned short Port;

   sf::RenderWindow                  mWindow;
std::size_t Received;
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
   sf::TcpSocket                     socket; //utilisation socket tcp
   sf::IPAddress ip;
   sf::IPAddress Sender;
   sf::IPAddress adresseServeur;
 };

 #endif
