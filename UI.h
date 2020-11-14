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
private:
	Font future;
	Text score;
	RectangleShape hpback;
	RectangleShape hp;
};

