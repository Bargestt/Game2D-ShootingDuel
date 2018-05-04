#include "stdafx.h"


#include "Enemy.h"
#include"AIActions.h"

using namespace std;

Enemy::Enemy(float size, float gunLen, sf::Color bodyColor)
	:Tank(size, gunLen, bodyColor)
{
	name = "Tank";
	//type = ENEMY;

	curAction = make_shared<AI_Move>(*this, sf::Vector2f(0,0));
}

Enemy::~Enemy()
{
}

void Enemy::update(float deltaTime)
{
	Tank::update(deltaTime);
	curAction->execute(deltaTime);

	if ( curAction->isCompleted() ) {		
		generateNewAction();
	}
}

void Enemy::generateNewAction()
{
	random_device device;
	mt19937 mt(device());
	std::uniform_real_distribution<float> rnd(0, 5);

	cout << "NEW ACTION\n";
	switch (static_cast<int>(rnd(mt))) {
	case 0:
		curAction = make_shared<AI_MoveForward>(*this);
		break;
	case 1:
		curAction = make_shared<AI_MoveBackward>(*this);
		break;
	case 2:
		curAction = make_shared<AI_TurnLeft>(*this);
		break;
	case 3:
		curAction = make_shared<AI_TurnRight>(*this);
		break;
	}
}
