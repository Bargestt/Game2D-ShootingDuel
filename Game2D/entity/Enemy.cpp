#include "..\stdafx.h"


#include "Enemy.h"
#include"..\actions\AIActions.h"

using namespace std;

Enemy::Enemy(EntityManager& control, sf::Color bodyColor)
	:Tank(control, 30, 50, bodyColor)
{
	setName("Tank");
	//type = ENEMY;

	aiAction = make_shared<AI_ShootAt>(*this, sf::Vector2f(0,0));
}

Enemy::~Enemy()
{
}

void Enemy::update(float deltaTime)
{
	Tank::update(deltaTime);
	aiAction->execute(deltaTime);

	if ( aiAction->isCompleted() ) {		
		generateNewAction();
	}
}

void Enemy::generateNewAction()
{
	random_device device;
	mt19937 mt(device());
	std::uniform_real_distribution<float> rnd(0, 10);

	std::uniform_real_distribution<float> rnd2(0.1, 2);

	aiAction->complete();

	// no timeot for shooting, so it can do funny bursts, it's bug tho
	switch (static_cast<int>(rnd(mt))) {
	case 0:
		aiAction = make_shared<AI_MoveForward>(*this, rnd2(mt));
		break;
	case 1:
		aiAction = make_shared<AI_MoveBackward>(*this, rnd2(mt));
		break;
	case 2:
		aiAction = make_shared<AI_TurnLeft>(*this, rnd2(mt));
		break;
	case 3:
		aiAction = make_shared<AI_TurnRight>(*this, rnd2(mt));
		break;
	default:
		if(nemesis != nullptr)
			aiAction = make_shared<AI_ShootAt>(*this, nemesis->getPosition());
		break;
	}
}
