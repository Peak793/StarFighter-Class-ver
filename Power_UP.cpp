#include "Power_UP.h"

Power_UP::Power_UP(Texture &texture,Vector2f Epos)
{
	PowerUP.setTexture(texture);
	PowerUP.setPosition(Epos);
}

Power_UP::~Power_UP()
{
}

Vector2f Power_UP::getPos()
{
	return Vector2f(PowerUP.getPosition());
}

FloatRect Power_UP::getGlobalBounds()
{
	return FloatRect(PowerUP.getGlobalBounds());
}

void Power_UP::update()
{
	PowerUP.move (0,speed);
}

void Power_UP::render(RenderTarget &target)
{
	target.draw(PowerUP);
}
