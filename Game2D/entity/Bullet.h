#pragma once
#include "Entity.h"
#include "Tank.h"

class Bullet : public Entity
{
	sf::CircleShape body;

	Tank& source;

	float angle;
	float speed;

	float speedX;
	float speedY;

public:
	Bullet(Tank& source, sf::Vector2f pos, float angle, float speed, float size);
	~Bullet();

	void update(float deltaTime) override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual void setPosition(const sf::Vector2f& position) { body.setPosition(position); }
	virtual sf::Vector2f getPosition() const { return body.getPosition(); }

	void onCollision(const Entity& other);

	void ricohet(const Collidable& collider);
	void setAngle(float angle);
};

