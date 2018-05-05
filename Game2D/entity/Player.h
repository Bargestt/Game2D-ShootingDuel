#pragma once
#include<memory>

#include"Tank.h"
#include"..\actions\Actions.h"


class Player : public Tank
{
public:


private:	


public:
	Player();
	Player(EntityManager& control, sf::Color bodyColor = sf::Color::Green);
	~Player();
};

