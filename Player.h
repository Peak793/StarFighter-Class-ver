#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include <iostream>
using namespace sf;
class Player
{
public:
	//Variables
	float speed = 2.5;
	int hp;
	int hpmax = 10;
	float damage = 1;
	bool isPowerUP = false;
	bool isdamaged = false;
	bool isdead = false;
	bool isgameOver = false;
	int Fcooldown = 25;
	
	Clock PowerUPcooldown;
	int yo=0;
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
	bool deadAnimation();
	FloatRect getGlobalBounds() const;

private:
	//Varables
	Sprite sprite;
	Texture texture;
	IntRect rect;
	Vector2u count;
	Vector2u currentImage;
	Clock clock;
	Clock clock2;
	Clock clock3;
	Clock recovertime;
	int c=0;
	//Functions


};