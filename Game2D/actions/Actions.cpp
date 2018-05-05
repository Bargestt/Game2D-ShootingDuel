#include "..\stdafx.h"
#include<memory>

#include "Actions.h"
#include "..\entity\Tank.h"
#include "..\entity\Bullet.h"
#include "..\entity\EntityManager.h"


void ShootAction::execute(EntityManager& control) {
	sf::Vector2f gunPoint = owner.getPosition();
	gunPoint.x  += static_cast<float>(cos(owner.getAngle() * M_PI / 180)) * owner.getGunLength();
	gunPoint.y  += static_cast<float>(sin(owner.getAngle() * M_PI / 180)) * owner.getGunLength();

	auto bullet = std::make_shared<Bullet>(
											owner, 
											gunPoint, 
											owner.getAngle(), 
											owner.getBulletSpeed(), 
											owner.getCaliber() );
	control.addEntity(bullet);

};

