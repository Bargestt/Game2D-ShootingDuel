#pragma once

#include<SFML\Graphics.hpp>
#include<memory>

class GameContext
{
private:
	bool _isGood;
public:
	GameContext(int width, int height);
	~GameContext();

	bool isGood() const { return _isGood; }
	bool init();

	std::shared_ptr<sf::RenderWindow>  window;	

	int width;
	int height;
	std::string title;
};

