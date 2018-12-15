#pragma once
#include <iostream>
#include "raylib.h"
#include<cstring>
#include"Bullet.h"
#include<vector>
#include"Player.h"

class Enemy
{
public:
	float timer;
	int health;
	Texture2D texture;
	Rectangle pos;
	int enemyAttackDmg;
	// how much time between bullets
	int attackSpeed;
	// how fast bullets move
	float speed;

	bool enabled;
	//big bois
	float scale;
	//bullet pattern management
	int pattern;
	int step;
	


	Enemy();
	Enemy(int _health, Rectangle _pos, int _attack, int _attackSpeed, int _speed , int _pattern);
	~Enemy();

	void enemyDraw();
	void enemyAttack(float deltaTime, std::vector<Bullet>& bullets, Player player);
};