#include "stdafx.h"
#include "AIActions.h"
#include"Tank.h"

using namespace std;


AI_Move::AI_Move(Tank & owner, sf::Vector2f dest)
	:AI_Action(owner), destination(dest)
{
}
void AI_Action::execute(float deltaTime)
{
	lifetime -= deltaTime;
	if (lifetime < 0) complete();
	action();
}

void AI_Move::action()
{
	auto oPos = owner.getPosition();

	float oAngle= owner.getAngle();

	float dx = destination.x - oPos.x;
	float dy = destination.y - oPos.y;

	float mDist = fabsf(dx) + fabsf(dy);
	if (mDist < owner.getBodyRadius()) 
	{
		complete();
		owner.setMoveForward(false);
	}
	else 
	{
		owner.setMoveForward(true);
	}	

	float angleToDest = static_cast<float>(atan2f(dy, dx) / M_PI * 180);
	if (angleToDest < 0) angleToDest += 360.0f;

	float dAngle = angleToDest - oAngle;


	if (fabsf(dAngle) <= 1.0f) {
		owner.setTurnLeft(false);
		return;
	}
	//cout << oAngle << endl;

	owner.setTurnLeft(true);	
}

