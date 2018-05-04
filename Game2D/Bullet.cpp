#include "stdafx.h"
#include "Bullet.h"
#include "EntityManager.h"

using namespace std;
using namespace sf;

Bullet::Bullet(Tank& source, sf::Vector2f pos, float angle, float speed, float size)
	:source(source), angle(angle), speed(speed)
{
	setName("Bullet");
	type = BULLET;

	speedX = static_cast<float>(cos(angle * M_PI / 180)) * speed;
	speedY = static_cast<float>(sin(angle * M_PI / 180)) * speed;

	body.setRadius(size);
	body.setOrigin(size, size);
	body.setFillColor(sf::Color::White);
	body.setPosition(pos);

	collider = std::make_shared<CircleCollider>(*this, size);
}


Bullet::~Bullet()
{
	
}

void Bullet::update(float deltaTime)
{	
	body.move(speedX*deltaTime, speedY*deltaTime);
}

void Bullet::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(body, states);
}

void Bullet::onCollision(const Entity& other)
{
	EntityType type = other.getType();
	if (type == TANK)
	{
		status = DEAD;
		source.setScore(source.getScore() + 1);
	}
	else if (type == OBSTACLE)
	{
		ricohet( *other.getCollider() );
	}
	else if (type == BORDER)
	{
		status = DEAD;
	}
}

void Bullet::ricohet(const Collidable & collider)
{
	if (collider.type == Collidable::CIRCLE)
	{
		//TEMP
		status = DEAD;
	}
	if (collider.type == Collidable::BOX)
	{
		const BoxCollider& box = static_cast<const BoxCollider&>(collider);

		FloatRect rect(box.getPosition(), box.getSize());
		Vector2f p = body.getPosition();

		if (rect.contains(p)) {
			//Shouldn't happen in most cases, 
			//but if it does, some adjustments required			
		}

		// TEMPORARY VERSION
		//TODO: make vectorised version
		float horiz = fminf( fabsf(p.y - rect.top), 
							 fabsf(p.y - (rect.top + rect.height)) );

		float vert = fminf( fabsf(p.x - rect.left),
							fabsf(p.x - (rect.left + rect.width)) );

		if (horiz < vert) {
			//horizontal collision
			speedY = -speedY;
		}
		else {
			//vertical collision
			speedX= -speedX;
		}		
	}
}

void Bullet::setAngle(float angle)
{
	this->angle = angle;
	speedX = static_cast<float>(cos(angle * M_PI / 180)) * speed;
	speedY = static_cast<float>(sin(angle * M_PI / 180)) * speed;
}
