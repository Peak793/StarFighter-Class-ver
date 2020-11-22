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
	this->texture.loadFromFile("img/PlayerSprite3.png");
	this->count.x = 6;
	this->count.y = 3;
	this->rect.left = 0;
	this->rect.top = 0;
	this->rect.width = this->texture.getSize().x / this->count.x;
	this->rect.height = this->texture.getSize().y / this->count.y;
	//this->currentImage.x = 0;
	//this->currentImage.y = 1;
}

void Player::initPlayer()
{
	this->initTexture();
	this->sprite.setTexture(this->texture);
	this->sprite.setOrigin(32, 32);
	this->sprite.setTextureRect(this->rect);
	this->hp = this->hpmax;
}

void Player::animation()
{
	if (isdead == false)
	{
		if (isdamaged == false)
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
		else if (isdamaged == true)
		{
			if (c == 5)
			{
				c = 0;
				currentImage.y = 0;
				this->rect.top = this->currentImage.y * rect.height;
				isdamaged = false;
			}
			if (this->clock.getElapsedTime().asMilliseconds() >= 100)
			{
				this->currentImage.y = 1;
				this->rect.top = this->currentImage.y * rect.height;
				this->currentImage.x += 1;
				this->rect.left = this->currentImage.x * rect.width;
				this->sprite.setTextureRect(this->rect);
				this->clock.restart();
			}
			if (this->currentImage.x == 3)
			{
				this->currentImage.x = 0;
				c++;
			}
		}
	}
	else if (isdead == true)
	{
		bool check = this->deadAnimation();
		if (check == true)
		{
			isgameOver = true;
		}
	}
}
void Player::move(float dirX, float dirY)
{
	this->sprite.move(dirX * speed, dirY * speed);
}

void Player::setpos(float x, float y)
{
	this->sprite.setPosition(x, y);
}

const Vector2f Player::getpos() const
{
	return Vector2f(this->sprite.getPosition().x, sprite.getPosition().y);
}

void Player::update()
{
	this->animation();
	if (isPowerUP == true)
	{
		if (PowerUPcooldown.getElapsedTime().asSeconds() < 5)
		{
			damage = 1.5;
			Fcooldown = 10;
			speed = 4;
		}
		else
		{
			isPowerUP = false;
			damage = 1;
			Fcooldown = 25;
			speed = 3;
			PowerUPcooldown.restart();
		}
	}
}

void Player::render(RenderTarget& target)
{
	target.draw(this->sprite);
}

bool Player::deadAnimation()
{
	if (clock3.getElapsedTime().asMilliseconds() >= 100)
	{
		if (c == 0)
		{
			currentImage.y = 2;
			currentImage.x = 0;
			rect.top = currentImage.y * rect.height;
			rect.left = currentImage.x * rect.width;
			sprite.setTextureRect(rect);
			c++;
		}
		else if (currentImage.x <= 5)
		{
			currentImage.x++;
			rect.left = currentImage.x * rect.width;
			sprite.setTextureRect(rect);
		}
		else
		{
			return true;
		}
		clock3.restart();
	}
	return false;
}

FloatRect Player::getGlobalBounds() const
{
	return FloatRect(sprite.getGlobalBounds());
}
