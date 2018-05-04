#pragma once
#include<vector>
#include<memory>

#include <SFML\Graphics.hpp>

#include "GuiElement.h"
#include"GuiLabel.h"
#include"Score.h"

class GuiManager : public sf::Drawable
{
	std::vector< std::shared_ptr<GuiElement> > guis;

	sf::Font baseFont;
public:
	GuiManager();
	~GuiManager();

	std::shared_ptr<GuiLabel> createLabel(
		std::string text, sf::Vector2f pos, int size, GuiLabel::Alignment align = GuiLabel::LEFT);
	std::shared_ptr<Score> createScore(
		Tank& target,
		sf::Vector2f pos, int size, GuiLabel::Alignment align = GuiLabel::LEFT);


protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

