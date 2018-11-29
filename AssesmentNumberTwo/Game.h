#pragma once
#include"GameState.h"
#include "raylib.h"
#include<string>
#include<iostream>
#include"Player.h"
#include"HealthPickups.h"
#include"Enemy.h"
#include"Items.h"
class Game
{
public:
	//screen width
	int screenWidth = 800;
	// screen height
	int screenHeight = 450;
	//timer??
	float timer = 0.0f;



	void update();
	void collision();
	void draw();

	//has all game logic for individual screen
	void mainMenu();
	void inGame();
	void introScreen();
	void winScreen();
	void loseScreen();
	void go();


};