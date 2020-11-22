#include "Bullet.h"
#include "Player.h"
#include "BackGround.h"
#include "Enemy.h"
#include "Ebullet.h"
#include "HpUP.h" 
#include "UI.h"
#include "Power_UP.h"
using namespace sf;
class Game
{
public:
	//Variables
	unsigned enemycount = 0;
	unsigned enemymax = 20;
	int progresstion = 0;
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
	void dropping(Vector2f Epos);
	void Dupdate();
	void RenderD();
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

	std::vector<Enemy>enemies;
	Texture enemy;
	int EStimer;
	int Scooldown;

	std::vector<Ebullet>ebullets;
	Texture ebullet;
	int EBcooldown;
	Clock EBtimer;

	std::vector<HpUP>itemHP;
	Texture hpup;

	std::vector<Power_UP>PUP;
	Texture PUPTEX;

	BackGround *bg;

	UI *ui;
	unsigned long long score = 0;
	//Functions


};