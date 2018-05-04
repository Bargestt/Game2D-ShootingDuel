#pragma once
#include<memory>
#include<SFML\Graphics.hpp>

#include "GameContext.h"
class Renderer
{
private:	
	std::shared_ptr<sf::RenderWindow> pWindow;

	std::vector<const sf::Drawable*> drawables;
public:
	Renderer(const GameContext& context);
	~Renderer();
	void finishRender();

	void drawShape(const sf::Shape& shape);
	void drawSprite(const sf::Sprite& sprite);

	void draw(const sf::Drawable& drawable);
};
