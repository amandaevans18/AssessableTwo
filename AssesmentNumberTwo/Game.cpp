#include "Game.h"

gameState GameState = MAIN_MENU;

void Game::go()
{

	switch (GameState)
	{
	case MAIN_MENU:
		mainMenu();
		break;
	case LVLONE:
		lvlOne();
		break;
	case LVLTWO:
		lvlTwo();
		break;
	case INTROSCREEN:
		introScreen();
		break;
	case WINSCREEN:
		winScreen();
		break;
	case LOSESCREEN:
		loseScreen();
		break;
	default:
		break;
	}

}


void Game::update()
{
	//deals with movement of player and enemy and attacks
	player.playerAttack(GetFrameTime(),bullets);
	player.playerMovement(GetFrameTime(), screenWidth, screenHeight);

	for (int e = 0; e < 10; e++)
	{
		enemy[e].enemyAttack(GetFrameTime(), bullets, player);
		for (int b = 0; b < bullets.size(); b++) 
		{
			bullets[b].movement(GetFrameTime());
			if (CheckCollisionRecs(bullets[b].pos, player.pos) && bullets[b].tag == ENEMY)
			{
				player.health -= bullets[b].attack;
				bullets[b].enabled = false;
			}
			if (CheckCollisionRecs(bullets[b].pos, enemy[e].pos) && bullets[b].tag == PLAYER)
			{
				enemy[e].health -= bullets[b].attack;
				bullets[b].enabled = false;
			}
		}
	}
}


void Game::draw()
{
	player.playerDraw();
	for (int e = 0; e < 10; e++) 
	{
		enemy[e].enemyDraw();
	}
	for (int b = 0; b < bullets.size(); b++) 
	{
		bullets[b].draw();
	}
}



void Game::mainMenu()
{
	ClearBackground(BLACK);
	DrawText("PRESS SPACE TO START", 350,250, 35,RED);
	if (IsKeyReleased(KEY_SPACE))
	{
		GameState = INTROSCREEN;
		return;
	}
}

void Game::lvlOne()
{
	enemysAlive = false;
	ClearBackground(WHITE);

	draw();
	update();
	if (player.health <= 0) 
	{
		GameState = LOSESCREEN;
		return;
	}
	for (int i = 0; i < 5; i++)
	{
		if (enemy[i].enabled == false) 
		{
			enemysAlive = true;
		}
	}
	if (enemysAlive == false) 
	{
		enemy[5] = Enemy(1, { 20,20,5,5 }, 1, 2, 1, 0);
		enemy[6] = Enemy(2, { 200,200,10,10 }, 1, 1, 1, 0);
		enemy[7] = Enemy(1, { 150,150,10,10 }, 1, 1, 1, 1);
		enemy[8] = Enemy(3, { 50,50,10,10 }, 1, 1, 1, 2);
		enemy[9] = Enemy(2, { 350,15,10,10 }, 1, 1, 1, 0);
		GameState = LVLTWO;
		return;
	}
}

void Game::lvlTwo() 
{
	enemysAlive = false;
	ClearBackground(WHITE);
	draw();
	update();
	if (player.health <= 0)
	{
		GameState = LOSESCREEN;
		return;
	}
	for (int i = 0; i < 5; i++)
	{
		if (enemy[i].enabled == true)
		{
			enemysAlive = true;
			break;
		}
	}
	/*if (enemysAlive == true)
	{
		GameState = WINSCREEN;
		return;
	}*/
}

void Game::introScreen() 
{
	ClearBackground(BLACK);
	DrawText("WASD to move and arrow keys to shoot!", 50, 250, 35, RED);
	DrawText("Press SPACE to begin!", 200, 300, 20, RED);

	if (IsKeyReleased(KEY_SPACE)) 
	{
		enemy[0] = Enemy(1, { 20,20,5,5 }, 1, 2, 1, 0);
		enemy[1] = Enemy(2, { 200,200,10,10 }, 1, 1, 1, 0);
		enemy[2] = Enemy(1, { 150,150,10,10 }, 1, 1, 1, 1);
		enemy[3] = Enemy(3, { 50,50,10,10 }, 1, 1, 1, 2);
		enemy[4] = Enemy(2, { 350,15,10,10 }, 1, 1, 1, 0);
		GameState = LVLONE;
		return;
	}
}

void Game::winScreen() 
{
	ClearBackground(BLACK);
	DrawText("You WON!", 50, 250, 35, GREEN);
	DrawText("Press SPACE to continue...", 200, 300, 20, RED);
	if (IsKeyReleased(KEY_SPACE))
	{
		GameState = MAIN_MENU;
		return;
	}
}

void Game::loseScreen()
{
	ClearBackground(BLACK);
	DrawText("You LOST!", 50, 250, 35, RED);
	DrawText("Press SPACE to continue...", 200, 300, 20, RED);
	if (IsKeyReleased(KEY_SPACE))
	{
		GameState = MAIN_MENU;
		return;
	}
}

