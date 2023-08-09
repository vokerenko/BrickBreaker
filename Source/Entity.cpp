#include "stdafx.h"
#include "Utility.h"
#include "Entity.h"

Entity::Entity(sf::PrimitiveType type, sf::Vector2f position,
	sf::Vector2f size, sf::Color color)
	: m_vertices{ type }
{
	setPosition(position);
	switch (type)
	{
	case sf::Quads:
		setupQuads(position, size, color);
		break;
	default:
		break;
	}
}


void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = nullptr;
	target.draw(m_vertices, states);
}

void Entity::setupQuads(sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
	m_vertices.resize(4);
	m_vertices[0].position = sf::Vector2f(0.f, 0.f);
	m_vertices[1].position = sf::Vector2f(size.x, 0.f);
	m_vertices[2].position = size;
	m_vertices[3].position = sf::Vector2f(0.f, size.y);
	setupColor(color);

}
bool Entity::isColliding(Entity& other) const
{
	return getVertexArrayGlobalBounds().intersects(other.getVertexArrayGlobalBounds());
}
sf::FloatRect Entity::getVertexArrayGlobalBounds() const
{
	return sf::FloatRect(m_vertices.getBounds().left * getScale().x + getPosition().x,
		m_vertices.getBounds().top * getScale().y + getPosition().y,
		m_vertices.getBounds().width * getScale().x,
		m_vertices.getBounds().height * getScale().y);
}
void Entity::setupColor(sf::Color color)
{
	for (sf::Vertex& vertex : m_vertices)
	{
		vertex.color = color;
	}
}

sf::Vector2f Entity::getSize() const
{
	return sf::Vector2f(getVertexArrayGlobalBounds().width, getVertexArrayGlobalBounds().height);
}