#include "stdafx.h"
#include<memory>

#include "Actions.h"
#include "Tank.h"
#include "Bullet.h"


void ShootAction::execute() {
	std::cout << "Bang!" << std::endl;
	//std::make_shared<Bullet>( owner.getPosition().x, owner.getPosition().y, 0, 0);
};

