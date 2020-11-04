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

	//Functions
	Player();
	~Player();
	void initTexture();
	void initPlayer();
	void animation();
	void move(float dirX, float dirY);
	void setpos(float x,float y);
	const Vector2f getpos() const;
	void update();
	void render(RenderTarget &target);

private:
	//Varables
	Sprite sprite;
	Texture texture;
	IntRect rect;
	Vector2u count;
	Vector2u currentImage;
	Clock clock;
	//Functions


};

