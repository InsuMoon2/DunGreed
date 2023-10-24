#pragma once
class Game_Start
{
public:
	//게임시작
	ObImage*	backCloud;
	ObImage*	frontCloud;
	ObImage*	bird;
	ObImage*	bird2;
	ObImage*	mainLogo;
	ObImage*	bgLayer;

	ObImage*	play_On;
	ObImage*	play_Off;
	ObRect*		play_Col;

	ObImage*	exit_On;
	ObImage*	exit_Off;
	ObRect*		exit_Col;

	ObImage*	copyRight;

	Game_Start();
	~Game_Start();

	void Update();
	void Render();
};

