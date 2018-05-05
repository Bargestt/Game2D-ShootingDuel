#include "..\stdafx.h"
#include "Score.h"


Score::Score(const Tank& target,const sf::Vector2f pos, 
	const sf::Font& font, int size, Alignment align)
	: target(target), 
	GuiLabel(std::string(), pos, font, size, align)
{
	label.setString(target.getName() + ":" + std::to_string(target.getScore()));
}


Score::~Score()
{
}

void Score::updateData()
{
	label.setString(target.getName() + ":" + std::to_string(target.getScore()));
}
