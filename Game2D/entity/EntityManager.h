#pragma once
#include<memory>
#include<vector>
#include<algorithm>

#include<SFML\Graphics.hpp>

#include"Entity.h"
#include"Tank.h"
#include"..\Collidable.h"
#include"..\Renderer.h"
class EntityManager
{
	std::vector< std::shared_ptr<Entity> > entities;

	std::vector< std::shared_ptr<Entity> > insertQueue;


public:
	EntityManager();
	~EntityManager();

	void addEntity(std::shared_ptr<Entity> entity);
	void removeEntity(std::shared_ptr<Entity> entity);

	void update(float deltaTime);
	void fixedUpdate(float deltaTime);

	void render(std::shared_ptr<Renderer> renderer);

};

