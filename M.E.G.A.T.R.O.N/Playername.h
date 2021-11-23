#pragma once
#include<SFML/Graphics.hpp>
#include<sstream>
#include<iostream>
#include<fstream>

using namespace std;

#define BACKSPACE 8
#define ESC 27
#define ENTER 13
#define SPACEBAR 32


class Playername
{
private:

	sf::Text textbox;
	std::ostringstream text;
	bool isSelected = true;
	bool hasLimit = false;
	bool sel = false;
	int limit;
	fstream scoreboard;

	sf::RenderWindow* Regis;
	sf::Event p;
	void initPlayername();

	void inputLogic(int charTyped);

	void typeOn(sf::Event input);
	void deleteLastChar();
	
	void updateFile();

public:

	Playername();
	virtual ~Playername();

	

	void setLimit(bool ToF);


	void setLimit(bool ToF, int lim);
	

	void setSelected(bool sel);
	

	string getText();
	

	

	void type(sf::Event ev);


	void sfevent();
	void namerender();
	void PYopen();
	
	
};

