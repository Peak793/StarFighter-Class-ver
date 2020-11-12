#pragma once
#include "Player.h"
using namespace sf;
class BackGround
{
public:
	BackGround();
	~BackGround();
	void initBackGround();
	void update();
	void render(RenderTarget &target);

private:
	Sprite sprite;
	Texture texture;
};

