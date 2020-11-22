#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
class UI
{
public:
	UI();
	~UI();
	void update(int score, int hp);
	void render(RenderTarget& target);
	void pause();
private:
	Font future;
	Text score;
	Texture iconTex;
	Sprite icon;
	RectangleShape hpback;
	RectangleShape hp;
};

