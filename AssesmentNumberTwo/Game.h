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
	//draws main menu when button pressed update game state and clear screen
	void mainMenu();
	//first lvl of the dungeon
	void lvlOne();
	//second lvl of the dungien
	void lvlTwo();
	//third lvl of the dungien
	void lvlThree();
	//the text before game starts when certain button pressed change game state to lvl one
	void introScreen();
	//YOOU WIN only in lvl one 
	void winScreen();
	//die if health is 0
	void loseScreen();
	//calling all of the functions above and calling their logic  
	void go();


};