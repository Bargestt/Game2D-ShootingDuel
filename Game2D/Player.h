#pragma once
#include<memory>

#include"Tank.h"
#include"Actions.h"


class Player : public Tank
{
public:
	enum RotationType {
		NO_ROTATION, ROTATE_LEFT, ROTATE_RIGHT
	}; 
	enum MoveType {
		NO_MOVEMENT, MOVE_FORWARD, MOVE_BACKWARD
	};


private:	
	std::shared_ptr<Action> action;

public:
	Player();
	Player(float size, float gunLen, sf::Color bodyColor);
	~Player();

	void update(float deltaTime);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void doAction();

	void onCollision(const Entity & other) {
		Tank::onCollision(other);
		
		if (other.getType() == EntityType::BULLET) {
			//TODO: increment points
			//TODO: Show hit animation	
		}
	}
};

