#include "stdafx.h"
#include "Border.h"


Border::Border(float x, float y, float w, float h)
	:Obstacle(x,y,w,h)
{
	body.setOutlineColor(sf::Color::White);
	type = EntityType::BORDER;
}


Border::~Border()
{
}

void Border::onCollision(const Entity & other)
{

}
