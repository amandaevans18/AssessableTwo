#pragma once
#include <iostream>
#include "raylib.h"

class Items
{
	Vector2 pos;
	bool enabled;
	Texture2D texture;

	Items();
	~Items();
	void draw();
};