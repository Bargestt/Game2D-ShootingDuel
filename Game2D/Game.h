#pragma once
#include <chrono>

#include"GameContext.h"
#include"Renderer.h"

#include"entity\Border.h"
#include"entity\Obstacle.h"
#include"entity\Player.h"
#include"entity\Enemy.h"
#include"entity\EntityManager.h"
#include"gui\GuiManager.h"


class Game
{
private:
	GameContext context;
	std::shared_ptr<sf::RenderWindow> pWindow;

	std::shared_ptr<Renderer>  renderer;
	EntityManager manager;
	GuiManager guiManager;

	float fixedUpdateTime = 1.0f / 60;
	bool running;

	//game objects, i'm too lazy to create separate class for them
	std::shared_ptr<Player> player;
	std::shared_ptr<Enemy> enemy;
	std::shared_ptr<Score> playerScore;
	std::shared_ptr<Score> enemyScore;

public:
	Game();
	~Game();

	void start();
	void stop();

private:
	void loop();

	void events();
	void keyPress(const sf::Event::KeyEvent& e);
	void keyRelease(const sf::Event::KeyEvent& e);
	void initRes();
};

