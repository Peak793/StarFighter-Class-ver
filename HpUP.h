#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
class HpUP
{
public:
	//Variables
	float speed = 1.5;
	Clock timer;
	int temp=0;
	//Functions
	HpUP(Texture& texture, Vector2f EPos);
	~HpUP();
	void update();
	void render(RenderTarget &target);
	FloatRect getGlobalBounds();
	Vector2f getPos();
private:
	//Variables
	Sprite hpUp;


	//Functions
};

