#include "stdafx.h"

Dungeon::Dungeon()
{
	//¸Ê
	boss = new ObImage(L"BossMaped.png");
	boss->scale = Vector2(320.0f * 5.0f, 320.0f * 4.0f);
	boss->SetLocalPosY(200.0f);

	//¾ç¿·¿¡ ¹®
	door1 = new ObImage(L"door.png");
	door1->scale = Vector2(1518.0f / 23.0f, 20.0f) * 5.6f;
	door1->SetWorldPos(Vector2(-760.0f, -170.0f));
	door1->rotation = 270.0f * ToRadian;
	door1->maxFrame.x = 23.0f;
	door1->ChangeAnim(ANIMSTATE::ONCE, 0.1f);

	door2 = new ObImage(L"door.png");
	door2->scale = Vector2(1518.0f / 23.0f, 20.0f) * 5.6f;
	door2->SetWorldPos(Vector2(760.0f, -170.0f));
	door2->rotation = 90.0f * ToRadian;
	door2->maxFrame.x = 23.0f;
	door2->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	

	//È¶ºÒ
	{
	for (int i = 0; i < 4; i++)
	{
		torch[i] = new ObImage(L"torch.png");
		torch[i]->scale = Vector2(140.0f / 7.0f, 30.0f) * 3.5f;
		torch[i]->maxFrame.x = 7.0f;
		torch[i]->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	}
	
	torch[0]->SetWorldPos(Vector2(-170.0f, -90.0f));
	torch[1]->SetWorldPos(Vector2(170.0f, -90.0f));
	torch[2]->SetWorldPos(Vector2(-222.0f, 308.0f));
	torch[3]->SetWorldPos(Vector2(220.0f, 308.0f));
	}

	//ºí·°
	{
	for (int i = 0; i < 8; i++)
	{
		bossFloor[i] = new ObRect();
		bossFloor[i]->pivot = OFFSET_LT;
		bossFloor[i]->isFilled = false;
		bossFloor[i]->collider = COLLIDER::RECT;
		bossFloor[i]->visible = false;
	}

	//0~5±îÁö
	for (int i = 0; i < 6; i++)
	{
		bossFloor[i]->scale = Vector2(265.0f, 15.0f);
	}

	
	bossFloor[0]->SetWorldPos(Vector2(-515.0f, -75.0f));
	bossFloor[1]->SetWorldPos(Vector2(230.0f, -75.0f));
	bossFloor[2]->SetWorldPos(Vector2(-554.0f, 135.0f));
	bossFloor[3]->SetWorldPos(Vector2(290.0f, 135.0f));
	bossFloor[4]->SetWorldPos(Vector2(-556.0f, 328.0f));
	bossFloor[5]->SetWorldPos(Vector2(290.0f, 328.0f));

	//6
	bossFloor[6]->scale = Vector2(826.0f, 15.0f);
	bossFloor[6]->SetWorldPos(Vector2(-403.0f, -230.0f));
	
	//7
	bossFloor[7]->scale = Vector2(312.0f, 15.0f);
	bossFloor[7]->SetWorldPos(Vector2(-141.0f, 485.0f));
	}
}

Dungeon::~Dungeon()
{
	SafeDelete(boss);
	SafeDelete(door1);
	SafeDelete(door2);

	for (int i = 0; i < 8; i++)
	{
		SafeDelete(bossFloor[i]);
	}
}

void Dungeon::Update()
{ 
	if (door1->frame.x == 15.0f || door2->frame.x == 15.0f)
	{
		door1->ChangeAnim(ANIMSTATE::STOP, 0);
		door2->ChangeAnim(ANIMSTATE::STOP, 0);
	}

	for (int i = 0; i < 8; i++)
	{
		bossFloor[i]->Update();
	}

	for (int i = 0; i < 4; i++)
	{
		torch[i]->Update();
	}

	door1->Update();
	door2->Update();
	boss->Update();
}

void Dungeon::Render()
{
	boss->Render();
	door1->Render();
	door2->Render();

	for (int i = 0; i < 4; i++)
	{
		torch[i]->Render();
	}

	for (int i = 0; i < 8; i++)
	{
		bossFloor[i]->Render();
	}
}
