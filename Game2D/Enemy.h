#pragma once
#include<memory>
#include <random>

#include "Tank.h"


class AI_Action;

class Enemy : public Tank
{
	std::shared_ptr<AI_Action> curAction;

	float stepSize = 30;




public:

	Enemy(float size, float gunLen, sf::Color bodyColor = sf::Color::Red);
	~Enemy();

	void update(float deltaTime);

	void generateNewAction();
};

