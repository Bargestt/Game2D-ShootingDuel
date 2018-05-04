#include "stdafx.h"
#include "GameContext.h"

using namespace std;
using namespace sf;

GameContext::GameContext(int width, int height)
	: width(width), height(height), title("Default"), _isGood(false)
{
	
}

GameContext::~GameContext()
{
	window->close();
}

bool GameContext::init()
{
	_isGood = false;

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	window = make_shared<RenderWindow>( VideoMode(width, height), 
										title.c_str(),
										sf::Style::Default,
										settings
									  );

	if (window == nullptr) return false;

	_isGood = true;
	return true;
}


