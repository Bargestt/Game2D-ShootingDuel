#include "..\stdafx.h"
#include "Entity.h"

#include"EntityManager.h"

Entity::Entity(EntityManager & control)
	:control(control)
{
}

void Entity::fixedUpdate(float deltaTime)
{
}

bool Entity::collidesWith(const Entity & target) const
{
	if (collider == nullptr) return false;
	if (target.getCollider() == nullptr) return false;
	if (status == DEAD) return false;
	if (target.getStatus() == DEAD) return false;

	return collider->collidesWith(target.getCollider());
}



std::shared_ptr<Collidable> Entity::getCollider() const
{
	return collider;
}

EntityManager & Entity::getControl()
{
	return control;
}

Entity::EntityType Entity::getType() const
{
	return type;
}

Entity::Status Entity::getStatus() const
{
	return status;
}

std::string Entity::getName() const
{
	return name;
}

void Entity::setName(const std::string & name)
{
	this->name = name;
}
