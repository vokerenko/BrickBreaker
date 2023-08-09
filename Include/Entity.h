#pragma once
#include "Utility.h"

class Entity : public sf::Drawable, public sf::Transformable
{
public:

	Entity(sf::PrimitiveType type, sf::Vector2f position = sf::Vector2f(0.f, 0.f),
		sf::Vector2f size = sf::Vector2f(200.f, 200.f),
		sf::Color color = sf::Color::Red);

	sf::Vector2f getSize() const;
	sf::FloatRect getVertexArrayGlobalBounds() const;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void setupQuads(sf::Vector2f position = sf::Vector2f(0.f, 0.f),
		sf::Vector2f size = sf::Vector2f(200.f, 200.f),
		sf::Color color = sf::Color::Red);


protected:
	void setupColor(sf::Color color);
	bool isColliding(Entity& other) const;
protected:
	VertexArray m_vertices;
};


