#include "..\stdafx.h"
#include "GuiManager.h"


GuiManager::GuiManager()
{
	if ( !baseFont.loadFromFile("arial.ttf") ) {
		std::cout << "Couldn't load base font \"arial.ttf\"";
	}
}


GuiManager::~GuiManager()
{
}

std::shared_ptr<GuiLabel> GuiManager::createLabel(
	std::string text, sf::Vector2f pos, int size, GuiLabel::Alignment align)
{
	auto ptr = std::make_shared<GuiLabel>(text, pos, baseFont, size, align);

	guis.push_back(ptr);

	return ptr;
}

std::shared_ptr<Score> GuiManager::createScore(Tank & target, sf::Vector2f pos, int size, GuiLabel::Alignment align)
{
	auto ptr = std::make_shared<Score>(target, pos, baseFont, size, align);
	target.addGuiLitener(ptr);

	guis.push_back(ptr);

	return ptr;
}

void GuiManager::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto gui : guis) {
		target.draw(*gui, states);
	}
}
