#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "EntityManager.h"

using namespace std;
using namespace sf;

Player::Player()
{
	setName("Player");
	//type = PLAYER;
}

Player::Player(float size, float gunLen, sf::Color bodyColor)
	:Tank(size, gunLen, bodyColor)
{
	setName("Player");
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





