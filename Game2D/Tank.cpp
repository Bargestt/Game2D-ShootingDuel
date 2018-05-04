#include "stdafx.h"
#include "Tank.h"
#include <memory>

using namespace std;
using namespace sf;

Tank::Tank()
{
	init();
}

Tank::Tank(float size, float gunLen, sf::Color bodyColor)
	: bodyRadius(size), gunLength(gunLen), bodyColor(bodyColor)
{
	init();
}


Tank::~Tank()
{
}

void Tank::init()
{
	name = "Tank";
	type = TANK;

	body.setRadius(bodyRadius);
	body.setOrigin(bodyRadius, bodyRadius);
	body.setFillColor(Color(0, 0, 0, 0));
	body.setOutlineColor(bodyColor);
	body.setOutlineThickness(2);


	gun.setFillColor(bodyColor);
	gun.setSize(Vector2f(gunLength, caliber));
	gun.setOrigin(Vector2f(0, caliber / 2));

	collider = std::make_shared<CircleCollider>(*this, bodyRadius);
}

void Tank::update(float deltaTime)
{
	if (turnLeft) {
		rotateLeft(deltaTime);
	}
	if (turnRight) {
		rotateRight(deltaTime);
	}

	if (movingForward) {
		moveForward(deltaTime);
	}
	if (movingBackward) {
		moveBackward(deltaTime);
	}
}

void Tank::onCollision(const Entity & other)
{	
	if (other.getType() == EntityType::OBSTACLE) {
		//TODO: Calc sliding vector
		moveBy(static_cast<float>(-dx), static_cast<float>(-dy));		
	}
	else if (other.getType() == EntityType::TANK) {
		//TODO: Calc sliding vector
		moveBy(static_cast<float>(-dx), static_cast<float>(-dy));
	}
	else if (other.getType() == EntityType::BULLET) {
		hitsTaken++;
		if (guiListener != nullptr)
			guiListener->updateData();
	}
}

void Tank::setScore(int score)
{
	this->score = score; 
	if (guiListener != nullptr)
		guiListener->updateData();
}

void Tank::setColor(const sf::Color & color)
{
	bodyColor = color;
	body.setOutlineColor(color);
	gun.setOutlineColor(color);
	gun.setFillColor(color);
}

void Tank::addGuiLitener(std::shared_ptr<GuiElement> gui)
{
	guiListener = gui;
}

void Tank::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(body, states);
	target.draw(gun, states);
}


void Tank::moveBy(float x, float y)
{
	body.move(x, y);
	gun.move(x, y);
}

void Tank::setPosition(const sf::Vector2f & position)
{
	body.setPosition(position);
	gun.setPosition(position);
}

void Tank::setPosition(float x, float y)
{
	body.setPosition(x, y);
	gun.setPosition(x, y);
}

sf::Vector2f Tank::getPosition() const
{
	return body.getPosition();
}



void Tank::setAngle(float angle)
{
	this->angle = angle;
	body.setRotation(angle);
	gun.setRotation(angle);
}


void Tank::moveForward(float deltaTime)
{
	dx = cos(angle * M_PI / 180) * speed * deltaTime;
	dy = sin(angle * M_PI / 180) * speed * deltaTime;

	moveBy(static_cast<float>(dx), static_cast<float>(dy));
}
void Tank::moveBackward(float deltaTime)
{
	dx = cos(angle * M_PI / 180) * -speed * deltaTime;
	dy = sin(angle * M_PI / 180) * -speed * deltaTime;

	moveBy(static_cast<float>(dx), static_cast<float>(dy));
}
void Tank::rotateLeft(float deltaTime)
{
	float newAngle = angle - rotationSpeed * deltaTime;
	setAngle(newAngle);
	if (angle < 0)angle += 360.0f;

}
void Tank::rotateRight(float deltaTime)
{
	float newAngle = angle + rotationSpeed * deltaTime;
	setAngle(newAngle);
	if (angle >= 360)angle -= 360.0f;
	
}