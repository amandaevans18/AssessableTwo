#pragma once
#include <iostream>
#include "raylib.h"
#include<vector>
#include"Bullet.h"

class Player 
{
public:
	int health;
	Texture2D sprite;
	Rectangle pos;
	float speed;
	int playerAttackDmg;
	int playerAttackSpeed;
	float bulletSpeed;
	float scale;
	float timer;

	Player();
	~Player();

	void playerDraw();
	void playerMovement(float deltaTime, float screenX, float screenY);
	void playerAttack(float deltaTime, std::vector<Bullet> bullets);
};