#pragma once
#include<memory>
#include <random>

#include "Tank.h"


class AI_Action;

class Enemy : public Tank
{
	std::shared_ptr<AI_Action> aiAction;

	float stepSize = 30;

	std::shared_ptr<Entity> nemesis;


public:


	Enemy(EntityManager& control, sf::Color bodyColor = sf::Color::Red);
	~Enemy();

	void update(float deltaTime);

	void generateNewAction();

	void setNemesis(std::shared_ptr<Entity> target) { nemesis = target; }
	std::shared_ptr<Entity> getNemesis() const { return nemesis; }
};

