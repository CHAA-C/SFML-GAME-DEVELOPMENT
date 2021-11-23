#include "MenuClass.h"
MenuClass::MenuClass(float width, float height)
{
	if (!font.loadFromFile("font/tahomabd.ttf"))
	{
		// handle error
	}
	menu[0].setFont(font);
	menu[0].setCharacterSize(40);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("PLAY");
	menu[0].setOrigin(menu[0].getLocalBounds().width/2, menu[0].getLocalBounds().height/2);
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS+1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Green);
	menu[1].setString("SCOREBOARD");
	menu[1].setOrigin(menu[1].getLocalBounds().width / 2, menu[1].getLocalBounds().height / 2);
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS+1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::Green);
	menu[2].setString("EXIT");
	menu[2].setOrigin(menu[2].getLocalBounds().width / 2, menu[2].getLocalBounds().height / 2);
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS+1) * 3));
}
MenuClass::~MenuClass()
{

}

void MenuClass::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_ITEMS ; i++)
	{
		window.draw(menu[i]);
	}
}

void MenuClass::Up()
{
	if (selectItem - 1 >= 0)
	{
		menu[selectItem].setFillColor(sf::Color::Green);
		selectItem--;
		menu[selectItem].setFillColor(sf::Color::Red);
		 
	}
}

void MenuClass::Down()
{
	if (selectItem + 1 < MAX_ITEMS)
	{
		menu[selectItem].setFillColor(sf::Color::Green);
		selectItem++;
		menu[selectItem].setFillColor(sf::Color::Red);

	}
}