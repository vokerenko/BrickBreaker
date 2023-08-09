#include "stdafx.h"
#include "Ball.h"
#include "BrickBreaker.h"
#include "Brick.h"

Ball::Ball(sf::Vector2f position, float radius, sf::Color color)
	: Entity(sf::Quads, position, sf::Vector2f(radius * 2, radius * 2), color)
	, m_circle(radius)
	, m_velocity(200.0f, -170.0f)
{
	setupColor(sf::Color::Transparent);
	m_circle.setFillColor(color);
}

void Ball::collision(Entity& other, bool vertical)
{
	if (isColliding(other))
	{
		m_velocity.x *= -1.0f;
		if (vertical)
		{
			m_velocity *= -1.0f;
		}
	}
}

void Ball::collision(BrickBreaker& bb)
{
	if (isColliding(bb))
	{
		setOrigin(getSize() / 2.f);
		bb.setOrigin(bb.getSize() / 2.f);
		m_velocity.y *= -1.0f;

		float deltaX = (getPosition().x + getOrigin().x) - (bb.getPosition().x + bb.getOrigin().x);
		m_velocity.x = abs(deltaX) / deltaX * 200.0f;
		if (abs(deltaX) >= 20.0f)
		{
			m_velocity.x += deltaX;
		}
		else
		{
			m_velocity.x -= deltaX + abs(deltaX) / deltaX * 50.0f;
		}

		setOrigin(0.0f, 0.0f);
		bb.setOrigin(0.0f, 0.0f);
	}
}

void Ball::collision(Brick& brick)
{
	sf::Vector2f delta{};
	sf::Vector2f intersect{};
	setOrigin(getSize() / 2.f);
	brick.setOrigin(brick.getSize() / 2.f);
	delta = (getPosition() + getOrigin()) - (brick.getPosition() + brick.getOrigin());
	intersect = abs(delta) - (getSize() + brick.getSize()) / 2.f;
	if (isColliding(brick))
	{
		if (intersect.x > intersect.y)
		{
			collision(brick, false);
		}
		if (intersect.y > intersect.x)
		{
			collision(brick, true);
		}
		// to do make so the brick really disappears and not just you know..
		brick.setPosition(-200.0f, -200.0f);
	}

	setOrigin(0, 0);
	brick.setOrigin(0, 0);
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = nullptr;
	target.draw(m_circle, states);
}