#include "stdafx.h"
#include "Main.h"

void Main::Init()
{
	//Scene 초기값
	game_Scene = MAINSCENE::GAMESTART;

	if (game_Scene == MAINSCENE::BOSS)
	{
		SOUND->AddSound("beliallaugh_rev.wav", "beliallaugh_rev", false);
		SOUND->Play("beliallaugh_rev");
	}

	//게임시작
	start = new Game_Start;

	//플레이어
	pl = new Player();

	//보스
	bossMap = new Dungeon();
	berial = new Berial();

	//마을 배경
	sky = new ObImage(L"Town_BGL.png");
	sky->scale = Vector2(app.GetHalfWidth(), app.GetHalfHeight()) * 3.0f;
	//sky->scale = Vector2(320.0f, 178.0f) * 5.0f;
	sky->space = SPACE::SCREEN;

	tree = new ObImage(L"TownBG_Day.png");
	tree->scale = Vector2(app.GetHalfWidth() * 3.0f, app.GetHeight());
	//tree->scale = Vector2(320.0f, 142.0f) * 5.0f;
	tree->space = SPACE::SCREEN;

	layer = new ObImage(L"TownLayer_Day.png");
	layer->scale = Vector2(app.GetHalfWidth() * 3.0f, app.GetHeight());
	//layer->scale = Vector2(320.0f, 95.0f) * 5.0f;
	layer->SetWorldPosY(-150.0f);
	layer->space = SPACE::SCREEN;

	floor = new ObImage(L"Villiaged.png");
	floor->scale = Vector2(2038.0f * 4.0f, 300.0f * 4.5f);
	floor->pivot = OFFSET_B;
	floor->SetWorldPosY(-415.0f);

	//던전 입구
	entrance = new ObImage(L"DungeonEat.png");
	entrance->scale = Vector2(3360.0f / 28.0f, 90.0f) * 5.0f;
	entrance->SetWorldPos(Vector2(0.0f, -351.0f));
	entrance->pivot = OFFSET_B;
	entrance->frame.x = 0.0f;
	entrance->maxFrame.x = 28.0f;
	entrance->visible = false;

	entrance_Col = new ObRect();
	entrance_Col->scale = Vector2(3360.0f / 28.0f * 3.5f, 90.0f * 4.7f);
	entrance_Col->SetParentRT(*entrance);
	entrance_Col->pivot = OFFSET_B;
	entrance_Col->color = Color(0.0f, 0.0f, 0.5f, 1.0f);
	entrance_Col->isFilled = false;
	entrance_Col->visible = false;

	//바닥 배열로
	for (int i = 0; i < FMAX; i++)
	{
		floorCol[i] = new ObRect();
		floorCol[i]->scale = Vector2(200.0f, 15.0f);
		floorCol[i]->pivot = OFFSET_LT;
		floorCol[i]->SetWorldPos(Vector2(-4076.0f + (200.0f * i), -351.0f));
		floorCol[i]->isFilled = false;
		floorCol[i]->visible = false;
		floorCol[i]->collider = COLLIDER::RECT;
	}

	//F1
	for (int i = 0; i < F1MAX; i++)
	{
		floor1[i] = new ObRect();
		floor1[i]->scale = Vector2(210.0f, 15.0f);
		floor1[i]->pivot = OFFSET_LT;
		floor1[i]->SetWorldPos(Vector2(-4076.0f + (210.0f * i), 295.0f));
		floor1[i]->isFilled = false;
		floor1[i]->visible = false;
		floor1[i]->color = Color(0.0f, 0.5f, 0.0f, 1.0f);
		floor1[i]->collider = COLLIDER::RECT;
	}

	//F2
	for (int i = 0; i < F2MAX; i++)
	{
		floor2[i] = new ObRect();
		floor2[i]->scale = Vector2(216.0f, 15.0f);
		floor2[i]->pivot = OFFSET_LT;
		floor2[i]->SetWorldPos(Vector2(-1000.0f + (216.0f * i), 157.0f));
		floor2[i]->isFilled = false;
		floor2[i]->visible = false;
		floor2[i]->color = Color(0.0f, 0.5f, 0.0f, 1.0f);
		floor2[i]->collider = COLLIDER::RECT;
	}

	//F3
	for (int i = 0; i < F3MAX; i++)
	{
		floor3[i] = new ObRect();
		floor3[i]->scale = Vector2(210.0f, 15.0f);
		floor3[i]->pivot = OFFSET_LT;
		floor3[i]->SetWorldPos(Vector2(2200 + (210.0f * i), 295.0f));
		floor3[i]->isFilled = false;
		floor3[i]->visible = false;
		floor3[i]->color = Color(0.0f, 0.5f, 0.0f, 1.0f);
		floor3[i]->collider = COLLIDER::RECT;
	}

	//블럭
	for (int i = 0; i < 4; i++)
	{
		block[i] = new ObRect();
		block[i]->scale = Vector2(233.0f, 15.0f);
		block[i]->pivot = OFFSET_LT;
		block[i]->visible = false;
		block[i]->collider = COLLIDER::RECT;
	}

	block[0]->SetWorldPos(Vector2(-2562.0f, -200.0f));
	block[1]->SetWorldPos(Vector2(-2466.0f, -40.0f));
	block[2]->SetWorldPos(Vector2(-2700.0f, 90.0f));
	block[3]->SetWorldPos(Vector2(2211.0f, -55.0f));

	SOUND->AddSound("0.Town.wav", "Town", true);
	SOUND->AddSound("1.JailBoss.wav", "JailBoss", true);

	//벨리알
	SOUND->AddSound("iceball.wav", "iceball", false);
	SOUND->AddSound("slimeball.wav", "slimeball", false);
	SOUND->AddSound("random5.wav", "random5", false);

	//플레이어 히트
	SOUND->AddSound("Hit_Player.wav", "Hit_Player", false);

}

void Main::Release()
{
	SafeDelete(sky);
	SafeDelete(tree);
	SafeDelete(layer);
	SafeDelete(floor);

	for (int i = 0; i < FMAX; i++)
	{
		SafeDelete(floorCol[i]);
	}

	for (int i = 0; i < F1MAX; i++)
	{
		SafeDelete(floor1[i]);
	}

	for (int i = 0; i < F2MAX; i++)
	{
		SafeDelete(floor2[i]);
	}

	for (int i = 0; i < F3MAX; i++)
	{
		SafeDelete(floor3[i]);
	}
}

void Main::Update()
{
	//마우스 좌표 출력
	//cout << "마우스 X 좌표 : " << INPUT->GetMouseWorldPos().x << endl;
	//cout << "마우스 Y 좌표 : " << INPUT->GetMouseWorldPos().y << endl;

	//게임시작
	if (game_Scene == MAINSCENE::GAMESTART)
	{
		//GameStart
		SOUND->AddSound("title.wav", "Title", true);
		SOUND->Play("Title");

		start->Update();
	}

	//메인
	else if (game_Scene == MAINSCENE::MAIN)
	{
		sky->uv.x += DELTA / sky->scale.x * 25.0f;
		sky->uv.z += DELTA / sky->scale.x * 25.0f;

		//마을
		SOUND->Stop("Title");
		SOUND->Play("Town");

		sky->Update();
		tree->Update();
		layer->Update();
		floor->Update();

		for (int i = 0; i < FMAX; i++)
		{
			floorCol[i]->Update();
		}

		for (int i = 0; i < F1MAX; i++)
		{
			floor1[i]->Update();
		}

		for (int i = 0; i < F2MAX; i++)
		{
			floor2[i]->Update();
		}

		for (int i = 0; i < F3MAX; i++)
		{
			floor3[i]->Update();
		}

		for (int i = 0; i < 4; i++)
		{
			block[i]->Update();
		}

		entrance->Update();
		entrance_Col->Update();
		pl->Update();
	}

	//보스
	else if (game_Scene == MAINSCENE::BOSS)
	{
		for (int i = 0; i < FMAX; i++)
		{
			floorCol[i]->Update();
		}

		SOUND->Stop("Title");
		SOUND->Stop("Town");
		SOUND->Play("JailBoss");

		bossMap->Update();
		berial->Update();
		pl->Update();
	}

}

void Main::LateUpdate()
{
	pl->sword_Col->visible = false;
	//위치 고정
	if (pl->player_Col->GetWorldPos().y < -351.0f)
	{
		pl->player_Col->SetWorldPosY(-351.0f);
	}

	//게임시작 UI 충돌
	if (game_Scene == MAINSCENE::GAMESTART)
	{
		//게임시작 충돌
		if (start->play_Col->IntersectScreenMouse(INPUT->GetMouseScreenPos()))
		{
			start->play_On->visible = true;
			start->play_Off->visible = false;

			if (INPUT->KeyDown(VK_LBUTTON))
			{
				game_Scene = MAINSCENE::MAIN;

				pl->player_Col->SetWorldPosX(-1661.0f);
				pl->player_Col->SetWorldPosY(-350.0f);
			}
		}

		else
		{
			start->play_On->visible = false;
			start->play_Off->visible = true;
		}

		//종료 충돌
		if (start->exit_Col->IntersectScreenMouse(INPUT->GetMouseScreenPos()))
		{
			start->exit_On->visible = true;
			start->exit_Off->visible = false;
		}

		else
		{
			start->exit_On->visible = false;
			start->exit_Off->visible = true;
		}
	}

	//메인 충돌
	else if (game_Scene == MAINSCENE::MAIN)
	{
		//메인 플레이어 가두기
		pl->player_Col->SetWorldPosX(Utility::Saturate(pl->player_Col->GetWorldPos().x, -4035.0f, 4035.0f));

		//메인 캠 고정
		CAM->position.x = Utility::Saturate(pl->player_Col->GetWorldPos().x, -4074.0f + app.GetHalfWidth(), 4074.0f - app.GetHalfWidth());
		CAM->position.y = Utility::Saturate(pl->player_Col->GetWorldPos().y, 0.0f, 700.0f);

		//F1 플레이어 충돌
		for (int i = 0; i < F1MAX; i++)
		{
			if (floor1[i]->Intersect(pl->player_Buttom->GetWorldPos()))
			{
				if (pl->gravity > 0)
				{
					//cout << "F1 충돌!" << endl;
					pl->player_Col->SetWorldPosY(floor1[i]->GetWorldPos().y + 0.000001f);
					pl->gravity = 0.0f;
					pl->player_Col->Update();

					if (pl->player_State == PLAYERSTATE::JUMP)
					{
						pl->player_State = PLAYERSTATE::IDLE;
						pl->player_Idle->visible = true;
						pl->player_Run->visible = false;
						pl->player_Jump->visible = false;
					}
				}

			}
		}

		//F2 플레이어 충돌
		for (int i = 0; i < F2MAX; i++)
		{
			if (floor2[i]->Intersect(pl->player_Buttom->GetWorldPos()))
			{
				if (pl->gravity > 0)
				{
					//cout << "F2 충돌!" << endl;
					pl->player_Col->SetWorldPosY(floor2[i]->GetWorldPos().y + 0.000001f);
					pl->gravity = 0.0f;
					pl->player_Col->Update();

					if (pl->player_State == PLAYERSTATE::JUMP)
					{
						pl->player_State = PLAYERSTATE::IDLE;
						pl->player_Idle->visible = true;
						pl->player_Run->visible = false;
						pl->player_Jump->visible = false;
					}
				}
			}
		}

		//F3 플레이어 충돌
		for (int i = 0; i < F3MAX; i++)
		{
			if (floor3[i]->Intersect(pl->player_Buttom->GetWorldPos()))
			{
				if (pl->gravity > 0)
				{
					//cout << "F3 충돌!" << endl;
					pl->player_Col->SetWorldPosY(floor3[i]->GetWorldPos().y + 0.000001f);
					pl->gravity = 0.0f;
					pl->player_Col->Update();

					if (pl->player_State == PLAYERSTATE::JUMP)
					{
						pl->player_State = PLAYERSTATE::IDLE;
						pl->player_Idle->visible = true;
						pl->player_Run->visible = false;
						pl->player_Jump->visible = false;
					}
				}

			}
		}

		//block 충돌
		for (int i = 0; i < 4; i++)
		{
			if (block[i]->Intersect(pl->player_Buttom->GetWorldPos()))
			{
				if (pl->gravity > 0.0f)
				{
					//cout << "블럭 충돌" << endl;
					pl->player_Col->SetWorldPosY(block[i]->GetWorldPos().y + 0.000001f);
					pl->gravity = 0.0f;
					pl->player_Col->Update();

					if (pl->player_State == PLAYERSTATE::JUMP)
					{
						pl->player_State = PLAYERSTATE::IDLE;
						pl->player_Idle->visible = true;
						pl->player_Run->visible = false;
						pl->player_Jump->visible = false;
					}
				}

			}
		}

		//바닥 플레이어 충돌
		for (int i = 0; i < FMAX; i++)
		{
			if (floorCol[i]->Intersect(pl->player_Buttom->GetWorldPos()))
			{
				pl->player_Col->SetWorldPosY(-351.0f);
				pl->gravity = 0.0f;
				pl->jump = false;

				if (pl->player_State == PLAYERSTATE::JUMP)
				{
					pl->player_State = PLAYERSTATE::IDLE;
					pl->player_Idle->visible = true;
					pl->player_Run->visible = false;
					pl->player_Jump->visible = false;
				}

				for (int i = 0; i < AMAX; i++)
				{
					pl->shadowTrail[i]->Update();
				}
			}
		}

		//던전 입장
		if (entrance_Col->Intersect(pl->player_Col))
		{
			if (INPUT->KeyUp(VK_UP))
			{
				entrance->visible = true;
				entrance->ChangeAnim(ANIMSTATE::ONCE, 0.15f);

				SOUND->AddSound("DungeonOut.wav", "DungeonOut", false);
				SOUND->Play("DungeonOut");
			}

			if (entrance->uv.x >= 0.95f && entrance->uv.z <= 1.0f)
			{
				game_Scene = MAINSCENE::BOSS;
			}

		}
	}

	//보스 충돌
	else if (game_Scene == MAINSCENE::BOSS)
	{
		pl->sword_Col->visible = false;
		//보스 플레이어 가두기
		pl->player_Col->SetWorldPosX(Utility::Saturate(pl->player_Col->GetWorldPos().x, -750.0f, 750.0f));

		//보스 캠 고정
		CAM->position.x = Utility::Saturate(pl->player_Col->GetWorldPos().x, -800.0f + app.GetHalfWidth(), 800.0f - app.GetHalfWidth());
		CAM->position.y = Utility::Saturate(pl->player_Col->GetWorldPos().y, 0.0f, 419.0f);

		for (int i = 0; i < 8; i++)
		{
			if (bossMap->bossFloor[i]->Intersect(pl->player_Buttom->GetWorldPos()))
			{
				if (pl->gravity > 0)
				{
					pl->player_Col->SetWorldPosY(bossMap->bossFloor[i]->GetWorldPos().y + 0.000001f);
					pl->gravity = 0.0f;
					pl->player_Col->Update();

					if (pl->player_State == PLAYERSTATE::JUMP)
					{
						pl->player_State = PLAYERSTATE::IDLE;
						pl->player_Idle->visible = true;
						pl->player_Run->visible = false;
						pl->player_Jump->visible = false;
					}
				}
			}
		}

		//보스 무기 피격 시 - 무기 피격범위 sword_Col
		if (berial->berial_Col->Intersect(pl->sword_Col))
		{
			if (berial->boss_HP > 0.0f)
			{
				berial->boss_HP -= 20.0f;
				berial->boss_Life->scale.x -= 20.0f;
				cout << "보스 HP : " << berial->boss_HP << endl;

				if (berial->boss_HP == 0.0f)
				{
					cout << "보스 컷" << endl;
					berial->boss_Pattern = BOSSPATTERN::DIE;
				}

				berial->SetDamage();
				pl->sword_Col->colOnOff = false;
			}

		}
		
		//플레이어 피격 시
		
		//Laser
		
		if (berial->laser_Col->Intersect(pl->player_Col))
		{
			if (pl->player_HP > 0.0f)
			{
				SOUND->Play("Hit_Player");

				berial->laser_Col->colOnOff = false;
				pl->player_HP -= 1.0f;
				pl->player_Life->scale.x -= 2.001f;
				cout << "LLaser Hit" << endl;
			}
		}

		if (berial->laser_Col2->Intersect(pl->player_Col))
		{
			if (pl->player_HP > 0.0f)
			{
				SOUND->Play("Hit_Player");

				berial->laser_Col2->colOnOff = false;
				pl->player_HP -= 1.0f;
				pl->player_Life->scale.x -= 2.001f;
				cout << "RLaser Hit" << endl;
			}
		}

		//Sword
		for (int i = 0; i < SMAX; i++)
		{
			if (berial->swords[i]->sword_Col->Intersect(pl->player_Col))
			{
				if (pl->player_HP > 0.0f)
				{
					//SOUND->Stop("Hit_Player");
					SOUND->Play("Hit_Player");
					
					berial->swords[i]->sword_Col->colOnOff = false;
					pl->player_HP -= 5.0f;
					pl->player_Life->scale.x -= 10.0f;
					cout << "Sword Hit" << endl;

				}
			}
		}
		

		//Ball
		//for (int i = 0; i < BMAX; i++)
		//{
		//	if (berial->balls[i]->ball_Col[0]->Intersect(pl->player_Col) ||
		//		berial->balls[i]->ball_Col[1]->Intersect(pl->player_Col) || 
		//		berial->balls[i]->ball_Col[2]->Intersect(pl->player_Col) || 
		//		berial->balls[i]->ball_Col[3]->Intersect(pl->player_Col))
		//	{
		//		if (pl->player_HP > 0.0f)
		//		{
		//			//SOUND->Stop("Hit_Player");
		//			SOUND->Play("Hit_Player");

		//			berial->balls[i]->ball_Col[0]->colOnOff = false;
		//			berial->balls[i]->ball_Col[1]->colOnOff = false;
		//			berial->balls[i]->ball_Col[2]->colOnOff = false;
		//			berial->balls[i]->ball_Col[3]->colOnOff = false;

		//			pl->player_HP -= 1.0f;
		//			pl->player_Life->scale.x -= 2.0f;
		//			cout << "Ball Hit" << endl;

		//		}
		//	}
		//}

		//레이저 위치
		if (INPUT->KeyDown('1'))
		{
			pl_lastPos1 = pl->player_Col->GetWorldPos().y;
		}

		else if (INPUT->KeyDown('2'))
		{
			pl_lastPos2 = pl->player_Col->GetWorldPos().y;
		}

		scalar1 = pl_lastPos1 - berial->idle_Hand1->GetWorldPos().y;
		scalar2 = pl_lastPos2 - berial->idle_Hand2->GetWorldPos().y;

		if (fabs(scalar1) > 1.0f)
		{
			//cout << scalar1 << endl;
			berial->idle_Hand1->MoveWorldPos(UP * (scalar1 * 8.0f) * DELTA);
		}

		else if (fabs(scalar1) < 1.0f)
		{
			scalar1 = 0.0f;
		}

		if (fabs(scalar2) > 1.0f)
		{
			//cout << scalar2 << endl;
			berial->idle_Hand2->MoveWorldPos(UP * (scalar2 * 8.0f) * DELTA);
		}

		else if (fabs(scalar2) < 1.0f)
		{
			scalar2 = 0.0f;

		}

		//Sword
		for (int i = 0; i < SMAX; i++)
		{
			pl_lastPos = pl->player_Col->GetWorldPos();
			sword_dir = pl_lastPos - berial->swords[i]->sword_Col->GetWorldPos();

			if (berial->swords[i]->sword_Shoot->visible == false)
			{
				berial->swords[i]->sword_Col->rotation = Utility::DirToRadian(sword_dir);
			}
			
			Vector2 Dir = berial->swords[i]->sword_Col->GetRight();

			if (berial->swords[i]->sword_Shoot->visible)
			{
				berial->swords[i]->sword_Default->visible = false;
				berial->swords[i]->sword_Col->MoveWorldPos(Dir * 1500.0f * DELTA);
			}

			float aaa = sword_dir.Length();

			if (aaa > 2000)
			{
				cout << "Reset" << endl;
				berial->Reset();
			}
		}

		//Die 충돌
		if (bossMap->bossFloor[6]->Intersect(berial->die_Head_Col))
		{
			berial->dh_scalar = 0.0f;
			berial->die_Head_Col->SetWorldPosY(bossMap->bossFloor[6]->GetWorldPos().y + 1.0f);
		}

		else if (bossMap->bossFloor[6]->Intersect(berial->die_Mouth_Col))
		{
			berial->dm_scalar = 0.0f;
			berial->die_Mouth_Col->SetWorldPosY(bossMap->bossFloor[6]->GetWorldPos().y + 1.0f);
		}

		//바닥 플레이어 충돌
		for (int i = 0; i < FMAX; i++)
		{
			if (floorCol[i]->Intersect(pl->player_Buttom->GetWorldPos()))
			{
				pl->player_Col->SetWorldPosY(-351.0f);
				pl->gravity = 0.0f;
				pl->jump = false;

				if (pl->player_State == PLAYERSTATE::JUMP)
				{
					pl->player_State = PLAYERSTATE::IDLE;
					pl->player_Idle->visible = true;
					pl->player_Run->visible = false;
					pl->player_Jump->visible = false;
				}

				for (int i = 0; i < AMAX; i++)
				{
					pl->shadowTrail[i]->Update();
				}
			}
		}

		//pl->player_Col->Update();
		//pl->player_Idle->Update();
		//pl->player_Run->Update();
		//pl->player_Jump->Update();
		//pl->player_Die->Update();
		//pl->player_Dust->Update();
		//pl->player_arm->Update();
		//pl->player_Sword->sword->Update();
		//pl->player_Buttom->Update();
		//pl->sword_Effect->Update();
		//pl->sword_Col->Update();
		berial->Update();
		bossMap->Update();
	}

}

void Main::Render()
{
	//게임시작
	if (game_Scene == MAINSCENE::GAMESTART)
	{
		start->Render();
	}

	//메인
	else if (game_Scene == MAINSCENE::MAIN)
	{
		sky->Render();
		tree->Render();
		layer->Render();
		floor->Render();

		for (int i = 0; i < FMAX; i++)
		{
			floorCol[i]->Render();
		}

		for (int i = 0; i < F1MAX; i++)
		{
			floor1[i]->Render();
		}

		for (int i = 0; i < F2MAX; i++)
		{
			floor2[i]->Render();
		}

		for (int i = 0; i < F3MAX; i++)
		{
			floor3[i]->Render();
		}

		for (int i = 0; i < 4; i++)
		{
			block[i]->Render();
		}

		entrance->Render();
		entrance_Col->Render();
		pl->Render();
	}

	//보스
	else if (game_Scene == MAINSCENE::BOSS)
	{
		bossMap->Render();

		for (int i = 0; i < FMAX; i++)
		{
			floorCol[i]->Render();
		}

		pl->Render();
		berial->Render();
	}


}

void Main::ResizeScreen()
{

}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prevInstance, LPWSTR param, int command)
{
	app.SetAppName(L"Game1");
	app.SetInstance(instance);
	app.InitWidthHeight(1400, 800.0f);
	Main* main = new Main();
	int wParam = (int)WIN->Run(main);
	WIN->DeleteSingleton();
	SafeDelete(main);
	return wParam;
}