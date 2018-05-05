#include "..\stdafx.h"
#include "Entity.h"

#include"EntityManager.h"

Entity::Entity(EntityManager & control)
	:control(control)
{
}

EntityManager & Entity::getControl()
{
	return control;
}

bool Entity::collidesWith(const Entity & target) const
{
	if (collider == nullptr) return false;
	if (target.getCollider() == nullptr) return false;
	if (status == DEAD) return false;
	if (target.getStatus() == DEAD) return false;

	return collider->collidesWith(target.getCollider());
}
