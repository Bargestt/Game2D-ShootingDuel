#pragma once
#include <SFML\Graphics.hpp>

class GuiElement : public sf::Drawable
{
public:
	GuiElement() {};
	~GuiElement() {};

	virtual void updateData()=0;

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const =0;
};

