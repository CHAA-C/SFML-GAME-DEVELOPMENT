#pragma once
#include<SFML/Graphics.hpp>
#include<fstream>
#include<iostream>
#include<string>

using namespace std;

class Scoreboard
{
private:
	vector <pair<string, int>> score;
	sf::RenderWindow *board;
	sf::Event e;
	void initScoreboard();
	fstream fp;
	
	
public:

	Scoreboard();
	virtual ~Scoreboard();
	
	void sfevent();
	void scorerender();
	void open();
	void fileread();
	int get_rank(string input);




};

