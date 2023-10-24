#pragma once
class Dungeon
{
private:


public:
	ObImage*	boss;
	ObImage*	torch[4];
	ObImage*	door1;
	ObImage*	door2;

	ObRect*		bossFloor[8];

	Dungeon();
	~Dungeon();

	void Update();
	void Render();
};

