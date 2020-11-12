#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
class Enemy
{
public:
	//Variables
	int hp;
	int hpmax;
	float movementspeed;
	int d = 0;
	bool isDead = false;
	bool direction;
	int count = 0;
	bool canshoot = false;
		//Functions
	Enemy(Texture& texture, float movementspeed, bool direction, float x, float y);
	~Enemy();
	void initEnemy(Texture& texture, float movementspeed, bool direction, float x, float y);
	void animation();
	int deadanimation();
	void setRectY(int row);
	void setRectX(int collum);
	void move();
	void update();
	IntRect getrect();
	FloatRect getGlobalBounds() const;
	const Vector2f getPos() const;
	void render(RenderTarget* target);
private:
	//Variables
	Sprite sprite;
	Clock clock;
	Clock clock2;
	Clock clock3;
	Clock cooldown;
	IntRect rect;
	//Functions
};

