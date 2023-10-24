#pragma once
#define LMAX 10
#define SMAX 6
#define BMAX 120

enum class BOSSPATTERN
{
	IDLE,
	LLASER,
	RLASER,
	SWORD,
	BALL,
	DIE
};

class Berial
{
	struct Ball;
	struct Sword;

public:
	BOSSPATTERN	boss_Pattern;

	bool	isDamaged = false;
	float	damageTime = 0.0f;
	float	boss_HP = 400.0f;

	//IDLE
	ObImage* idle_Head;
	ObImage* idle_Hand1;
	ObImage* idle_Hand2;
	ObImage* idle_shot;
	ObImage* attack_shot;

	ObRect*  berial_Col;

	//LASER
	ObImage* laser_Hand1;
	ObImage* laser_Hand2;
	ObImage* laser_Head1;
	ObImage* laser_Head2;
	ObImage* laser_Body1[LMAX];
	ObImage* laser_Body2[LMAX];

	ObRect* laser_Col;
	ObRect* laser_Col2;

	int		sword_Num = 6;
	float	sword_Timer = 0.0f;
	float	sword_Interval = 0.3f;
	int		sword_index = 0;

	int		shoot_Num = 6;
	float	shoot_Timer = 0.0f;
	float	shoot_Interval = 0.3f;
	int		shoot_index = 0;

	//SWORD
	Sword*	swords[SMAX];
	Vector2	p_sword_Dir;

	//BALL
	ObImage* ball_Head;
	ObImage* ball_HeadShot;
	ObImage* ball_Circle;
	ObImage* ball_Fx;
	ObImage* ball_Particle;

	Ball*	 balls[BMAX];

	int		 ball_Num = 30;
	float	 ball_Timer = 0.0f;
	float	 ball_Interval = 0.3f;
	int		 ball_index = 0;

	//DIE	 
	float	 dh_scalar = 200.0f;
	float	 dm_scalar = 200.0f;
	ObImage* die_Head;
	ObImage* die_Mouth;
	ObImage* die_Effect[50];

	ObRect* die_Head_Col;
	ObRect* die_Mouth_Col;

	Player* player;

	ObImage* boss_LifeBack;
	ObImage* boss_LifeBase;
	ObImage* boss_Icon;
	ObImage* boss_Life;
	
	//Shoot
	float		scalar; //½î´Â Èû
	Vector2		fireDir; //½î´Â ¹æÇâ

	Vector2		sword_dir;
	Vector2		pl_lastPos;

	Berial();
	~Berial();

	void Update();
	void Render();

	void SetDamage()
	{
		isDamaged = true;
		damageTime = 0.2f;
	}

	void AllInvisible()
	{
		idle_Head->visible = false;
		idle_Hand1->visible = false;
		idle_Hand2->visible = false;
		//idle_shot->visible = false;
		//attack_shot->visible = false;

		berial_Col->visible = false;

		laser_Hand1->visible = false;
		laser_Hand2->visible = false;
		laser_Head1->visible = false;
		laser_Head2->visible = false;

		for (int i = 0; i < LMAX; i++)
		{
			laser_Body1[i]->visible = false;
			laser_Body2[i]->visible = false;
		}

		laser_Col->visible = false;
		laser_Col2->visible = false;

		for (int i = 0; i < SMAX; i++)
		{
			swords[i]->sword_Charge->visible = false;
			swords[i]->sword_Default->visible = false;
			swords[i]->sword_Hit->visible = false;
			swords[i]->sword_Shoot->visible = false;
			swords[i]->sword_Col->visible = false;
		}

		for (int i = 0; i < BMAX; i++)
		{
			balls[i]->ball[0]->visible = false;
			balls[i]->ball[1]->visible = false;
			balls[i]->ball[2]->visible = false;
			balls[i]->ball[3]->visible = false;

			balls[i]->ball_Col[0]->visible = false;
			balls[i]->ball_Col[1]->visible = false;
			balls[i]->ball_Col[2]->visible = false;
			balls[i]->ball_Col[3]->visible = false;
		}

		ball_Head->visible = false;
		ball_HeadShot->visible = false;
		ball_Circle->visible = false;
		ball_Fx->visible = false;
		ball_Particle->visible = false;

		for (int i = 0; i < 50; i++)
		{
			die_Effect[i]->visible = false;
		}

		
	}

	void Reset();

private:
	struct Ball
	{
		ObImage*	 ball[4];
		ObCircle*	 ball_Col[4];
		Vector2		 fireDir[4];
	};

	struct Sword
	{
		ObImage*	sword_Charge;
		ObImage*	sword_Default;
		ObImage*	sword_Hit;
		ObImage*	sword_Shoot;
		ObRect*		sword_Col;
	};
};

