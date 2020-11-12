
#pragma once
#include"SFML/Graphics.hpp"
#include "iostream"
using namespace sf;
class Bullet
{
public:
	//Variables

	//Functions
	Bullet(Texture &texture, Vector2f playerPos, int dir_X, int dir_Y,float speed);
	~Bullet();
	const Vector2f getpos() const;
	FloatRect getGlobalBounds() const;
	void update();
	void render(RenderTarget& target);
private:
	//Variables
	Sprite sprite;
	Vector2f dir;
	float movementspeed;
	//Functions
};
