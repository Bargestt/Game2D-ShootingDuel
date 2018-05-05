#include "..\stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "EntityManager.h"

using namespace std;
using namespace sf;


Player::Player(EntityManager& control, sf::Color bodyColor)
	:Tank(control, 30, 50, bodyColor)
{
	setName("Player");
	//type = PLAYER;
}


Player::~Player()
{
	
}






