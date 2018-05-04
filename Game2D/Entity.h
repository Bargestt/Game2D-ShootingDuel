#pragma once
#include<SFML\Graphics.hpp>
#include <memory>

#include "Collidable.h"

class EntityManager;

class Entity : public sf::Drawable
{
protected:	
	std::string name = "AbstractEntity"; // name for debug purpose or maybe more
public:
	enum EntityType { NONE, TANK, ENEMY, PLAYER, BULLET, OBSTACLE, DEATH };
	enum Status { 
		ALIVE, 
		DEAD, //No collsions, delete on next fixedUpdate
		GHOST, //Ignored in collsion checks of others, but can collide 
		NO_CLIP // no collisions
	};

	Entity() {};
	~Entity() {};

	virtual void update(float deltaTime) =0;

	virtual void setPosition(const sf::Vector2f& position) = 0;
	virtual sf::Vector2f getPosition() const = 0;

	virtual void onCollision(const Entity& other) = 0;
	
	std::shared_ptr<Collidable> getCollider() const { return collider; }

	bool collidesWith(const Entity& target) const;

	EntityType getType()const { return type; }
	Status getStatus()const { return status; }

	std::string getName() const { return name; }

protected:
	EntityType type = NONE;
	Status status = ALIVE;

	//TODO: fix this shit
	friend class EntityManager;
	EntityManager* control = nullptr;
	void setControl(EntityManager* control) { this->control = control; }
	
	std::shared_ptr<Collidable> collider;


	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};
