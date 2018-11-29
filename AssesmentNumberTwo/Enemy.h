#pragma once
#include <iostream>
#include "raylib.h"

class Player
{
	int health;
	Texture2D texture;
	Vector2 pos;
	int attack;
	int speed;
	float height;
	float width;

	void draw();
	void movement(float deltaTime, float screenX, float screenY);
};