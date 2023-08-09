#pragma once
#include "stdafx.h"

class VertexArray : public sf::VertexArray
{
public:
	//VertexArray() : sf::VertexArray() {};
	//VertexArray(sf::PrimitiveType type, std::size_t vertexCount = 0) : sf::VertexArray(type, vertexCount) {};
	using sf::VertexArray::VertexArray;

	sf::Vertex* begin()
	{
		return &((*this)[0]);
	}
	sf::Vertex* end()
	{
		return &((*this)[0]) + getVertexCount();
	}
};
namespace Constants
{
	namespace Window
	{
		constexpr int Width = 800;
		constexpr int Height = 1000;
	}
	namespace BrickBreaker
	{
		constexpr float Width = 120.0f;
		constexpr float Height = 10.0f;
		constexpr float PositionX = Window::Width / 2.0f - BrickBreaker::Width / 2.0f;
		constexpr float PositionY = Window::Height - BrickBreaker::Height * 3.0f;
	}
}

template<typename T>
inline sf::Vector2<T> abs(sf::Vector2<T>& value) { return sf::Vector2<T>(abs(value.x), abs(value.y)); }

template<typename T>
inline std::ostream& operator<< (std::ostream& out, const sf::Vector2<T>& vec)
{
	out << "{ x:" << vec.x << " y:" << vec.y << " }";
	return out;
}
template<typename T>
inline std::ostream& operator<< (std::ostream& out, const sf::Rect<T> r)
{
	out << "{ left:" << r.left << ", top:" << r.top << ", width:" << r.width << ", height:" << r.height;
	return out;
}