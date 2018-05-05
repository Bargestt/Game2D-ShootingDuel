#pragma once

#include <SFML\Graphics.hpp>
#include "GuiElement.h"

class GuiLabel : public GuiElement
{
protected:
	sf::Text label;
public:
	enum Alignment{ LEFT, RIGHT };

	GuiLabel(const std::string text, const sf::Vector2f& pos,
			 const sf::Font& font, int size, Alignment align);
	~GuiLabel();
	
	sf::Text& getData() { return label; }
	void updateData() {}

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

