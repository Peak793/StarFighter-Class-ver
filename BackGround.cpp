#include "BackGround.h"

BackGround::BackGround()
{
	this->initBackGround();
}

BackGround::~BackGround()
{

}

void BackGround::initBackGround()
{
	this->texture.loadFromFile("img/long.png");
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(0.f,-13527.f);
}


void BackGround::update()
{
	this->sprite.move(0.f,1.f);
	if (this->sprite.getPosition().y == 0)
		this->sprite.setPosition(0.f,-13527.f);
}

void BackGround::render(RenderTarget &target)
{
	target.draw(this->sprite);
}
