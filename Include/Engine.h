#pragma once
#include "Entity.h"
#include "BrickBreaker.h"
#include "Wall.h"
#include "Ball.h"
#include "Brick.h"

class Engine
{
public:
	// Constructors
	Engine();

	// Methods
	void update();
	void render();

	// Accessors
	bool isRunning() const { return m_window.isOpen(); };

private:
	sf::VideoMode m_video_mode;
	sf::RenderWindow m_window;
	sf::Event m_event;
	sf::Clock m_clock;
	BrickBreaker m_brickBreaker;
	Wall m_leftWall;
	Wall m_upWall;
	Wall m_rightWall;
	Ball m_ball;
	std::vector<Brick> m_bricks;
	float m_dt;

	// Methods
	void handleEvents();
};

