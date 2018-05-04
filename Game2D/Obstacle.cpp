#include "stdafx.h"
#include "Obstacle.h"




Obstacle::Obstacle(float x, float y, float w, float h)	
{
	name = "Obstacle";
	body.setPosition(x, y);
	body.setSize(sf::Vector2f(w, h));
	body.setFillColor(sf::Color::Transparent);

	body.setOutlineThickness(3);
	body.setOutlineColor(bodyColor);

	collider = std::make_shared<BoxCollider>(*this, body.getSize());

	type = OBSTACLE;
}

Obstacle::~Obstacle()
{
}

void Obstacle::update(float deltaTime)
{
}

void Obstacle::setPosition(const sf::Vector2f & position)
{
	body.setPosition(position);
}

sf::Vector2f Obstacle::getPosition() const
{
	return body.getPosition();
}

void Obstacle::onCollision(const Entity & other)
{
}

void Obstacle::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(body, states);
}
