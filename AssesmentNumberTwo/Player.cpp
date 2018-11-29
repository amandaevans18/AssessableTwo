#include "Player.h"

void Player::draw()
{
	sprite = LoadTexture(spriteName.c_str());
	DrawTexture(sprite, pos.x, pos.y, WHITE);

}

void Player::movement(float deltaTime, float screenX, float screenY)
{
	float size = height * width;
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
