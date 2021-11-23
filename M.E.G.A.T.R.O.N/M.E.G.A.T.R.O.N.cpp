#include<SFML/Graphics.hpp>
#include"MenuClass.h"
#include"Game.h"
#include "Scoreboard.h"
#include<stdio.h>
#include<time.h>
#include <stdlib.h>
#include "Playername.h"

using namespace std;

int main()
{
	srand(time(NULL));
	
	

	sf::RenderWindow MENU(sf::VideoMode(110*17, 50*17), "M.E.G.A.T.R.O.N");
	MenuClass menu(MENU.getSize().x, MENU.getSize().y);

	

	while (MENU.isOpen())
	{
		sf::Event e;
		while (MENU.pollEvent(e))
		{
			switch (e.type)
			{
			case sf::Event::KeyReleased:
				switch (e.key.code)
				{
				case sf::Keyboard::PageUp:
					menu.Up();
					break;

				case sf::Keyboard::PageDown:
					menu.Down();
					break;

				case sf::Keyboard::Return:
					switch (menu.getPress())
					{
					case 0 :
					{
						Game game;
						game.run();
						
					}
						break;

					case 1:
					{
						Scoreboard scoreboard;
						scoreboard.open();
					}
						break;
					
					case 2 :
						MENU.close(); 
					}
				}
				break;

			case sf::Event::Closed:
				MENU.close();
				break;
			}
		}

		sf::Text name,head;
		sf::Font font;
		font.loadFromFile("font/tahomabd.ttf");
		name.setFont(font);
		name.setCharacterSize(20);
		name.setFillColor(sf::Color::White);
		name.setString(" Developed By 64010251 Nuttapat Ngammuk																																	PageUp and PageDown To Scroll and Enter to Select");
		name.setPosition(30, 800);

		head.setFont(font);
		head.setCharacterSize(120);
		head.setFillColor(sf::Color::White);
		head.setString("M.E.G.A.T.R.O.N");
		head.setPosition(450, 10);


		MENU.clear();
		menu.draw(MENU);
		MENU.draw(name);
		MENU.draw(head);
		MENU.display();
	}
	
	return 0;
}
