#pragma once
#include "raylib.h"
#include<string>
#include<iostream>
#include"Player.h"
#include"HealthPickups.h"
#include"Enemy.h"

enum gameState 
{
MAIN_MENU, LVLONE, LVLTWO,INTROSCREEN, WINSCREEN,LOSESCREEN
};
class Game
{
	//screen width
	int screenWidth = 800;
	// screen height
	int screenHeight = 450;
	//timer??
	float timer = 0.0f;
	

public:

	Player player;
	Enemy enemy[10];
	std::vector<Bullet> bullets;
	bool enemysAlive;

	void update();
	void draw();

	//has all game logic for individual screen / art for them
	//draws main menu when button pressed update game state and clear screen
	void mainMenu();
	//first lvl of the dungeon
	void lvlOne();
	//second lvl of the dungien
	void lvlTwo();
	//the text before game starts when certain button pressed change game state to lvl one
	void introScreen();
	//YOOU WIN only in lvl one 
	void winScreen();
	//die if health is 0
	void loseScreen();
	//calling all of the functions above and calling their logic  
	void go();


};