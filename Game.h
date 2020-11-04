#include "Player.h"
using namespace sf;
class Game
{
public:
	//Variables
	Texture bullet;

	//Functions
	Game();
	~Game();
	void InitVariable();
	void InitWindow();
	void InitPlayer();
	void running();
	void pollEvent();
	void movePlayer();
	void update();
	void render();
private:
	//Variable
	RenderWindow *window;
	Event ev;
	Player *player;
	//Functions


};