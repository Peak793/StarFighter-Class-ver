#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 4

class Menu
{
public:
	Menu(float width,float height);
	~Menu();

	void		render(sf::RenderWindow& Window);
	void		MoveUp();
	void		MoveDown();

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
};
