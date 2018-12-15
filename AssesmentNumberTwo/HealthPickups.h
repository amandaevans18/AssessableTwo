#pragma once
#include <iostream>
#include "raylib.h"
#include"Player.h"

class HealthPickups
{
	Rectangle pos;
	bool enabled;
	int val;
	Color color;

	HealthPickups();
	HealthPickups(Rectangle _pos, Color _color,int _val);

	void draw();
	bool pickupCollected(Player player);
};