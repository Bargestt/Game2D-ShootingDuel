#pragma once

class Tank;
class EntityManager;

class Action
{
protected:
	Tank & owner;

public:
	Action(Tank& owner) : owner(owner) {};
	~Action() {};

	virtual void execute(EntityManager& control) = 0;
};

class NoAction : public Action
{
public:
	NoAction(Tank & owner):Action(owner) {};
	~NoAction() {};

	void execute(EntityManager& control) override { };
};

class ShootAction : public Action
{
public:
	using Action::Action;
	~ShootAction() {};

	void execute(EntityManager& control) override;
};