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

