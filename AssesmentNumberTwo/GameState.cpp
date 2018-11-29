#include "GameState.h"

GStates GameState::getState()
{
	return cState;
}

void GameState::setState(GStates newState)
{
	cState = newState;
}

GameState & GameState::GetInstance()
{
	static GameState instance;
	return instance;
}

GameState::~GameState() {}