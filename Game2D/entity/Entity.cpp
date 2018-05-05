#include "..\stdafx.h"
#include "Entity.h"

bool Entity::collidesWith(const Entity & target) const	
{
	if (collider == nullptr) return false;
	if (target.getCollider() == nullptr) return false;
	if (status == DEAD) return false;
	if (target.getStatus() == DEAD) return false;

	return collider->collidesWith(target.getCollider());
}
