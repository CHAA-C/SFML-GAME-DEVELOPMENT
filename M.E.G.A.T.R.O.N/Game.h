#ifndef GAME_H
#define GAME_H


#include<SFML/Graphics.hpp>
#include<time.h>
#include<sstream>
#include<fstream>
#include<iostream>

using namespace std;

class Game
{
private:

	sf::RenderWindow *window;
	sf::Event c;
	sf::Clock clock;
	fstream scoreboard;



	float time;

	void initWindow();

public:
	Game();
	virtual ~Game();

	//function
	void updateTime();
	void updateSFMLev();
	void update();
	void render();
	void run();
	

	void updateFile();
	

};
#endif
