#pragma once
#include<SFML\Graphics.hpp>
#include <memory>

#include "..\Collidable.h"


class EntityManager;

class Entity : public sf::Drawable
{
public:
	enum EntityType { NONE, TANK, ENEMY, PLAYER, BULLET, OBSTACLE, BORDER, DEATH };
	enum Status {	
		ALIVE, 
		DEAD, //No collsions, delete on next fixedUpdate
	};


private:	
	std::string name = "AbstractEntity"; // name for debug purpose or maybe more
	EntityManager& control;
public:
	Entity(EntityManager& control);
	~Entity() {};

	virtual void update(float deltaTime) =0;
	virtual void fixedUpdate(float deltaTime);

	virtual void setPosition(const sf::Vector2f& position) = 0;
	virtual sf::Vector2f getPosition() const = 0;


	//Collisions
	virtual void onCollision(const Entity& other) = 0;	
	bool collidesWith(const Entity& target) const;

	std::shared_ptr<Collidable> getCollider() const;
	EntityManager& getControl();
	
	//Identification
	EntityType getType()const;
	Status getStatus()const;

	std::string getName() const;
	void setName(const std::string& name);

protected:
	EntityType type = NONE;
	Status status = ALIVE;
	
	std::shared_ptr<Collidable> collider;


	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};

