#pragma once
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
	//if the intro has been played
	bool introPlayed = false;
	//if the game is not beat
	bool gameUnBeat = false;
	//if all lvl1 enemys are dead
	bool lvlOneBeat = false;
	//if all lvl2 enemys are dead
	bool lvlTwoBeat = false;
	//if all lvl3 enemys are dead (game won)
	bool lvlThreeBeat = false;
	//if player is dead!
	bool playerDead = false;
	//keep track of tranistion screen
	bool tranistion = false;
	//menu button is pressed
	bool startGame = false;
	

	void update();
	void collision();
	void draw();

	//has all game logic for individual screen / art for them
	//draws main menu when button pressed update game state and clear screen
	void mainMenu();
	//first lvl of the dungeon
	void lvlOne();
	//second lvl of the dungien
	void lvlTwo();
	//third lvl of the dungein
	void lvlThree();
	//the text before game starts when certain button pressed change game state to lvl one
	void introScreen();
	//YOOU WIN only in lvl one 
	void winScreen();
	//die if health is 0
	void loseScreen();
	//a transition screen
	void transitionScreen();
	//calling all of the functions above and calling their logic  
	void go();


};