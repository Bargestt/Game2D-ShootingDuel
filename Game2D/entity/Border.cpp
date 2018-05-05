#include "..\stdafx.h"
#include "Border.h"


Border::Border(EntityManager& control, float x, float y, float w, float h)
	: Obstacle(control, x,y,w,h)
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
