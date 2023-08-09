#include "stdafx.h"
#include "Brick.h"

Brick::Brick(sf::Vector2f position, sf::Vector2f size, sf::Color color)
	: Entity{ sf::Quads,
			  position,
			  size,
			  color }
{
}
