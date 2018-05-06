#include "..\stdafx.h"
#include "AIActions.h"
#include"..\entity\Tank.h"

using namespace std;



void AI_Action::execute(float deltaTime)
{
	lifetime -= deltaTime;
	if (lifetime < 0) { 
		complete(); 
		return;
	}
	action();
}


AI_Move::AI_Move(Enemy & owner, sf::Vector2f dest)
	:AI_Action(owner), destination(dest)
{
	cout << destination.x << " : " << destination.y << endl;
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

	float desiredAngle = static_cast<float>(atan2f(dy, dx) / M_PI * 180);

	float dAngle = desiredAngle - owner.getAngle();
	if (dAngle < -180)dAngle += 360.0f;
	if (dAngle >= 180)dAngle -= 360.0f;

	if (fabsf(dAngle) <= 1.0f) {
		owner.setTurnLeft(false);
		owner.setTurnRight(false);
		return;
	}

	if (dAngle < 0)
		owner.setTurnLeft(true);
	if (dAngle > 0)
		owner.setTurnRight(true);
}



AI_ShootAt::AI_ShootAt(Enemy & owner, sf::Vector2f target)
	:AI_Action(owner), target(target)
{
	owner.setMoveForward(false);
	owner.setMoveBackward(false);

	auto oPos = owner.getPosition();
	float oAngle = owner.getAngle();

	float dx = target.x - oPos.x;
	float dy = target.y - oPos.y;

	desiredAngle = static_cast<float>(atan2f(dy, dx) / M_PI * 180);

	float dAngle = desiredAngle - owner.getAngle();
	if (dAngle < -180)dAngle += 360.0f;
	if (dAngle >= 180)dAngle -= 360.0f;

	if(dAngle < 0)
		owner.setTurnLeft(true);
	if(dAngle > 0)
		owner.setTurnRight(true);
	//cout << dAngle << endl;
}

void AI_ShootAt::action()
{
	float dAngle = desiredAngle - owner.getAngle();
	if (dAngle < -180)dAngle += 360.0f;
	if (dAngle >= 180)dAngle -= 360.0f;

	if (fabsf(dAngle) <= 1.0f) {
		owner.setTurnLeft(false);
		owner.setTurnRight(false);
		owner.doAction();
		complete();
		return;
	}
}
