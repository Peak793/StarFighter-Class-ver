#include "Bullet.h"

Bullet::Bullet(Texture &texture,Vector2f playerPos,int dir_X,int dir_Y, float speed)
{
	this->sprite.setTexture(texture);
	this->sprite.setScale(1,0.5);
	this->sprite.setOrigin(this->sprite.getGlobalBounds().width/2,this->sprite.getGlobalBounds().height/2);
	this->sprite.setPosition(playerPos.x,playerPos.y-40);
	this->dir.x = dir_X;
	this->dir.y = dir_Y;
	this->movementspeed = speed;
}

Bullet::~Bullet()
{

}

const Vector2f Bullet::getpos() const
{
	return Vector2f(this->sprite.getPosition().x ,this->sprite.getPosition().y );
}

FloatRect Bullet::getGlobalBounds() const
{
	return FloatRect(this->sprite.getGlobalBounds());
}

void Bullet::update()
{
	this->sprite.move((float)this->dir.x*this->movementspeed,(float)this->dir.y*this->movementspeed);
}

void Bullet::render(RenderTarget &target)
{
	target.draw(this->sprite);
}
