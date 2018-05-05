#include "stdafx.h"
#include "Renderer.h"

using namespace std;
using namespace sf;

Renderer::Renderer(const GameContext& context)
	: pWindow(context.window)
{	
}

Renderer::~Renderer()
{
}


void Renderer::finishRender()
{
	pWindow->clear();
	
	for (auto shape : drawables) 
	{
		pWindow->draw(*shape);		
	}
	drawables.clear();
	
	pWindow->display();
}



void Renderer::draw(const sf::Drawable& drawable)
{
	drawables.push_back(&drawable);
}

bool Renderer::isInside(sf::Vector2f point, float leeway)
{
	auto rect = sf::FloatRect(
		0 - leeway,
		0 - leeway, 
		pWindow->getSize().x + leeway * 2, 
		pWindow->getSize().y + leeway * 2);

	return 	rect.contains(point);
}

