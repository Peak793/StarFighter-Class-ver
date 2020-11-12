#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
class Ebullet
{
public:
	//Variables
	float speed=0;


	//Functions
	Ebullet(Texture *texture,float posX, float posY, float speed);
	~Ebullet();
	int move();
	FloatRect getGlobalBounds();
	void update();
	void render(RenderTarget *target);

private:
	CircleShape ebullet;
	
};

