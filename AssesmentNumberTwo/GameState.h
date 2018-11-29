
//GameState.h with Enum
#pragma once
#include "raylib.h"
#include"Game.h"
#include<string>
#include<iostream>

enum GStates
{
	MainMenu = 0,
	IntroText,
	InGame,
	WinScreen,
	LoseScreen
};

class GameState
{
private:
	GStates cState = MainMenu;
	GameState() {};
	GameState(GameState const&) {};  // prevents external use
	void operator=(GameState const&) {}; // prevents external use

										 // note that the getState and setState function have changed to return and
										 // accept enum values instead of integers
public:
	GStates getState();
	void setState(GStates newState);
	static GameState& GetInstance();
	~GameState();
};