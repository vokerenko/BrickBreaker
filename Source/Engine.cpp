#include "stdafx.h"
#include "Utility.h"
#include "BrickBreaker.h"
#include "Wall.h"
#include "Engine.h"

Engine::Engine()
	: m_video_mode{ Constants::Window::Width, Constants::Window::Height }, m_window{ m_video_mode, "BrickBreaker" }
	, m_event{}
	, m_brickBreaker{}
	, m_dt{ m_clock.restart().asSeconds() }
	, m_leftWall{ sf::Vector2f(0.0f, 0.0f), sf::Vector2f(30.0f, Constants::Window::Height) }
	, m_upWall{ sf::Vector2f(30.0f, 0.0f), sf::Vector2f(Constants::Window::Width - 30.0f, 30.0f) }
	, m_rightWall{ sf::Vector2f(Constants::Window::Width - 30.0f, 30.0f), sf::Vector2f(30.0f, Constants::Window::Height - 30.0f) }
	, m_ball{ sf::Vector2f(Constants::BrickBreaker::PositionX + Constants::BrickBreaker::Width / 2.0f - 15.0f, Constants::BrickBreaker::PositionY - 15.0f * 2), 15.0f }

{
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			m_bricks.push_back(Brick(sf::Vector2f(100.0f + 400.0f * i, 60.0f + 200.0f * j), sf::Vector2f(150.0f, 50.0f)));
		}
	}

}

void Engine::update()
{
	m_dt = m_clock.restart().asSeconds();
	handleEvents();
	m_brickBreaker.collision(m_leftWall);
	m_brickBreaker.collision(m_rightWall);
	m_ball.move(m_ball.m_velocity * m_dt);
	m_ball.collision(m_brickBreaker);
	m_ball.collision(m_leftWall, false);
	m_ball.collision(m_rightWall, false);
	m_ball.collision(m_upWall, true);
	for (Brick& brick : m_bricks)
	{
		m_ball.collision(brick);
	}

}
void Engine::render()
{
	m_window.clear();

	m_window.draw(m_brickBreaker);
	m_window.draw(m_leftWall);
	m_window.draw(m_upWall);
	m_window.draw(m_rightWall);
	m_window.draw(m_ball);
	for (const Brick& brick : m_bricks)
	{
		m_window.draw(brick);
	}
	m_window.display();

}
void Engine::handleEvents() {
	while (m_window.pollEvent(m_event))
	{
		switch (m_event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		default:
			continue;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		m_window.close();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_brickBreaker.move(sf::Vector2f(200.0f * m_dt, 0.0f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_brickBreaker.move(sf::Vector2f(-200.0f * m_dt, 0.0f));
	}


}