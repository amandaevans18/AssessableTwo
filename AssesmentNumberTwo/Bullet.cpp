#include "Bullet.h"

Bullet::Bullet()
{
	enabled = false;
}

Bullet::Bullet(Vector2 _pos, Color _color, int _attack, Vector2 _speed , WhomFired _tag)
{
	pos.x = _pos.x;
	pos.y = _pos.y;
	color = _color;
	attack = _attack;
	speed = _speed;
	tag = _tag;
	// hardcoded
	pos.width = 1;
	pos.height = 2;
	enabled = true;
}

Bullet::~Bullet()
{
}

void Bullet::draw()
{
	if (enabled)
	{
		DrawRectangleRec(pos, color);
	}
}

void Bullet::movement(float deltaTime)
{
	if (enabled) 
	{
		pos.x += (speed.x * deltaTime);
		pos.y += (speed.y * deltaTime);

	}
}

void Bullet::collisionUpdate(Player player, Enemy enemy)
{
	if (enabled)
	{
		if (CheckCollisionRecs(pos, player.pos) && tag == ENEMY)
		{
			player.health -= attack;
			enabled = false;
		}
		if (CheckCollisionRecs(pos, enemy.pos) && tag == PLAYER)
		{
			enemy.health -= attack;
			enabled = false;
		}
	}
}

