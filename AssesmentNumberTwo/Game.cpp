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

	for (int e = 0; e < 5; e++)
	{
		if (enemy[e].enabled)
		{
			enemy[e].enemyAttack(GetFrameTime(), bullets, player);
		}
		for (int b = 0; b < bullets.size(); b++) 
		{
			bullets[b].movement(GetFrameTime());
			if (CheckCollisionRecs(bullets[b].pos, player.pos) && bullets[b].tag == ENEMY && bullets[b].enabled)
			{
				player.health -= bullets[b].attack;
				bullets[b].enabled = false;
			}
			if (CheckCollisionRecs(bullets[b].pos, enemy[e].pos) && bullets[b].tag == PLAYER && bullets[b].enabled && enemy[e].enabled)
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
	for (int e = 0; e < 5; e++) 
	{
		enemy[e].enemyDraw();
	}
	for (int b = 0; b < bullets.size(); b++) 
	{
		bullets[b].draw();
	}
	DrawText(healthShown.c_str(), 20, 20, 20, RED);
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
 	healthShown = "Health: " + std::to_string(player.health);
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
		}
	}
	if (enemysAlive == false) 
	{
		enemy[0] = Enemy(1, { 100,20,64,64 }, 1, 1, 200, 0);
		enemy[1] = Enemy(2, { 200,200,64,64 }, 1, 1, 100, 0);
		enemy[2] = Enemy(1, { 150,150,64,64 }, 1, 1, 250, 1);
		enemy[3] = Enemy(3, { 50,50,64,64 }, 1, 2, 300, 2);
		enemy[4] = Enemy(2, { 350,15,64,64 }, 1, 3, 200, 0);
		GameState = LVLTWO;
		return;
	}
}

void Game::lvlTwo() 
{
	healthShown = "Health: " + std::to_string(player.health);
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
	if (enemysAlive == false)
	{
		GameState = WINSCREEN;
		return;
	}
}

void Game::introScreen() 
{
	ClearBackground(BLACK);
	DrawText("WASD to move and arrow keys to shoot!", 50, 250, 35, RED);
	DrawText("Press SPACE to begin!", 200, 300, 20, RED);

	if (IsKeyReleased(KEY_SPACE)) 
	{
		enemy[0] = Enemy(1, { 100,20,64,64 }, 1, 1, 200, 0);
		enemy[1] = Enemy(2, { 200,200,64,64 }, 1, 1, 300, 0);
		enemy[2] = Enemy(1, { 150,150,64,64 }, 1, 2, 250, 1);
		enemy[3] = Enemy(3, { 50,50,64,64 }, 1, 3, 100, 2);
		enemy[4] = Enemy(2, { 350,15,64,64 }, 1, 2, 150, 0);
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
		player.health = 5;
		return;
	}
}

