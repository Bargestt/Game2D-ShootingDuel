#pragma once
#include "GuiLabel.h"
#include "Tank.h"
class Score : public GuiLabel
{
	const Tank& target;
public:
	Score(const Tank& target, const sf::Vector2f pos, 
		const sf::Font& font, int size, Alignment align);
	~Score();

	void updateData();
};

