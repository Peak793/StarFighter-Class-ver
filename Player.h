#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
using namespace sf;
class Player
{
public:
	//Variables
	float speed = 2.5;
	int hp;
	int hpmax = 5;
	bool isdamaged = false;
	bool isdead = false;

	//Functions
	Player();
	~Player();
	void initTexture();
	void initPlayer();
	void animation();
	void move(float dirX, float dirY);
	void setpos(float x, float y);
	const Vector2f getpos() const;
	void update();
	void render(RenderTarget& target);
	FloatRect getGlobalBounds() const;

private:
	//Varables
	Sprite sprite;
	Texture texture;
	IntRect rect;
	Vector2u count;
	Vector2u currentImage;
	Clock clock;
	Clock recovertime;
	int count;
	//Functions


};