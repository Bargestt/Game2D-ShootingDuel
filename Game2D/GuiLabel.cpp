#include "stdafx.h"
#include "GuiLabel.h"


GuiLabel::GuiLabel(const std::string text, const sf::Vector2f& pos,
				   const sf::Font& font, int size, Alignment align = LEFT) 
	:label(text, font, size)
{
	if (align == RIGHT)
		label.setOrigin(label.getLocalBounds().width, 0);

	label.setPosition(pos);
}


GuiLabel::~GuiLabel()
{
}

void GuiLabel::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(label, states);
}
