#include "stdafx.h"
#include "Collidable.h"

#include "Entity.h"




Collidable::Collidable(Entity& owner, Type type) :owner(owner), type(type)
{
}
Collidable::~Collidable()
{
}
sf::Vector2f Collidable::getPosition() const
{
	return owner.getPosition(); 
}




CircleCollider::CircleCollider(Entity& owner, float radius)
	:Collidable(owner, CIRCLE), radius(radius)
{	
}

bool CircleCollider::collidesWith(std::shared_ptr<Collidable> target) const
{
	//normal distance from edge of a target to our center
	if (target->type == CIRCLE)
	{
		//TODO: check precision
		if (target->getNormalDistTo(owner.getPosition()) > radius)
			return false;
	}
	if (target->type == BOX)
	{
		BoxCollider* box = static_cast<BoxCollider*>(target.get());

		auto pos = box->getPosition();		
		auto size = box->getSize();

		sf::FloatRect rect( pos.x - radius, pos.y - radius, 
							size.x + radius*2, size.y + radius*2 );
		return  rect.contains( getPosition() );
		
	}

	return true;
}

float CircleCollider::getNormalDistTo(const sf::Vector2f & point) const
{
	float dist = sqrtf(powf(point.x - owner.getPosition().x, 2)
		+ powf(point.y - owner.getPosition().y, 2));
	dist -= radius;
	return dist;
}





BoxCollider::BoxCollider(Entity & owner, const sf::Vector2f& size)
	:Collidable(owner, BOX), size(size)
{
}

bool BoxCollider::collidesWith(std::shared_ptr<Collidable> target) const
{
	sf::Vector2f pos1 = owner.getPosition();	
	sf::Vector2f pos2 = target->getOwner().getPosition();

	if (target->type == CIRCLE)
	{
		CircleCollider* circle = static_cast<CircleCollider*>( target.get() );
		float r = circle->getRadius();
		sf::FloatRect rect(pos1.x - r, pos1.y - r, size.x + r*2, size.y + r*2);
		return rect.contains(pos2);
	}
	if (target->type == BOX)
	{
		BoxCollider* box = static_cast<BoxCollider*>(target.get());

		sf::FloatRect rect(pos1, size);
		return rect.intersects(sf::FloatRect(pos2, box->getSize()));
	}	

	return false;
}


float BoxCollider::getNormalDistTo(const sf::Vector2f & point) const
{
	//TODO: dist to closest side
	
	return 0.0f;
}
