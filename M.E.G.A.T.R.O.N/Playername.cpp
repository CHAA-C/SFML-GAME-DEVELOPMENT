#include "Playername.h"
#include<iostream>
#include<SFML/Graphics.hpp>

const int W = 110; // Width
const int H = 50; // Hieght

void Playername::initPlayername()
{
	this->Regis = new sf::RenderWindow(sf::VideoMode(W * 17, H * 17), "M.E.G.A.T.R.O.N");

}



Playername::Playername()
{
	this->initPlayername();
}


Playername::~Playername()
{

}


void Playername::namerender()
{
	this->Regis->clear();


	sf::Font font;
	font.loadFromFile("font/tahomabd.ttf");


	sf::Text head,bottom;

	head.setFont(font);
	head.setCharacterSize(80);
	head.setFillColor(sf::Color::Red);
	head.setString("TYPE WINNER NAME PLEASE");
	head.setPosition(325, 200);

	
	textbox.setCharacterSize(40);
	textbox.setFillColor(sf::Color::White);
	textbox.setPosition(850, 400);
	textbox.setFont(font);
	isSelected = true;

	bottom.setFont(font);
	bottom.setCharacterSize(40);
	bottom.setFillColor(sf::Color::Green);
	bottom.setString("PRESS \"ESC\" TO CONFIRM");
	bottom.setPosition(660, 600);


	this->Regis->draw(head); 
	this->Regis->draw(textbox);
	this->Regis->draw(bottom);

	this->Regis->display();
}

void Playername::inputLogic(int charTyped)
{
	if (charTyped != BACKSPACE && charTyped != SPACEBAR && charTyped != ESC)
	{
		text << static_cast<char>(charTyped);
	}
	else if (charTyped == BACKSPACE)
	{
		if (text.str().length() > 0)
		{
			deleteLastChar();
		}
	}
	textbox.setString(text.str());
}

void Playername::deleteLastChar()
{
	std::string t = text.str();
	std::string newT = "";
	for (int i = 0; i < t.length() - 1; i++)
	{
		newT += t[i];
	}
	text.str("");
	text << newT;

	textbox.setString(text.str());
}


void Playername::typeOn(sf::Event ev)
{
	if (isSelected)
	{
		int charTyped = ev.text.unicode;
		if (charTyped < 128)
		{
			if (hasLimit)
			{
				if (text.str().length() <= limit)
				{
					inputLogic(charTyped);
				}
				else if (text.str().length() > limit && charTyped == BACKSPACE)
				{
					deleteLastChar();
				}
			}
			else
			{
				inputLogic(charTyped);
			}
		}
	}
}


void Playername::updateFile()
{
	this->scoreboard.open("score/scoreboard.txt", ios_base::out | ios_base::app);
	this->scoreboard << this->text.str()<< endl;
	this->scoreboard.close();
}

void Playername::sfevent()
{
	while (this->Regis->pollEvent(this->p))
	{
		switch (this->p.type)
		{
		case sf::Event::Closed:
		{
			this->Regis->close();
			break;
		}
		case sf::Event::KeyPressed:
			if (p.key.code == sf::Keyboard::Escape)
			{
				this->updateFile();
				this->Regis->close();

			}
			break;

		case sf::Event::TextEntered:
			typeOn(p);
			break;         // กุมีปัญหาตรงนี้ มันบอก class sf::Text แม่งมีมีตัว type ที่กุเรียกใช้
		}
	}
}


void Playername::setLimit(bool ToF)
{
	hasLimit = ToF;
}

void Playername::setLimit(bool ToF, int lim)
{
	hasLimit = ToF;
	limit = lim;
}

void Playername::setSelected(bool sel)
{
	isSelected = sel;
	if (!sel)
	{
		string t = text.str();
		string newT = "";
		for (int i = 0; i < t.length() - 1; i++)
		{
			newT += t[i];
		}
		textbox.setString(newT);
	}
}


string Playername::getText()
{
	return text.str();
}

void Playername::PYopen()
{
	while (this->Regis->isOpen())
	{
		this->sfevent();
		this->namerender();
	}
}