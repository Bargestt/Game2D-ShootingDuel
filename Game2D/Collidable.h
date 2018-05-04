#pragma once
#include<SFML\Graphics\Rect.hpp>

#include<SFML\System\Vector2.hpp>
#include<memory>

class Entity;

class Collidable
{
protected:
	Entity & owner;

	bool ghostMode = false;
	
public:	
	enum Type { BOX, CIRCLE };
	const Type type;

	Collidable(Entity& owner, Type type);
	virtual ~Collidable();	

	bool isGhost()const { return ghostMode; }

	virtual bool collidesWith(std::shared_ptr<Collidable> target)const = 0;
	virtual float getNormalDistTo(const sf::Vector2f& point)const = 0;

	Entity &getOwner() const { return owner; }
	sf::Vector2f getPosition() const;

};


class CircleCollider : public Collidable
{		
private:	
	float radius = 10;
	
public:
	CircleCollider(Entity& owner, float radius);

	void setRadius(float r) { radius = r; }
	float getRadius() const { return radius; }

	bool collidesWith(std::shared_ptr<Collidable> target)const override;

	virtual float getNormalDistTo(const sf::Vector2f& point)const;
};


class BoxCollider : public Collidable
{	
private:
	sf::Vector2f size;
public:
	BoxCollider(Entity& owner, const sf::Vector2f& size);


	bool collidesWith(std::shared_ptr<Collidable> target)const override;

	virtual float getNormalDistTo(const sf::Vector2f& point)const;

	sf::Vector2f getSize() const { return size; }
};