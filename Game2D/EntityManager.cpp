#include "stdafx.h"
#include "EntityManager.h"
#include "Actions.h"

using namespace std;

EntityManager::EntityManager()
{
	
}


EntityManager::~EntityManager()
{
}

void EntityManager::addEntity(std::shared_ptr<Entity> entity)
{
	//TODO: Inefficient
	auto r = std::find(entities.begin(), entities.end(), entity);
	if (r == entities.end()) 
	{
		entities.push_back(entity);	

	}

	cout << entities.size() <<endl;
}

void EntityManager::removeEntity(std::shared_ptr<Entity> entity)
{
	entities.erase(std::find(entities.begin(), entities.end(), entity));
}

void EntityManager::update(float deltaTime)
{
	for (auto itr = entities.begin(); itr != entities.end(); itr++)
	{		
		auto entity1 = *itr;

		for (auto itr2 = itr + 1; itr2 != entities.end(); itr2++) {
			auto entity2 = *itr2;
			//Notify both
			if (entity1->collidesWith(*entity2)) {				
				entity1->onCollision(*entity2);
				entity2->onCollision(*entity1);
			}
		}		
		entity1->update(deltaTime);
	}
}

void EntityManager::fixedUpdate(float deltaTime)
{	
	entities.erase(
		remove_if(begin(entities), end(entities),
			[](auto ent) {return ent->getStatus() == Entity::DEAD; })
		, entities.end()
	);
}

void EntityManager::performAction(std::shared_ptr<Tank> entity)
{
	auto action = entity->getAction();
	if (action == nullptr) return;

	action->execute(*this);
}

void EntityManager::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto entity : entities)
	{
		target.draw(*entity, states);

	}
}
