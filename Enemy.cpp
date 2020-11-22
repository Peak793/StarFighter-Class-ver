#include "Enemy.h"

Enemy::Enemy(Texture& texture, float movementspeed,bool direction, float x, float y)
{
	sprite.setOrigin(32, 32);
	this->initEnemy(texture,movementspeed,direction,x,y);
}

Enemy::~Enemy()
{

}

void Enemy::initEnemy(Texture& texture,float movementspeed,bool direction,float x,float y)
{
	hpmax = 3;
	hp = hpmax;
	this->movementspeed = movementspeed;
	this->direction = direction;
	sprite.setPosition(x,y);
	sprite.setTexture(texture);
	rect.left = 0;
	rect.height = 0;
	rect.width = 64;
	rect.height = 64;
	sprite.setTextureRect(rect);
}

void Enemy::animation()
{
		if (clock.getElapsedTime().asMilliseconds() >= 100)
		{
			rect.top = 0;
			rect.left += 64;
			sprite.setTextureRect(rect);
			if (rect.left == 960)
				rect.left = 0;
			clock.restart();
		}

}

int Enemy::deadanimation()
{
	if (d == 0)
	{
		rect.top = 128;
		rect.left = 0;
		d++;
	}
	if (clock2.getElapsedTime().asMilliseconds() > 100)
	{
		rect.left += 64;
		sprite.setTextureRect(rect);
		if (rect.left == 448)
		{
			return 1;
		}
		clock2.restart();
	}
	return 0;
}

void Enemy::setRectY(int row)
{
	rect.top = row;
	this->sprite.setTextureRect(rect);
}

void Enemy::setRectX(int collum)
{
	rect.left = collum;
	sprite.setTextureRect(rect);
}

FloatRect Enemy::getGlobalBounds() const
{
	return FloatRect(this->sprite.getGlobalBounds());
}

const Vector2f Enemy::getPos() const
{
	return Vector2f(sprite.getPosition());
}

void Enemy::move()
{
	if (clock3.getElapsedTime().asSeconds() <=5)
	{
		if (direction == 0 && count < 2)
			sprite.move(-1 * movementspeed, 0);
		else
			sprite.move(1 * movementspeed, 0);

		if (sprite.getPosition().x >= 568)
		{
			direction = !direction;
		}
		else if (sprite.getPosition().x <= 32)
		{
			direction = !direction;
		}
	}
	else
	{
		canshoot = false;
		sprite.move(0,8);
		if (sprite.getPosition().y >= 932)
		{
			isDead = true;
		}
	}
}

IntRect Enemy::getrect()
{
	return IntRect(rect);
}

void Enemy::update()
{
	if (cooldown.getElapsedTime().asSeconds() > 2)
	{
		canshoot = true;
		cooldown.restart();
	}
	this->move();
}

void Enemy::render(RenderTarget *target)
{
	target->draw(sprite);
}
