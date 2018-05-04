#pragma once
#include "Entity.h"

class Obstacle : public Entity
{
	sf::RectangleShape body;

	sf::Color bodyColor = sf::Color(255, 0, 255);
public:
	Obstacle(float x, float y, float w, float h);
	~Obstacle();


	void update(float deltaTime) override;

	void setPosition(const sf::Vector2f& position)override;
	sf::Vector2f getPosition() const override;

	void onCollision(const Entity& other)override;

protected:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

