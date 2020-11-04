#include "Player.h"

Player::Player()
{
	this->initTexture();
	this->initPlayer();
}

Player::~Player()
{
}

void Player::initTexture()
{
	this->texture.loadFromFile("img/PlayerS.png");
	this->count.x = 4;
	this->count.y = 1;
	this->rect.left = 0;
	this->rect.top = 0;
	this->rect.width = this->texture.getSize().x/this->count.x;
	this->rect.height = this->texture.getSize().y/this->count.y;
	//this->currentImage.x = 0;
	//this->currentImage.y = 1;
}

void Player::initPlayer()
{
	this->initTexture();
	this->sprite.setTexture(this->texture);
	this->sprite.setOrigin(32,32);
	this->sprite.setTextureRect(this->rect);
}

void Player::animation()
{
	if (this->clock.getElapsedTime().asMilliseconds() >= 100)
	{
		this->currentImage.x += 1;
		this->rect.left = this->currentImage.x * rect.width;
		this->sprite.setTextureRect(this->rect);
		this->clock.restart();
	}
	if (this->currentImage.x == 3)
	{
		this->currentImage.x = 0;
	}
}
void Player::move(float dirX,float dirY)
{
		this->sprite.move(dirX * speed, dirY * speed);
}

void Player::setpos(float x, float y)
{
	this->sprite.setPosition(x,y);
}

const Vector2f Player::getpos() const
{
	return Vector2f(this->sprite.getPosition().x,sprite.getPosition().y);
}

void Player::update()
{
	this->animation();
}

void Player::render(RenderTarget &target)
{
	target.draw(this->sprite);
}
