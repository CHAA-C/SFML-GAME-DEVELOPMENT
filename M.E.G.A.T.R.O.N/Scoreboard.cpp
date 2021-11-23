#define _CRT_SECURE_NO_WARNINGS
#include<SFML/Graphics.hpp>
#include "Scoreboard.h"
#include<stdio.h>
#include<utility>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<sstream>
#include "Playername.h"


using namespace std;

char temp[255];





const int W = 110; // Width
const int H = 50; // Hieght




void Scoreboard::initScoreboard()
{
	this->board = new sf::RenderWindow(sf::VideoMode(W * 17, H * 17), "M.E.G.A.T.R.O.N");
	
}


Scoreboard::Scoreboard()
{
	this->initScoreboard();
}


Scoreboard::~Scoreboard()
{

}

void Scoreboard::fileread()
{
	fp.open("score/scoreboard.txt",ios_base::in);
	vector<string> v;
	
	string line;
	for (; getline(fp, line); )
		v.push_back(line);
	sort(v.begin(), v.end(), [&](string s1, string s2) -> bool { return this->get_rank(s1) > this->get_rank(s2); });

	for (auto i = v.begin(); i != v.end(); i++)
	{
		string name, scores;
		name = *i;

		string::size_type pos = name.find(' ');

		if (name.npos != pos)
		{
			scores = name.substr(0, pos);
			name = name.substr(pos + 1);
		}

		score.push_back(make_pair(name, stoi(scores)));

		if (score.size() >= 5)
			break;
	}
	fp.close();
	
}



void Scoreboard::scorerender()
{
	

	this->board->clear();

	sf::Font font;
	font.loadFromFile("font/tahomabd.ttf");

	sf::Text text,close,name1,score1,name2, score2,name3,score3,name4,score4,name5,score5;
	text.setFont(font);
	text.setCharacterSize(80);
	text.setFillColor(sf::Color::Red);
	text.setString("HIGHSCORE LEADER");
	text.setPosition(500, 30);

	close.setFont(font);
	close.setCharacterSize(25);
	close.setFillColor(sf::Color::Green);
	close.setString("PRESS \"ESC\" TO CLOSE");
	close.setPosition(785, 750);

	name1.setFont(font);
	name1.setCharacterSize(30);
	name1.setFillColor(sf::Color::White);
	name1.setString(score[0].first);
	name1.setPosition(500, 200);

	name2.setFont(font);
	name2.setCharacterSize(30);
	name2.setFillColor(sf::Color::White);
	name2.setString(score[1].first);
	name2.setPosition(500, 300);

	name3.setFont(font);
	name3.setCharacterSize(30);
	name3.setFillColor(sf::Color::White);
	name3.setString(score[2].first);
	name3.setPosition(500, 400);

	name4.setFont(font);
	name4.setCharacterSize(30);
	name4.setFillColor(sf::Color::White);
	name4.setString(score[3].first);
	name4.setPosition(500, 500);

	name5.setFont(font);
	name5.setCharacterSize(30);
	name5.setFillColor(sf::Color::White);
	name5.setString(score[4].first);
	name5.setPosition(500, 600);

	
	score1.setFont(font);
	score1.setCharacterSize(30);
	score1.setFillColor(sf::Color::White);
	score1.setString(to_string(score[0].second));
	score1.setPosition(1300, 200);

	score2.setFont(font);
	score2.setCharacterSize(30);
	score2.setFillColor(sf::Color::White);
	score2.setString(to_string(score[1].second));
	score2.setPosition(1300, 300);

	score3.setFont(font);
	score3.setCharacterSize(30);
	score3.setFillColor(sf::Color::White);
	score3.setString(to_string(score[2].second));
	score3.setPosition(1300, 400);

	score4.setFont(font);
	score4.setCharacterSize(30);
	score4.setFillColor(sf::Color::White);
	score4.setString(to_string(score[3].second));
	score4.setPosition(1300, 500);

	score5.setFont(font);
	score5.setCharacterSize(30);
	score5.setFillColor(sf::Color::White);
	score5.setString(to_string(score[4].second));
	score5.setPosition(1300, 600);


	

	


	this->board->draw(text);
	this->board->draw(name1);
	this->board->draw(name2);
	this->board->draw(name3);
	this->board->draw(name4);
	this->board->draw(name5);
	this->board->draw(score1);
	this->board->draw(score2);
	this->board->draw(score3);
	this->board->draw(score4);
	this->board->draw(score5);
	this->board->draw(close);

	this->board->display();
}

void Scoreboard::sfevent()
{
	while (this->board->pollEvent(this->e))
	{
		switch (this->e.type)
		{
		case sf::Event::Closed:
		{
			this->board->close();
			break;
		}
		break;

		case sf::Event::KeyPressed:
			if (e.key.code == sf::Keyboard::Escape)
			{
				this->board->close();
				break;
			}
		}
	}
}

int Scoreboard::get_rank(string input)
{
	stringstream ss(input);
	string s;
	// keep extracting strings, last one would be your 'int' rank
	ss >> s;
	return atoi(s.c_str());
}


void Scoreboard::open()
{
	while (this->board->isOpen())
	{
		this->fileread();
		this->sfevent();
		this->scorerender();

	}
}

