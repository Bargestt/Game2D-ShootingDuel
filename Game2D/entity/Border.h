#pragma once
#include"Obstacle.h"
class Border : public Obstacle
{	
public:
	Border(EntityManager& control, float x, float y, float w, float h);
	~Border();

public:

	virtual void onCollision(const Entity& other)override;
};


