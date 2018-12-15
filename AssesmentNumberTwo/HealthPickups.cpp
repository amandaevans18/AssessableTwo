#include "HealthPickups.h"

HealthPickups::HealthPickups(Rectangle _pos, Color _color, int _val) 
{
	pos = _pos;
	val = _val;
	color = _color;
}

void HealthPickups::draw()
{
	if (enabled) 
	{
	 //draw
		DrawRectangleRec(pos, color);
	}
}

bool HealthPickups::pickupCollected(Player player)
{
	if (enabled && CheckCollisionRecs(pos, player.pos)) 
	{
		player.health += val;
		enabled = false;
	}
	return false;
}
