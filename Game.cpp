#include "Game.h"

Game::Game()
{
	this->InitVariable();
	this->InitWindow();
	this->InitPlayer();
}

Game::~Game()
{
	delete this->window;
	delete this->player;
}

void Game::InitVariable()
{
	this->window = nullptr;
	this->player = nullptr;
	this->bullet.loadFromFile("Bullet.png");
}

void Game::InitWindow()
{
	this->window = new RenderWindow(VideoMode(600, 900), "StarFighter Classy Ver.", Style::Titlebar | Style::Close);
	this->window->setFramerateLimit(120);
	this->window->setVerticalSyncEnabled(false);
}

void Game::InitPlayer()
{
	this->player = new Player();
	this->player->setpos(window->getSize().x/2,window->getSize().y-50);
}

void Game::running()
{
	while (this->window->isOpen())
	{
		this->pollEvent();
		this->update();
		this->render();
	}
}

void Game::pollEvent()
{
	while (this->window->pollEvent(ev))
	{
		if (ev.type == Event::Closed)
			this->window->close();
		if (ev.type == Event::KeyPressed && ev.key.code == Keyboard::Escape)
			this->window->close();
	}
}

void Game::movePlayer()
{
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		this->player->move(0, -1);
		if (this->player->getpos().y < 32)
			this->player->setpos(player->getpos().x, 32);
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		this->player->move(0, 1);
		if (this->player->getpos().y > 868)
			this->player->setpos(player->getpos().x, 868);
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		this->player->move(-1, 0);
		if (this->player->getpos().x < 32)
			this->player->setpos(32, player->getpos().y);
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		this->player->move(1, 0);
		if (this->player->getpos().x > 568)
			this->player->setpos(568, player->getpos().y);
	}
	
}

void Game::update()
{
	this->player->update();
	this->movePlayer();
}

void Game::render()
{
	this->window->clear();
	//Draw stuffs
	this->player->render(*this->window);
	this->window->display();
}
