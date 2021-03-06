#include "UI.h"

UI::UI()
{
	future.loadFromFile("fonts/kenvector_future.ttf");
	iconTex.loadFromFile("img/playerLife2_red.png");
	icon.setTexture(iconTex);
	icon.setPosition(5,10);
	score.setFont(future);
	score.setCharacterSize(20);
	score.setString("SCORE : 0");
	score.setFillColor(Color::White);
	score.setPosition(400,10);
	hpback.setSize(Vector2f(100,20));
	hpback.setOutlineColor(Color::White);
	hpback.setFillColor(Color::Black);
	hpback.setOutlineThickness(5);
	hpback.setPosition(50,10);
	hp.setSize(Vector2f(100, 20));
	hp.setFillColor(Color(204,0,0));
	hp.setPosition(50, 10);
}

UI::~UI()
{

}

void UI::update(int score,int hp)
{
	this->score.setString("SCORE : " + std::to_string(score));
	this->hp.setSize(Vector2f(hp < 0 ? 0:hp *100 / 10, 20));
}

void UI::render(RenderTarget &target)
{
	target.draw(score);
	target.draw(hpback);
	target.draw(hp);
	target.draw(icon);
}

void UI::pause()
{

}
