#include "Player.h"

Player::Player()
{
	sprite = LoadTexture("sloth.png");
	health = 5;
	pos = {400,250,64,64};
	speed = 200;
	playerAttackDmg = 1;
	scale = .5;
	bulletSpeed = 100;
}

Player::~Player()
{
}

void Player::playerDraw()
{
	DrawTextureEx(sprite, { pos.x ,pos.y }, 0, scale, BLUE);

}

void Player::playerMovement(float deltaTime, float screenX, float screenY)
{
	float size = pos.height * pos.width;
	// need to add an if player is on the ground
	if (IsKeyDown(KEY_W))
	{
		pos.y -= speed * deltaTime;
		if (pos.y < size * -1)
		{
			//no movement
		}
	}

	//player moves down
	if (IsKeyDown(KEY_S))
	{
		pos.y += speed * deltaTime;
		if (pos.y > screenY + size)
		{
			//no movement
		}
	}
	//moves right
	if (IsKeyDown(KEY_A))
	{
		//stoping the player from moving that way
		pos.x -= speed * deltaTime;
		if (pos.x < size * -1)
		{
			//no movement
		}
	}
	//moves left
	if (IsKeyDown(KEY_D))
	{
		pos.x += speed * deltaTime;
		if (pos.x > screenX + size)
		{
			//no movement
		}
	}
}

void Player::playerAttack(float deltaTime, std::vector<Bullet>& bullets)
{
	if (timer >= playerAttackSpeed) 
	{
		if (IsKeyPressed(KEY_UP)) 
		{
			bullets.push_back(Bullet({ pos.x,pos.y }, RED, 1, { 0, -bulletSpeed }, PLAYER));
		}
		else if(IsKeyPressed(KEY_DOWN))
		{
			bullets.push_back(Bullet({ pos.x,pos.y }, RED, 1, { 0, bulletSpeed }, PLAYER));
		}
		else if (IsKeyPressed(KEY_LEFT))
		{
			bullets.push_back(Bullet({ pos.x,pos.y }, RED, 1, { -bulletSpeed, 0 }, PLAYER));
		}
		else if (IsKeyPressed(KEY_RIGHT))
		{
			bullets.push_back(Bullet({ pos.x,pos.y }, RED, 1, { bulletSpeed, 0 }, PLAYER));
		}
		timer = 0;
	}
}
