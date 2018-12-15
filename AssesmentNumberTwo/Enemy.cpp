#include "Enemy.h"

Enemy::Enemy() 
{
	enabled = false;
	texture = LoadTexture("sloth.png");
	pos = { 0, 0, 10, 10 };
	scale = 1;
	timer = 0.0f;
	step = 0;
}

Enemy::Enemy(int _health, Rectangle _pos, int _attack, int _attackSpeed, int _speed , int _pattern)
{
	health = _health;
	texture = LoadTexture("sloth.png");
	pos = _pos;
	attack = _attack;
	attackSpeed = _attackSpeed;
	speed = _speed;
	enabled = false;
	scale = 1;
	pattern = _pattern;
	timer = 0.0f;
	step = 0;
}


Enemy::~Enemy()
{
}

void Enemy::draw()
{
	if (enabled) 
	{
		DrawTextureEx(texture, { pos.x,pos.y }, 0.0f, scale, RED);
	}
}

void Enemy::attack(float deltaTime, std::vector<Bullet> bullets, Player player)
{
	if (timer >= attackSpeed)
	{
		switch (pattern)
		{
		case 0:
			//fires one at a time in all directions
			Vector2 temp;
			if (step >= 1 && step < 4) { temp.x = 1; }
			else if (step > 4 && step <= 7) { temp.x = -1; }
			else { temp.x = 0; }


			if (step > 2 && step < 6) { temp.y = 1; }
			else if (step < 2 || step == 7) { temp.y = -1; }
			else { temp.y = 0; }
			bullets.push_back(Bullet({ pos.x,pos.y }, RED, 1, { speed*temp.x, speed*temp.y }, ENEMY));
			step++;
			if (step < 7)
			{
				step = 0;
			}
			break;
		case 1:
			//four on carinal directions four on secondary directions
			if (step)
			{
				//carinal
				//up and down
				bullets.push_back(Bullet({ pos.x,pos.y }, RED, 1, { 0 , -speed }, ENEMY));
				bullets.push_back(Bullet({ pos.x,pos.y }, RED, 1, { 0, speed }, ENEMY));
				//side to side
				bullets.push_back(Bullet({ pos.x,pos.y }, RED, 1, { -speed, 0 }, ENEMY));
				bullets.push_back(Bullet({ pos.x,pos.y }, RED, 1, { speed, 0 }, ENEMY));
			}
			else
			{
				//right diags
				bullets.push_back(Bullet({ pos.x,pos.y }, RED, 1, { speed , -speed }, ENEMY));
				bullets.push_back(Bullet({ pos.x,pos.y }, RED, 1, { speed, speed }, ENEMY));
				//left diags
				bullets.push_back(Bullet({ pos.x,pos.y }, RED, 1, { -speed, -speed }, ENEMY));
				bullets.push_back(Bullet({ pos.x,pos.y }, RED, 1, { -speed, speed }, ENEMY));
			}
			step++;
			if (step > 1)
			{
				step = 0;
			}
			break;
		case 2:
			//fires AT THE PLAYER

			Vector2 temp;
			if (player.pos.x == pos.x)
			{
				temp.x = 0;
			}
			else if (player.pos.x <= pos.x)
			{
				temp.x = -1;
			}
			else
			{
				temp.x = 1;
			}

			//for why
			if (player.pos.y == pos.y)
			{
				temp.y = 0;
			}
			else if (player.pos.y <= pos.y)
			{
				temp.y = -1;
			}
			else
			{
				temp.y = 1;
			}
			//now for bullet
			bullets.push_back(Bullet({ pos.x,pos.y }, RED, 1, { speed * temp.x, speed *temp.y }, ENEMY));

			break;
		}
		timer = 0;
	}

	timer += deltaTime;


}
