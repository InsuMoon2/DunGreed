#pragma once
#define	AMAX 4

enum class PLAYERSTATE
{
	IDLE,
	RUN,
	JUMP,
	DIE,
	DASH,
};

class Player
{
	//struct Trail;
private:

public:
	//����
	PLAYERSTATE	player_State;

	//Trail		trails;

	float		player_Hp;

	//�̹���
	ObImage*	player_Idle;
	ObImage*	player_Run;
	ObImage*	player_Jump;
	ObImage*	player_Die;
	ObImage*	player_Dust;
	ObImage*	sword_Effect;
	ObImage*	player_LifeBack;
	ObImage*	player_LifeBase;
	ObImage*	player_Level;
	ObImage*	player_Life;
	ObImage*	player_LifeWave;
	ObImage*	dash_Base[2];
	ObImage*	dash_Count[2];

	ObRect*		player_Col;
	ObRect*		player_Buttom;
	ObRect*		player_arm;
	ObCircle*	sword_Col;

	//�ܻ�
	ObImage*	shadowTrail[AMAX];
	int			shadowNum;
	float		shadowTimer;
	float		shadowInterval;
	int			index;

	Vector2		w_lastPos;
	Vector2		lastPos;
	Vector2		moveDir;
	Vector2		moving;

	float		time;
	float		scalar;
	float		gravity;
	float		player_HP = 100.0f;
	float		rotation;

	bool		attack = true;

	//�뽬
	int			dashCount;
	bool		dash;

	//����
	bool		jump;

	//����
	Weapon*		player_Sword;

	Player();
	~Player();

	void Update();
	void Render();

	//struct Trail
	//{
	//	//�ܻ�
	//	ObImage*	shadowTrail[AMAX];
	//	int			shadowNum;
	//	float		shadowTimer;
	//	float		shadowInterval;
	//	int			index;
	//};
	
};

