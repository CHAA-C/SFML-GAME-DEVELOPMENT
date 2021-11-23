#include "Game.h"
#include "MenuClass.h"
#include "Playername.h"
#include<time.h>
#include <stdlib.h>
#include<sstream>



using namespace sf;
const int W = 110; // Width
const int H = 50; // Hieght
int block = 17; // 1 Block
int gameArray[H][W] = { 0 }; // GameArray

// Player 1
int x = 89 * block, y = (H * block) / 2;
int dx = 0, dy = 0;
int py1counter = 0;
int player1score = 0;

// Player 2
int x2 = 20 * block, y2 = (H * block) / 2;
int dx2 = 0, dy2 = 0;
int py2counter = 0;
int player2score = 0;

int i1 = rand() % 110 * block, i2 = rand() % 50 * block;

int itemapp = 0;

float timer = 0;
float delay = 0.1;

float Itime = 0;
float Idelay = 10;


bool gameOn = true;
bool gameEnd = false;
bool gameEnd2 = false;
bool specialstat1 = false;
bool specialstat2 = false;
int itemon = 0;


int scourcount = 1;



void Game::initWindow()
{
	this->window = new sf::RenderWindow(VideoMode(W * block, H * block), "M.E.G.A.T.R.O.N");
}

Game::Game()
{
	this->initWindow();

}

Game::~Game()
{

}

// Function

void Game::updateTime()
{
	this->time = this->clock.getElapsedTime().asSeconds();
	clock.restart();
	timer += time;
	Itime += time;
}

void Game::updateSFMLev()
{


	while (this->window->pollEvent(this->c))
	{
		switch (this->c.type)
		{
		case Event::Closed:
			{
				this->window->close();
				py1counter = 0;
				py2counter = 0;
				player1score = 0;
				player2score = 0;
				Itime = 0;
				break;
			}

			break;

		case Event::KeyPressed:
			if (c.key.code == Keyboard::Escape)
			{
				this->window->close();
				py1counter = 0;
				py2counter = 0;
				player1score = 0;
				player2score = 0;
				Itime = 0;
				break;
			}
		}
	}
	// Move Player1 ลูกศร กลับทางเดิมไม่ได้

	if (Keyboard::isKeyPressed(Keyboard::Up) && dy != block) { dx = 0; dy = -block; }
	if (Keyboard::isKeyPressed(Keyboard::Left) && dx != block) { dx = -block; dy = 0; }
	if (Keyboard::isKeyPressed(Keyboard::Down) && dy != -block) { dx = 0; dy = block; }
	if (Keyboard::isKeyPressed(Keyboard::Right) && dx != -block) { dx = block; dy = 0; }

	// Move Player2 W A S D กลับทางเดิมไม่ได้

	if (Keyboard::isKeyPressed(Keyboard::W) && dy2 != block) { dx2 = 0; dy2 = -block; }
	if (Keyboard::isKeyPressed(Keyboard::A) && dx2 != block) { dx2 = -block; dy2 = 0; }
	if (Keyboard::isKeyPressed(Keyboard::S) && dy2 != -block) { dx2 = 0; dy2 = block; }
	if (Keyboard::isKeyPressed(Keyboard::D) && dx2 != -block) { dx2 = block; dy2 = 0; }

	if (gameOn == true)
	{
		

		if (timer > delay) // TIME DELAY ไม่งั้นแม่งไวสัสๆ
		{
			x += dx;
			y += dy;

			x2 += dx2;
			y2 += dy2;



			

			// โผล่ออกมาอีกฝั่งได้ P1

			if (x >= (W * block)) x = 0; if (x < 0) x = (W - 1) * block;
			if (y >= (H * block)) y = 0; if (y < 0) y = (H - 1) * block;


			// โผล่ออกมาอีกฝั่งได้ P2

			if (x2 >= (W * block)) x2 = 0; if (x2 < 0) x2 = (W - 1) * block;
			if (y2 >= (H * block)) y2 = 0; if (y2 < 0) y2 = (H - 1) * block;

			//ชนแล้วหยุด P1

			if (gameArray[y / block][x / block] == 1 && (dx + dy) != 0 ||
				gameArray[y / block][x / block] == 2) {
				py1counter++;
				if (py1counter > 0 && specialstat2 == false)
				{
					player2score++;
				}
				Itime = 0;
			}

			//ชนแล้วหยุด P2

			if (gameArray[y2 / block][x2 / block] == 2 && (dx2 + dy2) != 0 ||
				gameArray[y2 / block][x2 / block] == 1) {
				py2counter++;
				if (py2counter > 0 && specialstat1 == false)
				{
					player1score++;
				}
				Itime = 0;
			}


			if (x == i1 && y == i2 && itemon == 1)
			{
				
				py1counter = -1;
				

			}

			if (x2 == i1 && y2 == i2 && itemon == 1)
			{
	
				py2counter = -1;
				
			}

			if (x == i1 && y == i2 && itemon == 2)
			{
				player1score++;
				player2score--;
			}

			if (x2 == i1 && y2 == i2 && itemon == 2)
			{
				player2score++;
				player1score--;
			}



			if (x == i1 && y == i2 && itemon == 3)
			{
				specialstat1 = true;
			}

			if (x2 == i1 && y2 == i2 && itemon == 3)
			{
				specialstat2 = true;
			}

			if (specialstat1 == true)
			{
				if (py2counter > 0) 
				{
					player1score += 2;
					specialstat1 = false;
				}
				if (py1counter > 0)
				{
					player1score--;
					specialstat1 = false;
				}
				
			}

			if (specialstat2 == true)
			{
				if (py1counter > 0)
				{
	
					player2score += 2;
					specialstat2 = false;
				}
				if (py2counter > 0)
				{
					player2score--;
					specialstat2 = false;
				}
			}
			
			
			
			//-----------------------------------------Array ไว้วาดหางผู้เล่น--------------------------------------------//

			if (gameArray[y / block][x / block] == 0) gameArray[y / block][x / block] = 1; // Write P1 in Array

			if (gameArray[y2 / block][x2 / block] == 0) gameArray[y2 / block][x2 / block] = 2; // Write P2 in Array

			//-----------------------------------------------------------------------------------------------------//

			timer = 0;


		}
	}

	if (gameEnd == true)
	{
		updateFile();

		x2 = 20 * block, y2 = (H * block) / 2;
		x2 = 20 * block, y2 = (H * block) / 2;
		py1counter = 0;
		py2counter = 0;
		player1score = 0;
		player2score = 0;
		Itime = 0;
		sf::sleep(sf::milliseconds(5000));
		this->window->close();
		gameEnd = false;
		gameOn = true;

		Playername playername;
		playername.PYopen();

		
		
	}

	if (gameEnd2 == true)
	{
		

		x2 = 20 * block, y2 = (H * block) / 2;
		x2 = 20 * block, y2 = (H * block) / 2;
		py1counter = 0;
		py2counter = 0;
		player1score = 0;
		player2score = 0;
		Itime = 0;
		sf::sleep(sf::milliseconds(5000));
		this->window->close();
		gameEnd2 = false;
		gameOn = true;

		



	}


	if (py1counter > 0 || py2counter > 0)
	{
		sf::sleep(sf::milliseconds(1000));

		
		x = rand() % 110 * 17, y = rand() % 50 * 17 ;
		x2 = rand() % 110 * 17, y2 = rand() % 50 * 17;
		i1 = rand() % 110 * 17, i2 = rand() % 50 * 17;
		
		
		dx = 0, dy = 0;
		dx2 = 0, dy2 = 0;
		py1counter = 0; py2counter = 0;

		//---------------- SET ทุกอย่างใหม่ ----------------//

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				gameArray[i][j] = 0;
			}
		}
		//---------------- SET ทุกอย่างใหม่ ----------------//
	}


	
}

void Game::updateFile()
{
	this->scoreboard.open("score/scoreboard.txt", ios_base::out | ios_base::app);

	if (player1score > player2score)
	{
		
		this->scoreboard << player1score << " ";
		this->scoreboard.close();
	}
	else if (player2score > player1score)
	{
		this->scoreboard << player2score << " ";
		this->scoreboard.close();
	}
	
}


void Game::update()
{
	this->updateSFMLev();
}

void Game::render()
{
	this->window->clear();




	// Render

	Texture t1, t2, t3, i4 ,i5,i6;
	t1.loadFromFile("IMG/BG.png");
	t2.loadFromFile("IMG/PY-1.png");
	t3.loadFromFile("IMG/PY-2.png");
	i4.loadFromFile("IMG/IT-1.png");
	i5.loadFromFile("IMG/IT-2.png");
	i6.loadFromFile("IMG/IT-3.png");

	Sprite Background(t1), Player1(t2), Player2(t3), Item1(i4), Item2(i5), Item3(i6);



	Font font;
	font.loadFromFile("font/tahomabd.ttf");

	Text red, blue, red2, blue2,tie;

	red.setFont(font);
	red.setCharacterSize(30);
	red.setFillColor(Color::Red);
	red.setString("RED : ");
	red.setPosition(1740, 0);

	red2.setFont(font);
	red2.setCharacterSize(150);
	red2.setFillColor(Color::Red);
	red2.setString("RED WIN");
	red2.setPosition(600, 300);

	blue.setFont(font);
	blue.setCharacterSize(30);
	blue.setFillColor(Color::Blue);
	blue.setString("BLUE : ");
	blue.setPosition(0, 0);

	blue2.setFont(font);
	blue2.setCharacterSize(150);
	blue2.setFillColor(Color::Blue);
	blue2.setString("BLUE WIN");
	blue2.setPosition(550, 300);

	tie.setFont(font);
	tie.setCharacterSize(150);
	tie.setFillColor(Color::White);
	tie.setString("TIE");
	tie.setPosition(800, 300);

		

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (gameArray[i][j] == 0)
			{

				// Background Draw //

				Background.setPosition(j * block, i * block);
				this->window->draw(Background);


			}
			//--------P1 Tails--------//

			else if (gameArray[i][j] == 1)
			{
				Player1.setPosition(j * block, i * block);
				this->window->draw(Player1);
			}
			//--------P2 Tails--------//

			else if (gameArray[i][j] == 2)
			{
				Player2.setPosition(j * block, i * block);
				this->window->draw(Player2);
			}
		}

		
	}







	// Player Head Draw

	Player1.setPosition(x, y);
	this->window->draw(Player1);
	Player2.setPosition(x2, y2);
	this->window->draw(Player2);



	if (Itime >= Idelay)
	{
		if (itemapp == 0 || itemapp == 1 || itemapp == 2 || itemapp == 4 || itemapp == 5)
		{
			Item1.setPosition(i1, i2);
			this->window->draw(Item1);
			itemon = 1;

			if (itemon == 1)
			{
				Item1.setPosition(i1, i2);
				this->window->draw(Item1);
			}
		}

		if (itemapp == 3)
		{
			Item3.setPosition(i1, i2);
			this->window->draw(Item3);
			itemon = 3;

			if (itemon == 3)
			{
				Item3.setPosition(i1, i2);
				this->window->draw(Item3);
			}
		}
			
		
		if (itemapp == 6)
		{

			Item2.setPosition(i1, i2);
			this->window->draw(Item2);
			itemon = 2;

			if (itemon == 2)
			{
				Item2.setPosition(i1, i2);
				this->window->draw(Item2);
			}
		}
	}
	
	


	// Player Red score Type
	std::stringstream ss;
	ss << (player1score);
	std::string si;
	ss >> si;
	red.setString("RED : " + si);



	// Player Blue score Type
	std::stringstream ss2;
	ss2 << (player2score);
	std::string si2;
	ss2 >> si2;
	blue.setString("BLUE : " + si2);

	// Player Score Draw

	this->window->draw(red);
	this->window->draw(blue);


	if (x == i1 && y == i2)
	{
	
		itemon = 0;
		Player1.setPosition(i1, i2);
		this->window->draw(Player1);

		
		i1 = rand() % 110 * block, i2 = rand() % 50 * block;
		itemapp++;

		Itime = 0;
	
	}
	else if (x2 == i1 && y2 == i2)
	{
		itemon = 0;
		Player2.setPosition(i1, i2);
		this->window->draw(Player2);

		
		i1 = rand() % 110 * block, i2 = rand() % 50 * block;
		itemapp++;



		Itime = 0;
	
	}

	if (player1score + player2score >= 10 && player1score > player2score)
	{
		gameOn = false;

		
		
		this->window->clear();
		this->window->draw(red2);

		
		gameEnd = true;
		
	}

	if (player2score + player1score >= 10 && player2score > player1score)
	{
		gameOn = false;

		

		

		this->window->clear();
		this->window->draw(blue2);
		
		gameEnd = true;

	}

	if (player2score + player1score >= 10 && player2score == player1score)
	{
		gameOn = false;
		this->window->clear();
		this->window->draw(tie);

		gameEnd2 = true;

	}

	if (itemapp > 6)
	{
		itemapp = 0;
	}


	this->window->display(); 
}

void Game::run()
{
	
	while (this->window->isOpen())
	{
		this->updateTime();
		this->update();
		this->render();
	}
}

