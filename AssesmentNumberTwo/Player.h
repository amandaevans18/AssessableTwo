#pragma once
#include <iostream>
#include "raylib.h"

class Player 
{
	int health;
	Texture2D sprite;
	std::string spriteName;
	Vector2 pos;
	int speed;
	int attack;
	float height;
	float width;

	void draw();
	void movement(float deltaTime, float screenX, float screenY);
};