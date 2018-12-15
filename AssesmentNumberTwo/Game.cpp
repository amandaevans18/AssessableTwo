#include "Game.h"

void Game::go()
{
	//most basic game logic, if we kill all enemys next lvl etc

	mainMenu();
	while (!gameWon && startGame)
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
				lvlOne();
			}
			if ((lvlOneBeat == false || gameWon == false) && tranistion == false)
			{
				transitionScreen();
				tranistion = true;
			}
			if ( gameWon == false && tranistion == true)
			{
				lvlTwo();
			}
		}
		else
		{
			loseScreen();
			if (IsKeyReleased(KEY_SPACE))
			{
				break;
			}
		}
	}
	winScreen();

}

void Game::resetVaribles()
{
	//screen width
	 screenWidth = 800;
	// screen height
	 screenHeight = 450;
	//timer??
	 timer = 0.0f;
	//if the intro has been played
	 introPlayed = false;
	//if all lvl1 enemys are dead
	 lvlOneBeat = false;
	//if all lvl2 enemys are dead(game is won)
	 gameWon = false;
	//if player is dead!
	 playerDead = false;
	//keep track of tranistion screen
	 tranistion = false;
	//menu button is pressed
	 startGame = false;
}


void Game::update()
{
	//deals with movement of player and enemy and attacks
	player.attack(GetFrameTime(),bullets);
	player.movement(GetFrameTime(), screenWidth, screenHeight);

	for (int e = 0; e < 10; e++)
	{
		enemy[e].attack(GetFrameTime(), bullets, player);
		for (int b = 0; b < bullets.size(); b++) 
		{
			bullets[b].movement(GetFrameTime());
			bullets[b].collisionUpdate(player,enemy[e]);
		}
	}
}


void Game::draw()
{
	player.draw();
	for (int e = 0; e < 10; e++) 
	{
		enemy[e].draw();
	}
	for (int b = 0; b < bullets.size(); b++) 
	{
		bullets[b].draw();
	}
}



void Game::mainMenu()
{
	startGame = true;
}

void Game::lvlOne()
{
}

void Game::lvlTwo() 
{
}

void Game::introScreen() 
{

}

void Game::winScreen() 
{
	resetVaribles();
}

void Game::loseScreen()
{

	resetVaribles();
}

void Game::transitionScreen()
{
}
