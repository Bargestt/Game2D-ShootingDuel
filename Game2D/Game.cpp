#include "stdafx.h"
#include "Game.h"
#include <iostream>

using namespace std;
using namespace sf;

Game::Game() : running(false),
	context(1024, 768)
{
	
}

Game::~Game()
{
}

void Game::start()
{
	context.init();	
	if (context.isGood()) 
	{
		running = true;
		initRes();
		loop();
	}
	stop();
}

void Game::stop()
{	
	pWindow->close();
}

void Game::loop()
{ 
	using clock = chrono::high_resolution_clock;

	auto prevTime = clock::now();
	float delta;
	float lag = 0;

	while (running)
	{
		auto time = clock::now() - prevTime;
		prevTime = clock::now();

		delta = chrono::duration<float>(time).count();
		lag += delta;

		events();		
		
		if (lag > fixedUpdateTime) {
			manager.fixedUpdate(lag);
			lag = 0;
		}
		
		manager.update(delta);

		renderer->draw(manager);			


		renderer->draw(guiManager);
		renderer->finishRender();
	}
}

void Game::events()
{
	sf::Event event;
	while (pWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			running = false;
		else if (event.type == sf::Event::KeyPressed)
			keyPress(event.key);
		else if (event.type == sf::Event::KeyReleased)
			keyRelease(event.key);
	}
}
void Game::keyRelease(const sf::Event::KeyEvent& e) {
	if (e.code == Keyboard::A)
		player->setTurnLeft(false);
	if (e.code == Keyboard::D)
		player->setTurnRight(false);
	if (e.code == Keyboard::W) 
		player->setMoveForward(false);
	if (e.code == Keyboard::S) 
		player->setMoveBackward(false);
	
}
void Game::keyPress(const sf::Event::KeyEvent& e) {
	if (e.code == Keyboard::W) {
		player->setMoveForward(true);
	}
	else if (e.code == Keyboard::A) {
		player->setTurnLeft(true);
	}
	else if (e.code == Keyboard::S) {
		player->setMoveBackward(true);
	}
	else if (e.code == Keyboard::D) {
		player->setTurnRight(true);
	}
	else if (e.code == Keyboard::Space) {
		player->doAction();
	}
}

void Game::initRes()
{
	pWindow = context.window;
	renderer = make_shared<Renderer>(context);

	

	enemy = make_shared<Enemy>(30.0f, 50.0f);
	enemy->setPosition(300, 300);

	manager.addEntity(enemy);

	player = make_shared<Player>(30.0f, 50.0f, Color::Green);
	player->setPosition(100, 100); 
	manager.addEntity(player);


	playerScore = guiManager.createScore(*player, { 30, 0 }, 30);
	enemyScore = guiManager.createScore(*enemy,
		{ static_cast<float>(pWindow->getSize().x - 130), 0 }, 30, GuiLabel::RIGHT);


	manager.addEntity(make_shared<Obstacle>(200.0f, 100.0f, 200.0f, 100.0f));
}
