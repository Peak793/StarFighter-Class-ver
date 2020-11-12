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
	delete this->bg;
}

void Game::InitVariable()
{
	srand(time(NULL));
	this->window = nullptr;
	this->player = nullptr;
	this->bullet.loadFromFile("img/Bullet.png");
	this->Btimer = 0;
	this->canShoot = true;
	this->Fcooldown = 20;
	this->Scooldown = 150;
	this->EStimer = this->Scooldown;
	this->bg = new BackGround();
	enemy.loadFromFile("img/Enemy.png");

	this->EBcooldown = 1;
	ebullet.loadFromFile("img/Ebullet.png");

	hpup.loadFromFile("img/playerLife2_red.png");

	enemies.reserve(10);
	bullets.reserve(50);
	ebullets.reserve(10);
	itemHP.reserve(3);
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
	this->player->setpos(window->getSize().x / 2.f, window->getSize().y - 50.f);
	this->player->hp = this->player->hpmax;
}

void Game::InitEnemy()
{
	if (this->EStimer < Scooldown)
		this->EStimer +=1;
	if ((this->EStimer == this->Scooldown && enemycount <enemymax) || (enemycount < 3))
	{
		bool temp = rand()%2;
		enemies.emplace_back(enemy,(float)((1.0 + rand() % 2) / 2),temp, (float)(50.f + rand() % 468),(float)(64 + (rand() % 5 * 64)));
		this->EStimer = 0;
	
		enemycount++;
	}
}

void Game::InitEBullet()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].canshoot == true)
		{
			ebullets.emplace_back(&ebullet,enemies[i].getPos().x,enemies[i].getPos().y + 32,5);
			enemies[i].canshoot = false;
		}
	}
	for (int i = 0; i < ebullets.size(); i++)
	{
		ebullets[i].move();
	}
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

void Game::bulletSpawn()
{
	if (this->Btimer < this->Fcooldown)
		this->Btimer++;
	else
		this->canShoot = true;

	if (Keyboard::isKeyPressed(Keyboard::Space) && canShoot == true)
	{
		this->canShoot = false;
		bullets.emplace_back(bullet,player->getpos(),0,-1,10.f);
		Btimer = 0;
	}
}

void Game::renderBullet()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].render(*this->window);
	}
}

void Game::renderEbullet()
{
	for (int i = 0; i < ebullets.size(); i++)
	{
		ebullets[i].render(this->window);
	}
}

void Game::Bmove()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].update();
	}
	int count = bullets.size();
	for (int i = 0; i < count; i++)
	{
		if (bullets[i].getpos().y <= -27)
		{
			bullets.erase(bullets.begin() + i);
			break;
		}
	}
}

void Game::enemyUpdate()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		if(enemies[i].isDead == false)
			enemies[i].update();
	}
}

void Game::enemyAnimation()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].isDead == false)
		{
			enemies[i].animation();
		}
		else
		{
			if(enemies[i].deadanimation())
			{
				enemies.erase(enemies.begin()+ i);
				enemycount--;
				break;
			}
		}
	}
}

void Game::collision()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		for (int k = 0; k < enemies.size(); k++)
		{
			if (bullets[i].getGlobalBounds().intersects(enemies[k].getGlobalBounds())&&enemies[k].isDead == false)
			{
				bullets.erase(bullets.begin()+i);
				enemies[k].setRectY(64);
				enemies[k].hp--;
				if (enemies[k].hp == 0 && enemies[k].getPos().y<900)
				{
					random = rand() % 1001;
					dropping(enemies[k].getPos());
					enemies[k].isDead = true;
				}
				break;
			}
		}
	}
	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].getGlobalBounds().intersects(this->player->getGlobalBounds())&& player->isdamaged == false && enemies[i].isDead == false)
		{
			enemies[i].isDead = true;
			player->hp--;
			player->isdamaged = true;
		}
	}

	for (int i = 0; i < ebullets.size(); i++)
	{
		if(ebullets[i].getGlobalBounds().intersects(player->getGlobalBounds())&& player->isdamaged == false)
		{
			player->hp--;
			player->isdamaged = true;
			std::cout << player->isdamaged << std::endl;
			ebullets.erase(ebullets.begin() + i);
		}
	}
}

void Game::dropping(Vector2f Epos)
{
	if (random >= 1 && random <= 200)
	{
		std::cout << "Drop" << std::endl;
		itemHP.emplace_back(hpup,Epos);
		random = 0;
	}
}

void Game::Dupdate()
{
	for (int i = 0; i < itemHP.size(); i++)
	{
		if (itemHP[i].temp == 0)
		{
			itemHP[i].timer.restart();
			itemHP[i].temp++;
		}
		else
		{
			if (itemHP[i].timer.getElapsedTime().asSeconds() < 3)
			{
				if(itemHP[i].getPos().y<850)
					itemHP[i].update();
			}
			else
			{
				itemHP.erase(itemHP.begin()+i);
				break;
			}
		}

	}

	for (int i=0;i<itemHP.size();i++)
	{
		if (player->getGlobalBounds().intersects(itemHP[i].getGlobalBounds()))
		{
			itemHP.erase(itemHP.begin()+i);
		}
	}
}

void Game::RenderD()
{
	for (int i = 0; i < itemHP.size(); i++)
	{
		itemHP[i].render(*this->window); 
	}
}


void Game::renderEnemy()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i].render(window);
	}
}

void Game::update()
{
	this->InitEnemy();
	this->InitEBullet();
	this->player->update();
	this->movePlayer();
	this->bulletSpawn();
	this->Bmove();
	this->bg->update();
	this->collision();
	this->enemyUpdate();
	this->enemyAnimation();
	this->Dupdate();
}

void Game::render()
{
	this->window->clear();
	
	//Draw stuffs
	this->bg->render(*this->window);
	this->renderEnemy();
	this->player->render(*this->window);
	this->renderEbullet();
	this->renderBullet();
	this->RenderD();
	this->window->display();
}
