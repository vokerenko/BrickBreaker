#include "stdafx.h"
#include "Wall.h"

Wall::Wall(sf::Vector2f position, sf::Vector2f size, sf::Color color)
	: Entity{ sf::Quads,
			  position,
			  size,
			  color }
{

}