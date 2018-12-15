#pragma once
#include <iostream>
#include "raylib.h"
#include"Enemy.h"
#include<vector>

class Player 
{
public:
	int health;
	Texture2D sprite;
	Rectangle pos;
	int speed;
	int playerAttack;
	int playerAttackSpeed;
	int bulletSpeed;
	float scale;
	float timer;

	Player();
	~Player();

	void draw();
	void movement(float deltaTime, float screenX, float screenY);
	void attack(float deltaTime, std::vector<Bullet> bullets);
};