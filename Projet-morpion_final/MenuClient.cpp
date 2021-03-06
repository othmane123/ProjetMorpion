#include <SFML/Network.hpp>
#include "Game.hpp"
#include "menu.hpp"
#include "MenuClient.hpp"
#include "MenuClient.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

MenuClient::MenuClient() :
  mWindow(sf::VideoMode(430, 430, 32), "Tic-Tac-Toe en SFML!"),
  mXTexture(),
  mOTexture(),
  mShapes(),
  mGrid(),
  mPlayer(X_PLAYER),
  mOutcome(UNFINISHED),
  mBoard()
{
  if (!mXTexture.loadFromFile("assets/cross.png"))
  {
    std::cerr << "ERROR : Image not found !" << std::endl;
  }
  if (!mOTexture.loadFromFile("assets/circle.png"))
  {
    std::cerr << "ERROR : Image not found !" << std::endl;
  }

  sf::RectangleShape vert1(sf::Vector2f(5, 410));
  vert1.setFillColor(sf::Color::Black);
  vert1.setPosition(140,10);
  mGrid.push_back(vert1);

  sf::RectangleShape vert2(sf::Vector2f(5, 410));
  vert2.setFillColor(sf::Color::Black);
  vert2.setPosition(285,10);
  mGrid.push_back(vert2);

  sf::RectangleShape hori1(sf::Vector2f(410, 5));
  hori1.setFillColor(sf::Color::Black);
  hori1.setPosition(10,140);
  mGrid.push_back(hori1);

  sf::RectangleShape hori2(sf::Vector2f(410, 5));
  hori2.setFillColor(sf::Color::Black);
  hori2.setPosition(10,285);
  mGrid.push_back(hori2);
}

void MenuClient::run()
{
  while (mWindow.isOpen())
  {
//    musiccc();
    processEvents();
    render();
}
}

void MenuClient::processEvents()
{
  sf::Event event;
  while (mWindow.pollEvent(event))
  {
      if (event.type==sf::Event::KeyPressed)
     {
      switch(event.key.code)
      {
        case sf::Keyboard::Escape:
             mWindow.close();
             break;
        case sf::Keyboard::Return: //retour menu
             break;
        case sf::Keyboard::R:
              resetGame();

        break;
     }}
    switch (event.type)
    {
    case sf::Event::MouseButtonPressed:
      if (event.mouseButton.button == sf::Mouse::Left)
      {
        Square square(squareClicked(event.mouseButton.x,event.mouseButton.y));
        if (square != UNKNOWN)
        {
          if (mBoard.addMove(mPlayer,square))
          {
            addSprite(square);
            updateOutcome();
            displayOutcome();
            if (mOutcome == UNFINISHED)
              swapPlayer();
            else
               // Xwin();
              resetGame();

          }
        }
      }
      break;

    case sf::Event::Closed:
      mWindow.close();
      break;
    }
  }
}

void MenuClient::render()
{
  mWindow.clear(sf::Color::White);

  for(int i(0) ; i < mGrid.size() ; i++)
  {
    mWindow.draw(mGrid[i]);
  }

  for(int i(0) ; i < mShapes.size() ; i++)
  {
    mWindow.draw(mShapes[i]);
  }

  mWindow.display();
}

void MenuClient::displayOutcome()
{

  switch (mOutcome)
  {
  case X_WINS:
    std::cout << "X WINS !" << std::endl;
    Xwin();
    break;

  case O_WINS:
    std::cout << "O WINS !" << std::endl;
    break;

  case DRAW:
    std::cout << "It's a draw.." << std::endl;
    break;
  }
}

void MenuClient::resetGame()
{
  mShapes.clear();
  mPlayer = X_PLAYER;
  mOutcome = UNFINISHED;
  mBoard.init();
}

Square MenuClient::squareClicked(int x, int y)
{
  if(x >= 0 && x <= 140)
  {
    if(y >= 0 && y <= 140)
      return TOPLEFT;
    if(y >= 145 && y <= 285)
      return MIDDLELEFT;
    if(y >= 290 && y <= 430)
      return BOTTOMLEFT;
  }
  if(x >= 145 && x <= 285)
  {
    if(y >= 0 && y <= 140)
      return TOPMIDDLE;
    if(y >= 145 && y <= 285)
      return CENTER;
    if(y >= 290 && y <= 430)
      return BOTTOMMIDDLE;
  }
  if(x >= 290 && x <= 430)
  {
    if(y >= 0 && y <= 140)
      return TOPRIGHT;
    if(y >= 145 && y <= 285)
      return MIDDLERIGHT;
    if(y >= 290 && y <= 430)
      return BOTTOMRIGHT;
  }
  return UNKNOWN;
}

void MenuClient::addSprite(Square square)
{
  sf::Sprite sprite;

  if(mPlayer == X_PLAYER)
    sprite.setTexture(mXTexture);
  if(mPlayer == O_PLAYER)
    sprite.setTexture(mOTexture);

  switch (square)
  {
  case TOPLEFT:
    sprite.setPosition(10,10);
    break;

  case TOPMIDDLE:
    sprite.setPosition(155,10);
    break;

  case TOPRIGHT:
    sprite.setPosition(300,10);
    break;

  case MIDDLELEFT:
    sprite.setPosition(10,155);
    break;

  case CENTER:
    sprite.setPosition(155,155);
    break;

  case MIDDLERIGHT:
    sprite.setPosition(300,155);
    break;

  case BOTTOMLEFT:
    sprite.setPosition(10,300);
    break;

  case BOTTOMMIDDLE:
    sprite.setPosition(155,300);
    break;

  case BOTTOMRIGHT:
    sprite.setPosition(300,300);
    break;
  }

  mShapes.push_back(sprite);
}

void MenuClient::updateOutcome()
{
  mOutcome = mBoard.checkOutcome();
}

void MenuClient::swapPlayer()
{
  if(mPlayer == X_PLAYER)
    mPlayer = O_PLAYER;
  else
    mPlayer = X_PLAYER;
}

void MenuClient::Xwin()
{
sf::Font MyFont;
if (!MyFont.loadFromFile("Arial.ttf"))
    {
    std::cout << "Probleme chargement fichier Arial" << std::endl;
    }
sf::Text text;

text.setFont(MyFont);
text.setString("X A GAGNE !!!!!");
text.setCharacterSize(10);
text.setColor(sf::Color::Red);
mWindow.clear();
mWindow.draw(text);
mWindow.display();
}

MenuClient::test()
{


sf::TcpSocket socket;
sf::Socket::Status status = socket.connect("192.168.0.100", 53000);
if (status != sf::Socket::Done)
{
    std::cout << "ereur du client" << std::endl;
     IPAddress localaddress = IPAddress::LocalHost;
    IPAddress clientaddress;
    SocketTCP Listener;
    SocketTCP client;
    if(!Listener.Listen(4567))
        cout << "Erreur";
    if(Listener.Accept(client, &clientaddress) != Socket::Done)
        cout << "Erreur";
    if(client.Connect(4567, IPAddress::LocalHost) != Socket::Done)
        cout << "Erreur";


}
}
