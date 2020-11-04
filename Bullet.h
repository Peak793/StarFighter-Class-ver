#pragma once
#include"SFML/Graphics.hpp"
#include "iostream"
using namespace sf;
class Bullet
{
public:
	//Variables
	
	//Functions
	Bullet();
	~Bullet();
	void initBullet(Texture texture);
	void update();
	void render();
private:
	//Variables
	Sprite sprite;
	Texture texture;
	//Functions
};

