#pragma once
#include<memory>
#include<vector>
#include<algorithm>

#include<SFML\Graphics.hpp>

#include"Entity.h"
#include"Tank.h"
#include"Collidable.h"

class EntityManager : public sf::Drawable
{
	std::vector< std::shared_ptr<Entity> > entities;

public:
	EntityManager();
	~EntityManager();

	void addEntity(std::shared_ptr<Entity> entity);
	void removeEntity(std::shared_ptr<Entity> entity);

	void update(float deltaTime);
	void fixedUpdate(float deltaTime);

	void performAction(std::shared_ptr<Tank> entity);

protected:	
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

