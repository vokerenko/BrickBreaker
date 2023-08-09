#include "stdafx.h"
#include "Utility.h"
#include "BrickBreaker.h"
#include "Wall.h"

using namespace Constants::BrickBreaker;

BrickBreaker::BrickBreaker()
	: Entity{ sf::Quads,
			  sf::Vector2f(PositionX, PositionY),
			  sf::Vector2f(Width, Height),
			  sf::Color::Red
}
{

}

void BrickBreaker::collision(Wall& wall)
{
	sf::Vector2f delta{};
	sf::Vector2f intersect{};
	setOrigin(getSize() / 2.f);
	wall.setOrigin(wall.getSize() / 2.f);
	delta = (getPosition() + getOrigin()) - (wall.getPosition() + wall.getOrigin());
	intersect = abs(delta) - (getSize() + wall.getSize()) / 2.f;
	if (isColliding(wall))
	{
		if (intersect.x > intersect.y)
		{
			if (delta.x > 0.f)
			{
				move(-intersect.x, 0.f);
			}
			else if (delta.x < 0.f)
			{
				move(intersect.x, 0.f);
			}
		}
		if (intersect.y > intersect.x)
		{
			if (delta.y > 0.f)
			{
				move(0.f, -intersect.y);
			}
			else if (delta.y < 0.f)
			{
				move(0.f, intersect.y);
			}
		}
	}
	setOrigin(0, 0);
	wall.setOrigin(0, 0);
}
