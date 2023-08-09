#pragma once
#include "Entity.h"

class Brick;
class BrickBreaker;
class Ball : public Entity
{
public:
	Ball(sf::Vector2f position, float radius, sf::Color color = sf::Color::Green);

	void collision(Entity& other, bool vertical);
	void collision(BrickBreaker& bb);
	void collision(Brick& brick);

	sf::Vector2f m_velocity;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::CircleShape m_circle;

};


