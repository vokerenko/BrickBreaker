#pragma once
#include "Entity.h"

class Brick : public Entity
{
public:
	Brick(sf::Vector2f position, sf::Vector2f size, sf::Color color = sf::Color::Cyan);

};

