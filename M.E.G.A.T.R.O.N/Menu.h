#pragma once
#include<SFML/Graphics.hpp>

#define MAX_BAR 3

class Menu
{
public:
	Menu(int W,int H);
	~Menu();

	void draw(sf::RenderWindow& window);
	void Up();
	void Down();

private:
		int SelectBar;
		sf::Font font;
		sf::Text menu[MAX_BAR];
};

