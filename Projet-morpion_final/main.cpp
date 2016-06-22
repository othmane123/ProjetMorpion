#include "Game.hpp"
#include "menu.hpp"
#include "IA.hpp"
#include "MenuClient.hpp"
#include "MenuServeur.hpp"

int main()
{

     sf::Music music;
if (!music.openFromFile("MainMusic.ogg"))
     std::cout << "Probleme chargement fichier audio" << std::endl;
music.play();

int x=0;
int y=0;

    	sf::RenderWindow window(sf::VideoMode(500, 450), "MORPION");

	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
		sf::Event event;


		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
                        x=x+1;
					    std::cout << "Joueur contre joueur" << std::endl;
						window.close();
						break;
					case 1:
					    x=x-1;
						std::cout << "Joueur contre IA" << std::endl;
						window.close();
						break;

					case 2:
					    std::cout << "Partie multi" << std::endl;
						window.close();
						y=y+1;
						break;

                    case 3:
					    std::cout << "Vous avez quitter" << std::endl;
						window.close();
						break;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

		window.clear();

		menu.draw(window);

		window.display();
	}
if (x>0)
{
   Game game;
  game.run();
}

    else if (x<0)
          {
     IA ia;
     ia.run();
    }
else if (y>0)
{

    MenuClient client;
    client.run();
}
    return 0;

}

