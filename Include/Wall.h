#pragma once
#include "Entity.h"

class Wall : public Entity
{
public:
	Wall(sf::Vector2f position, sf::Vector2f size, sf::Color color = sf::Color::Yellow);
};


