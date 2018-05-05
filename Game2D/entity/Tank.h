#pragma once
#include"..\gui\GuiElement.h"
#include "..\actions\Actions.h"

#include"Entity.h"

class Tank : public Entity
{
private:
	//VISUALS
	sf::CircleShape body;
	sf::RectangleShape gun;

	sf::Color bodyColor = sf::Color(0, 255, 0);
	float bodyRadius = 30;
	float caliber = 14;
	float gunLength = 50;
	float angle = 0;

	//PARAMETERS
	float speed = 300;
	float rotationSpeed = 150;	
	float bulletSpeed = 1000;

	int hitsTaken = 0;
	int score = 0;

	std::shared_ptr<GuiElement> guiListener;

	std::shared_ptr<Action> action;


	double dx =0, dy=0; //last movement increment
public:	
	Tank(EntityManager& control, float size, float gunLen, sf::Color bodyColor);
	~Tank();
private:
	void init();
public:
	virtual void update(float deltaTime);
	//basic obstacle collision
	virtual void onCollision(const Entity& other);

	//MOVEMENT
	void moveBy(float x, float y);
	virtual void setPosition(const sf::Vector2f& position);
	virtual void setPosition(float x, float y);
	virtual sf::Vector2f getPosition() const;

	void setTurnLeft(bool val) { turnLeft = val; }
	void setTurnRight(bool val) { turnRight = val; }
	void setMoveForward(bool val) { movingForward = val; }
	void setMoveBackward(bool val) { movingBackward = val; }

	//PARAM GETTERS/SETTERS
	float getBodyRadius()const { return bodyRadius; }
	float getGunLength()const { return gunLength; }
	float getAngle() const { return angle; }
	float getRotationSpeed() const { return rotationSpeed; }
	float getCaliber() { return caliber; }
	float getBulletSpeed() { return bulletSpeed; }

	std::shared_ptr<Action> getAction() { return action; }
	void setAction(std::shared_ptr<Action> newAction) { action = newAction; }
	void doAction();

	void setColor(const sf::Color& color);


	// GAMEPLAY INFO
	int getHitsTaken() const { return hitsTaken; }
	int getScore() const { return score; }
	void setScore(int score);
	void addGuiLitener(std::shared_ptr<GuiElement> gui);
	void setAngle(float angle);
protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


	//ACTIONS
	bool turnLeft = false;
	bool turnRight = false;

	bool movingForward = false;
	bool movingBackward = false;

	//MOVEMENT STEP CALCULATION & EXECUTION
	void moveForward(float deltaTime);
	void moveBackward(float deltaTime);
	void rotateLeft(float deltaTime);
	void rotateRight(float deltaTime);

};

