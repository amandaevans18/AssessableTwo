#pragma once
#include <iostream>
#include "raylib.h"

class HealthPickups
{
	Vector2 pos;
	bool enabled;
	Texture2D texture;
	int val;

	HealthPickups();
	HealthPickups();
	void draw();
	bool pickupCollected();
};