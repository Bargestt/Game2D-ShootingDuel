#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "EntityManager.h"

using namespace std;
using namespace sf;

Player::Player()
	:action(make_shared<ShootAction>(*this))
{
	name = "Player";
	//type = PLAYER;
}

Player::Player(float size, float gunLen, sf::Color bodyColor)
	:Tank(size, gunLen, bodyColor)
{
	name = "Player";
	//type = PLAYER;
}


Player::~Player()
{
	
}

void Player::update(float deltaTime)
{
	Tank::update(deltaTime);

}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	Tank::draw(target, states);
}

void Player::doAction()
{
	if (control != nullptr) 
	{
		Vector2f gunPoint = getPosition();
		gunPoint.x  += static_cast<float>(cos(getAngle() * M_PI / 180)) * getGunLength();
		gunPoint.y  += static_cast<float>(sin(getAngle() * M_PI / 180)) * getGunLength();
		control->addEntity(make_shared<Bullet>(*this, gunPoint, getAngle(), getBulletSpeed(), getCaliber()));
	}		
}




