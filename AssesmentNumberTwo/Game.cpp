#include "Game.h"

void Game::go()
{
	//most basic game logic, if we kill all enemys next lvl etc

	mainMenu();
	while (!gameUnBeat && startGame)
	{
		if (!playerDead)
		{
			if (IsKeyReleased(KEY_SPACE) && introPlayed == false)
			{
				introScreen();
				introPlayed = true;
			}
			if (IsKeyReleased(KEY_SPACE) && introPlayed == true)
			{

			}
			if ((lvlOneBeat == true || lvlTwoBeat == true || lvlThreeBeat == true) && tranistion == false)
			{
				transitionScreen();
				tranistion = true;
			}
			if (lvlOneBeat == false && tranistion == true)
			{
				tranistion = false;
				lvlOne();
			}
			if (lvlTwoBeat == false && tranistion == true)
			{
				tranistion = false;
				lvlTwo();
			}
			if (lvlThreeBeat == false && tranistion == true)
			{
				tranistion = false;
				lvlThree();
			}
		}
		else
		{
			break;
		}
	}
}


void Game::update()
{
	//deals with movement of player and enemy 
}

void Game::collision()
{
	//checks for collision
}

void Game::draw()
{
	//draws all of the sprites 
}



void Game::mainMenu()
{

}

void Game::lvlOne()
{
}

void Game::lvlTwo() 
{
}

void Game::lvlThree()
{
}

void Game::introScreen() 
{

}

void Game::winScreen() 
{
}

void Game::loseScreen()
{
}

void Game::transitionScreen()
{
}
