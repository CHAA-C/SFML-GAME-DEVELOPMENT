#pragma once
#include<SFML\Graphics.hpp>
#define MAX_ITEMS 3

class MenuClass
{
public:
	MenuClass(float width, float height);
	~MenuClass();

	void draw(sf::RenderWindow& window);
	void Up();
	void Down();
	int getPress() { return selectItem; }

private:
	int selectItem=0;
	sf::Font font;
	sf::Text menu[MAX_ITEMS];
};

