#include "HpUP.h"

HpUP::HpUP(Texture &texture, Vector2f EPos)
{
	hpUp.setTexture(texture);
	hpUp.setPosition(EPos);
}

HpUP::~HpUP()
{
}

FloatRect HpUP::getGlobalBounds()
{
	return FloatRect(hpUp.getGlobalBounds());
}

Vector2f HpUP::getPos()
{
	return Vector2f(hpUp.getPosition());
}

void HpUP::update()
{
	hpUp.move(0,speed);
}

void HpUP::render(RenderTarget& target)
{
	target.draw(hpUp); 
}
