#include "Bullet.h"
#include "Player.h"
#include "BackGround.h"
#include "Enemy.h"
#include "Ebullet.h"
using namespace sf;
class Game
{
public:
	//Variables
	unsigned enemycount = 0;
	unsigned enemymax = 8;
	//Functions
	Game();
	~Game();
	void InitVariable();
	void InitWindow();
	void InitPlayer();
	void InitEnemy();
	void InitEBullet();
	void running();
	void pollEvent();
	void movePlayer();
	void bulletSpawn();
	void renderBullet();
	void renderEbullet();
	void Bmove();
	void enemyUpdate();
	void enemyAnimation();
	void collision();
	void dropping();
	void renderEnemy();
	void update();
	void render();
private:
	//Variable
	RenderWindow* window;
	Event ev;
	Player* player;
	int random =0;
	
	std::vector<Bullet>bullets;
	Texture bullet;
	bool canShoot;
	int Btimer;
	int cooldown;

	std::vector<Enemy>enemies;
	Texture enemy;
	int EStimer;
	int Scooldown;

	std::vector<Ebullet>ebullets;
	Texture ebullet;
	int EBcooldown;
	Clock EBtimer;

	BackGround *bg;
	//Functions


};