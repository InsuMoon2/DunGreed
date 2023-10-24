#include "stdafx.h"

Game_Start::Game_Start()
{
	backCloud = new ObImage(L"BackCloud.png");
	backCloud->scale = Vector2(620.0f * 4.0f, 180.0f * 5.0f);
	backCloud->space = SPACE::SCREEN;

	frontCloud = new ObImage(L"FrontCloud.png");
	frontCloud->scale = Vector2(575.0f * 4.0f, 180.0f * 5.0f);
	frontCloud->space = SPACE::SCREEN;

	bird = new ObImage(L"bird.png");
	bird->scale = Vector2(96.0f / 8.0f, 8.0f) * 5.0f;
	bird->maxFrame.x = 8.0f;
	bird->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	bird->SetWorldPos(Vector2(-200.0f, -100.0f));
	bird->space = SPACE::SCREEN;

	bird2 = new ObImage(L"bird.png");
	bird2->scale = Vector2(96.0f / 8.0f, 8.0f) * 5.0f;
	bird2->maxFrame.x = 8.0f;
	bird2->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	bird2->SetWorldPos(Vector2(700.0f, -350.0f));
	bird2->space = SPACE::SCREEN;

	mainLogo = new ObImage(L"MainLogo.png");
	mainLogo->scale = Vector2(156.0f, 75.0f) * 4.5f;
	mainLogo->SetWorldPosY(100.0f);

	bgLayer = new ObImage(L"BGLayer_0.png");
	bgLayer->scale = Vector2(320.0f * 5.0f, 180.0f * 5.0f);
	bgLayer->space = SPACE::SCREEN;

	play_Off = new ObImage(L"PlayOff_Kor.png");
	play_Off->scale = Vector2(36.0f, 12.0f) * 5.0f;
	play_Off->SetWorldPosY(-180.0f);
	play_Off->space = SPACE::SCREEN;

	play_On = new ObImage(L"PlayOn_Kor.png");
	play_On->scale = Vector2(36.0f, 12.0f) * 5.0f;
	play_On->SetWorldPosY(-180.0f);
	play_On->visible = false;

	play_Col = new ObRect();
	play_Col->scale = Vector2(36.0f, 12.0f) * 5.0f;
	play_Col->SetParentRT(*play_Off);
	play_Col->isFilled = false;
	play_Col->visible = false;

	exit_Off = new ObImage(L"ExitOff_Kor.png");
	exit_Off->scale = Vector2(21.0f, 12.0f) * 5.0f;
	exit_Off->SetWorldPosY(-275.0f);

	exit_On = new ObImage(L"ExitOn_Kor.png");
	exit_On->scale = Vector2(21.0f, 12.0f) * 5.0f;
	exit_On->SetWorldPosY(-275.0f);
	exit_On->visible = false;

	exit_Col = new ObRect();
	exit_Col->scale = Vector2(36.0f * 3.0f, 12.0f * 5.0f);
	exit_Col->SetParentRT(*exit_Off);
	exit_Col->isFilled = false;
	exit_Col->visible = false;

	copyRight = new ObImage(L"Copyright.png");
	copyRight->scale = Vector2(36.0f * 4.0f, 12.0f) * 5.0f;
	copyRight->SetWorldPosY(-350.0f);

}

Game_Start::~Game_Start()
{
	SafeDelete(backCloud);
	SafeDelete(frontCloud);
	SafeDelete(bird);
	SafeDelete(mainLogo);
	SafeDelete(bgLayer);
}

void Game_Start::Update()
{
	backCloud->uv.x += DELTA / backCloud->scale.x * -25.0f;
	backCloud->uv.z += DELTA / backCloud->scale.x * -25.0f;

	frontCloud->uv.x += DELTA / frontCloud->scale.x * -25.0f;
	frontCloud->uv.z += DELTA / frontCloud->scale.x * -25.0f;

	bird->MoveWorldPos(RIGHT * 200.0f * DELTA);
	bird2->MoveWorldPos(LEFT * 150.0f * DELTA);
	bird2->reverseLR = true;

	if (bird->GetWorldPos().x > app.GetHalfWidth())
	{
		bird->SetWorldPos(Vector2(-700.0f, -100.0f));
	}

	if (bird2->GetWorldPos().x < -app.GetHalfWidth())
	{
		bird2->SetWorldPos(Vector2(700.0f, -350.0f));
	}

	backCloud->Update();
	frontCloud->Update();
	bird->Update();
	bird2->Update();
	mainLogo->Update();
	bgLayer->Update();
	play_Off->Update();
	play_On->Update();
	exit_Off->Update();
	exit_On->Update();
	copyRight->Update();
	play_Col->Update();
	exit_Col->Update();

}

void Game_Start::Render()
{
	bgLayer->Render();
	backCloud->Render();
	frontCloud->Render();
	mainLogo->Render();
	play_On->Render();
	play_Off->Render();
	exit_On->Render();
	exit_Off->Render();
	copyRight->Render();
	bird->Render();
	bird2->Render();
	play_Col->Render();
	exit_Col->Render();
}
