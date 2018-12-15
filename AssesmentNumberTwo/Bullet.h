#pragma once
#include"raylib.h"


enum WhomFired 
{PLAYER, ENEMY};
class Bullet
{

public:
	Rectangle pos;
	Color color;
	int attack;
	Vector2 speed;
	bool enabled;
	WhomFired tag;

	Bullet();
	Bullet(Vector2 _pos, Color _color, int _attack, Vector2 _speed, WhomFired _tag);
	~Bullet();

	void draw();
	void movement(float deltaTime);
};
