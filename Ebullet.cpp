#include "Ebullet.h"

Ebullet::Ebullet(Texture *texture,float posX, float posY,float speed)
{
	ebullet.setRadius(10);
	ebullet.setTexture(texture);
	ebullet.setPosition(posX,posY);
	this->speed = speed;
}

Ebullet::~Ebullet()
{

}

int Ebullet::move()
{
	this->ebullet.move(0,speed);
	return 0;
}

void Ebullet::update()
{

}

void Ebullet::render(RenderTarget *target)
{
	target->draw(ebullet);
}
