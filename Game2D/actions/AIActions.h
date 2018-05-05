#include <SFML\System\Vector2.hpp>
#include "..\entity\Enemy.h"


class AI_Action{
protected:
	Enemy & owner;
	float lifetime;
	bool completed = false;
public:
	AI_Action(Enemy& owner, float life = 2.0f) :owner(owner), lifetime(life) {}
	~AI_Action() {}

	virtual void execute(float deltaTime) final;

	virtual void action() = 0;

	void complete() { completed = true; onComplete(); }
	bool isCompleted()const { return completed; }
	virtual void onComplete(){}
};


class AI_Move : public AI_Action
{
	sf::Vector2f destination;

public:
	AI_Move(Enemy & owner, sf::Vector2f dest);
	~AI_Move() {};

	void action() override;
};

class AI_ShootAt : public AI_Action
{
	sf::Vector2f target;
public:
	AI_ShootAt(Enemy & owner, sf::Vector2f target);
	~AI_ShootAt() {};

	void action() override;
};


//============ Generic Actions ===================

class AI_MoveForward : public AI_Action
{
public:
	AI_MoveForward(Enemy & owner, float life = 2.0f) :AI_Action(owner, life) {}
	~AI_MoveForward() {};

	void action() override {
		owner.setMoveForward(true);
	}
	void onComplete() override { owner.setMoveForward(false); }
};
class AI_MoveBackward : public AI_Action
{
public:
	AI_MoveBackward(Enemy & owner, float life = 2.0f) :AI_Action(owner, life){}
	~AI_MoveBackward() {};

	void action() override {
		owner.setMoveBackward(true);
	}
	void onComplete() override { owner.setMoveBackward(false); }
};
class AI_TurnLeft : public AI_Action
{
public:
	AI_TurnLeft(Enemy & owner, float life = 2.0f) :AI_Action(owner, life) {}
	~AI_TurnLeft() {};

	void action() override {
		owner.setTurnLeft(true);
	}
	void onComplete() override { owner.setTurnLeft(false); }
};
class AI_TurnRight : public AI_Action
{
public:
	AI_TurnRight(Enemy & owner, float life = 2.0f) :AI_Action(owner,life) {}
	~AI_TurnRight() {};

	void action() override {
		owner.setTurnRight(true);
	}
	void onComplete() override { owner.setTurnRight(false); }
};
