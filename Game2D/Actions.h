#pragma once

class Tank;

class Action
{
protected:
	Tank & owner;

public:
	Action(Tank& owner) : owner(owner) {};
	~Action() {};

	virtual void execute() = 0;
};

class NoAction : public Action
{
public:
	NoAction(Tank & owner):Action(owner) {};
	~NoAction() {};

	void execute() override { };
};

class ShootAction : public Action
{
public:
	using Action::Action;
	~ShootAction() {};

	void execute() override;
};