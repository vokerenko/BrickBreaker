#pragma once
#include "Entity.h"

class Wall;
class BrickBreaker : public Entity
{
public:
	BrickBreaker();

	void collision(Wall& wall);

private:
};

