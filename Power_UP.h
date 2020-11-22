#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
class Power_UP
{
public:
	float speed = 1.5;
	Clock timer;
	int temp = 0;
	Power_UP(Texture &texture,Vector2f Epos);
	~Power_UP();
	Vector2f getPos();
	FloatRect getGlobalBounds();
	void update();
	void render(RenderTarget &target);
private:
	Sprite PowerUP;
};

