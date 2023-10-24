#pragma once
#define FMAX 41
#define F1MAX 8
#define F2MAX 8
#define F3MAX 8

enum class MAINSCENE
{
	GAMESTART,
	MAIN,
	BOSS
};

class Main : public Scene
{
private:
	//����
	MAINSCENE	game_Scene;

	//���ӽ���
	Game_Start*	start;

	//����
	ObImage*	sky;
	ObImage*	layer;
	ObImage*	tree;
	ObImage*	floor;

	ObRect*		floorCol[FMAX];
	ObRect*		floor1[F1MAX];
	ObRect*		floor2[F2MAX];
	ObRect*		floor3[F3MAX];
	ObRect*		block[4];

	//���� ����
	ObImage*	entrance;
	ObRect*		entrance_Col;

	//����
	Dungeon*	bossMap;
	Berial*		berial;

	//�÷��̾�
	Player*		pl;
	Vector2		sword_dir;
	Vector2		pl_lastPos;

	float		scalar1 = 0.0f;
	float		scalar2 = 0.0f;

	float		pl_lastPos1 = 0.0f;
	float		pl_lastPos2 = 0.0f;

	bool		isChecking = false;

public:

	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;
};
