#include "stdafx.h"

Player::Player()
{
	player_State = PLAYERSTATE::IDLE;

	player_Col = new ObRect();
	player_Col->scale = Vector2(75.0f / 5.0f, 20.0f) * 6.0f;
	player_Col->pivot = OFFSET_B;
	player_Col->isFilled = false;
	player_Col->visible = false;
	player_Col->SetWorldPosX(-400.0f);
	player_Col->SetWorldPosY(-350.0f);
	player_Col->collider = COLLIDER::RECT;

	player_Buttom = new ObRect();
	player_Buttom->scale = Vector2(35.0f / 8.0f, 1.0f) * 6.0f;
	player_Buttom->pivot = OFFSET_B;
	player_Buttom->isFilled = false;
	player_Buttom->SetParentRT(*player_Col);
	player_Buttom->color = Color(0.5f, 0.0f, 0.0f, 1.0f);
	player_Buttom->collider = COLLIDER::RECT;
	player_Buttom->visible = false;

	player_arm = new ObRect();
	player_arm->scale = Vector2(50.0f, 30.0f);
	player_arm->pivot = OFFSET_N;
	player_arm->SetParentT(*player_Col);
	player_arm->SetWorldPos(Vector2(0.0f, 40.0f));
	player_arm->isFilled = false;
	player_arm->visible = false;

	player_Idle = new ObImage(L"player_idle.png");
	player_Idle->scale = Vector2(65.0f / 5.0f, 20.0f) * 6.0f;
	player_Idle->pivot = OFFSET_B;
	player_Idle->maxFrame.x = 5.0f;
	player_Idle->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	player_Idle->SetParentRT(*player_Col);
	player_Idle->visible = true;

	player_Run = new ObImage(L"player_run.png");
	player_Run->scale = Vector2(90.0f / 6.0f, 20.0f) * 6.0f;
	player_Run->pivot = OFFSET_B;
	player_Run->maxFrame.x = 6.0f;
	player_Run->ChangeAnim(ANIMSTATE::LOOP, 0.08f);
	player_Run->SetParentRT(*player_Col);
	player_Run->visible = false;

	//TEXT();
	player_Jump = new ObImage(TEXT("player_jump.png"));
	//player_Jump = new ObImage(L"player_jump.png");
	player_Jump->scale = Vector2(17.0f, 21.0f) * 6.0f;
	player_Jump->pivot = OFFSET_B;
	player_Jump->SetParentRT(*player_Col);
	player_Jump->visible = false;

	player_Die = new ObImage(L"player_die.png");
	player_Die->scale = Vector2(23.0f, 12.0f) * 6.0f;
	player_Die->pivot = OFFSET_B;
	player_Die->SetParentRT(*player_Col);
	player_Die->visible = false;

	player_Dust = new ObImage(L"DustEffect.png");
	player_Dust->scale = Vector2(84.0f / 6.0f, 13.0f) * 6.0f;
	player_Dust->pivot = OFFSET_B;
	player_Dust->ChangeAnim(ANIMSTATE::LOOP, 0.08f);
	player_Dust->SetParentRT(*player_Col);
	player_Dust->maxFrame.x = 6.0f;
	player_Dust->visible = false;

	sword_Effect = new ObImage(L"CosmosSwordFx.png");
	sword_Effect->scale = Vector2(376.0f / 8.0f, 60.0f) * 4.0f;
	sword_Effect->pivot = OFFSET_L;
	sword_Effect->SetParentRT(*player_Col);
	sword_Effect->maxFrame.x = 8.0f;
	sword_Effect->visible = false;

	player_Sword = new Weapon();
	player_Sword->sword->SetParentRT(*player_arm);
	player_Sword->sword->pivot = OFFSET_N;

	sword_Col = new ObCircle();
	sword_Col->scale = Vector2(376.0f / 8.0f, 376.0f / 8.0f) * 4.5f;
	sword_Col->pivot = OFFSET_L;
	sword_Col->SetParentRT(*sword_Effect);
	sword_Col->SetLocalPosX(-25.0f);
	sword_Col->visible = false;
	sword_Col->isFilled = false;
	sword_Col->colOnOff = false;
	sword_Col->collider = COLLIDER::CIRCLE;

	for (int i = 0; i < AMAX; i++)
	{
		shadowTrail[i] = new ObImage(L"alice_shadow.png");
		shadowTrail[i]->scale = Vector2(17.0f, 21.0f) * 6.0f;
		shadowTrail[i]->pivot = OFFSET_B;
		shadowTrail[i]->visible = false;
		shadowTrail[i]->color = Color(0.5f, 0.5f, 0.5f, 0.3f);
	}

	player_LifeBack = new ObImage(L"PlayerLifeBack.png");
	player_LifeBack->scale = Vector2(75.0f, 16.0f) * 4.0f;
	player_LifeBack->pivot = OFFSET_L;
	player_LifeBack->visible = true;
	player_LifeBack->SetWorldPos(Vector2(-650.0f, 350.0f));
	player_LifeBack->space = SPACE::SCREEN;

	player_LifeBase = new ObImage(L"PlayerLifeBase 1.png");
	player_LifeBase->scale = Vector2(75.0f, 16.0f) * 4.0f;
	player_LifeBase->pivot = OFFSET_L;
	player_LifeBase->SetParentRT(*player_LifeBack);
	player_LifeBase->visible = true;
	player_LifeBase->space = SPACE::SCREEN;

	player_Level = new ObImage(L"Level.png");
	player_Level->scale = Vector2(71.0f, 56.0f) * 0.8f;
	player_Level->pivot = OFFSET_L;
	player_Level->SetParentRT(*player_LifeBack);
	player_Level->SetWorldPosX(16.0f);
	player_Level->visible = true;
	player_Level->space = SPACE::SCREEN;

	player_Life = new ObImage(L"LifeBar.png");
	player_Life->scale = Vector2(50.0f, 10.0f) * 4.0f;
	player_Life->pivot = OFFSET_L;
	player_Life->SetParentRT(*player_LifeBack);
	player_Life->SetWorldPosX(90.0f);
	player_Life->visible = true;
	player_Life->space = SPACE::SCREEN;

	dash_Base[0] = new ObImage(L"DashCountBase_0.png");
	dash_Base[0]->scale = Vector2(11.0f, 8.0f) * 5.0f;
	dash_Base[0]->SetParentRT(*player_Life);
	dash_Base[0]->SetWorldPosX(-80.0f);
	dash_Base[0]->SetWorldPosY(-85.0f);

	dash_Base[1] = new ObImage(L"DashCountBase_0.png");
	dash_Base[1]->scale = Vector2(11.0f, 8.0f) * 5.0f;
	dash_Base[1]->SetParentRT(*dash_Base[0]);
	dash_Base[1]->SetWorldPosX(51.0f);
	dash_Base[1]->reverseLR = true;

	for (int i = 0; i < 2; i++)
	{
		dash_Base[i]->pivot = OFFSET_L;
		dash_Base[i]->visible = true;
		dash_Base[i]->space = SPACE::SCREEN;
	}

	for (int i = 0; i < 2; i++)
	{
		dash_Count[i] = new ObImage(L"DashCount.png");
		dash_Count[i]->scale = Vector2(9.0f, 4.0f) * 4.6f;
		
		dash_Count[i]->pivot = OFFSET_L;
		dash_Count[i]->visible = true;
		dash_Count[i]->space = SPACE::SCREEN;
	}

	dash_Count[0]->SetParentRT(*dash_Base[0]);
	dash_Count[0]->SetWorldPosX(9.0f);

	dash_Count[1]->SetParentRT(*dash_Base[1]);
	//dash_Count[0]->SetWorldPosX(51.0f);

	
	//대쉬, 점프
	dashCount = 2;
	jump = false;

	gravity = 0.0f;
	time = 0.0f;
	scalar = 500.0f;

	//잔상
	shadowNum = 4;
	shadowTimer = 0.0f;
	shadowInterval = 0.06f;
	index = 0;

	SOUND->AddSound("step_lth1.wav", "step1", false);
	SOUND->AddSound("step_lth2.wav", "step2", false);
	SOUND->AddSound("step_lth3.wav", "step3", false);
	SOUND->AddSound("step_lth4.wav", "step4", false);

	SOUND->AddSound("dead.wav", "dead", false);


}

Player::~Player()
{
	SafeDelete(player_Col);
	SafeDelete(player_Idle);
	SafeDelete(player_Run);
	SafeDelete(player_Jump);
	SafeDelete(player_Die);
	SafeDelete(player_Dust);
	SafeDelete(sword_Effect);
	SafeDelete(sword_Col);

	for (int i = 0; i < AMAX; i++)
	{
		SafeDelete(shadowTrail[i]);
	}

}

void Player::Update()
{

	//마우스 위치에 따라 캐릭터 방향
	Vector2 dis = INPUT->GetMouseWorldPos() - player_Col->GetWorldPos();
	dis.Normalize();

	//움직이는 방향 벡터
	moveDir = Vector2(0.0f, 0.0f);
	moveDir.Normalize();

	//평소
	if (player_State == PLAYERSTATE::IDLE)
	{
		dashCount = 2;
		dash_Count[0]->visible = true;
		dash_Count[1]->visible = true;
		player_Col->colOnOff = true;
		player_Buttom->colOnOff = true;
		gravity += 800.0f * DELTA;

		//IDLE -> RUN
		//왼쪽
		if (INPUT->KeyPress('A'))
		{
			player_State = PLAYERSTATE::RUN;
			player_Idle->visible = false;
			player_Run->visible = true;
			player_Dust->visible = true;
		}

		//오른쪽
		else if (INPUT->KeyPress('D'))
		{
			player_State = PLAYERSTATE::RUN;
			player_Idle->visible = false;
			player_Run->visible = true;
			player_Dust->visible = true;
		}

		//IDLE -> JUMP
		if (INPUT->KeyDown('W') || INPUT->KeyDown(VK_SPACE))
		{
			player_State = PLAYERSTATE::JUMP;
			player_Idle->visible = false;
			player_Run->visible = false;
			player_Jump->visible = true;
			player_Dust->visible = false;
			gravity = -550.0f;

			SOUND->AddSound("Jumping.wav", "Jumping", false);
			//SOUND->Stop("Jumping");
			SOUND->Play("Jumping");
		}

		//IDLE -> DASH
		if (INPUT->KeyDown(VK_RBUTTON) && dashCount > 0)
		{
			lastPos = dis;
			player_State = PLAYERSTATE::DASH;
			player_Idle->visible = false;
			player_Run->visible = false;
			player_Jump->visible = true;
			player_Dust->visible = false;
			player_Buttom->colOnOff = false;

			for (int i = 0; i < AMAX; i++)
			{
				shadowTrail[i]->visible = false;
			}

			SOUND->AddSound("dash.wav", "dash", false);
			SOUND->Play("dash");

			moving = player_Col->GetWorldPos();
			dashCount--;

		}

		//IDLE -> DIE
		if (player_HP <= 0.0f)
		{
			player_State = PLAYERSTATE::DIE;
			player_Idle->visible = false;
			player_Run->visible = false;
			player_Jump->visible = false;
			player_Dust->visible = false;
			player_Die->visible = true;
		}
	}

	//달리기
	else if (player_State == PLAYERSTATE::RUN)
	{
		SOUND->Play("step1");
		//SOUND->Play("step2");
		//SOUND->Play("step3");
		//SOUND->Play("step4");

		//RUN -> IDLE
		if (INPUT->KeyPress('A'))
		{
			moveDir.x = -1.0f;
		}

		else if (INPUT->KeyPress('D'))
		{
			moveDir.x = 1.0f;
		}

		if (INPUT->KeyUp('A'))
		{
			player_State = PLAYERSTATE::IDLE;
			player_Idle->visible = true;
			player_Run->visible = false;
			player_Jump->visible = false;
			player_Dust->visible = false;

			player_Dust->frame.x = 0;
		}

		if (INPUT->KeyUp('D'))
		{
			player_State = PLAYERSTATE::IDLE;
			player_Idle->visible = true;
			player_Run->visible = false;
			player_Jump->visible = false;
			player_Dust->visible = false;

			player_Dust->frame.x = 0;
		}
		
		//RUN -> JUMP
		if (INPUT->KeyDown('W') || INPUT->KeyDown(VK_SPACE))
		{
			player_State = PLAYERSTATE::JUMP;
			player_Idle->visible = false;
			player_Run->visible = false;
			player_Jump->visible = true;
			player_Dust->visible = false;
			gravity = -550.0f;

			SOUND->AddSound("Jumping.wav", "Jumping", false);
			//SOUND->Stop("Jumping");
			SOUND->Play("Jumping");
		}

		//RUN -> DASH
		if (INPUT->KeyDown(VK_RBUTTON) && dashCount > 0)
		{
			lastPos = dis;
			player_State = PLAYERSTATE::DASH;
			player_Idle->visible = false;
			player_Run->visible = false;
			player_Jump->visible = true;
			player_Dust->visible = false;
			player_Buttom->colOnOff = false;
			player_Buttom->colOnOff = false;

			for (int i = 0; i < AMAX; i++)
			{
				shadowTrail[i]->visible = false;
			}

			SOUND->AddSound("dash.wav", "dash", false);
			SOUND->Play("dash");

			moving = player_Col->GetWorldPos();
			dashCount--;
		}

		//RUN -> DIE
		if (player_HP <= 0.0f)
		{
			player_State = PLAYERSTATE::DIE;
			player_Idle->visible = false;
			player_Run->visible = false;
			player_Jump->visible = false;
			player_Dust->visible = false;
			player_Die->visible = true;
			player_Sword->sword->visible = false;
		}
	}

	//쩜프
	else if (player_State == PLAYERSTATE::JUMP)
	{
		//JUMP -> IDLE
		jump = true;

		//JUMP -> RUN
		if (INPUT->KeyPress('A'))
		{
			moveDir.x = -0.8f;
			player_Idle->visible = false;
			player_Run->visible = false;
			player_Jump->visible = true;
			player_Dust->visible = false;
		}

		else if (INPUT->KeyPress('D'))
		{
			moveDir.x = 0.8f;
			player_Idle->visible = false;
			player_Run->visible = false;
			player_Jump->visible = true;
			player_Dust->visible = false;
		}

		//JUMP -> DASH
		if (INPUT->KeyDown(VK_RBUTTON) && dashCount > 0)
		{
			lastPos = dis;
			player_State = PLAYERSTATE::DASH;
			player_Idle->visible = false;
			player_Run->visible = false;
			player_Jump->visible = true;
			player_Buttom->colOnOff = false;
			player_Buttom->colOnOff = false;

			for (int i = 0; i < AMAX; i++)
			{
				shadowTrail[i]->visible = false;
			}

			SOUND->AddSound("dash.wav", "dash", false);
			SOUND->Play("dash");

			moving = player_Col->GetWorldPos();
			dashCount--;
		}

		//JUMP -> DIE
		if (player_HP <= 0.0f)
		{
			player_State = PLAYERSTATE::DIE;
			player_Idle->visible = false;
			player_Run->visible = false;
			player_Jump->visible = false;
			player_Dust->visible = false;
			player_Die->visible = true;
		}
	}

	//대쉬
	else if (player_State == PLAYERSTATE::DASH)
	{
		gravity = 300.0f;

		//대쉬 이동
		player_Col->MoveWorldPos(lastPos * 1300.0f * DELTA);

		Vector2 disDash = player_Col->GetWorldPos() - moving;
		float distance = disDash.Length();

		//이동거리 제한
		if (distance >= 300.0f)
		{
			player_State = PLAYERSTATE::JUMP;

			for (int i = 0; i < AMAX; i++)
			{
				shadowTrail[i]->visible = false;
			}
		}

		if (TIMER->GetTick(shadowTimer, shadowInterval))
		{
			shadowTrail[index]->visible = true;
			shadowTrail[index]->SetWorldPos(player_Col->GetWorldPos());
			index++;

			if (index == shadowNum)
			{
				index = 0;
			}
		}

		if (dashCount == 1)
		{
			dash_Count[1]->visible = false;
		}

		else
		{
			dash_Count[0]->visible = false;
		}

	}

	else if (player_State == PLAYERSTATE::DIE)
	{
		SOUND->AddSound("dead.wav", "dead", false);
		SOUND->Play("dead");
	}
	
	//ATTACK
	if (INPUT->KeyDown(VK_LBUTTON))
	{
		w_lastPos = sword_Col->GetWorldPos();

		sword_Effect->visible = true;
		sword_Col->visible = true;
		sword_Col->colOnOff = true;
		sword_Effect->ChangeAnim(ANIMSTATE::ONCE, 0.08f);
		sword_Effect->rotation = Utility::DirToRadian(dis);

		SOUND->AddSound("wujusword.wav", "wujusword", false);
		SOUND->Stop("wujusword");
		SOUND->Play("wujusword");

		if (attack)
		{
			rotation = 60.0f * ToRadian;
			attack = !attack;
		}

		else if(!attack)
		{
			rotation = -60.0f * ToRadian;
			attack = true;
		}

	}

	else
	{
		if (dis.x > 0) //LR True
		{
			player_Idle->reverseLR = false;
			player_Run->reverseLR = false;
			player_Jump->reverseLR = false;
			player_Dust->reverseLR = false;
			player_Sword->sword->reverseLR = false;

			for (int i = 0; i < AMAX; i++)
			{
				shadowTrail[i]->reverseLR = false;
			}

			player_Dust->SetLocalPosX(-50.0f);
			player_arm->SetLocalPosX(30.0f);
			player_Sword->sword->SetLocalPosX(50.0f);
			sword_Effect->SetLocalPos(Vector2(50.0f, 60.0f));
			player_arm->rotation = -dis.x + 45.0f + rotation;
		}

		else //LR False
		{
			player_Idle->reverseLR = true;
			player_Run->reverseLR = true;
			player_Jump->reverseLR = true;
			player_Dust->reverseLR = true;
			player_Sword->sword->reverseLR = true;

			for (int i = 0; i < AMAX; i++)
			{
				shadowTrail[i]->reverseLR = true;
			}

			player_Dust->SetLocalPosX(50.0f);
			player_arm->SetLocalPosX(-30.0f);
			player_Sword->sword->SetLocalPosX(-50.0f);
			sword_Effect->SetLocalPos(Vector2(-50.0f, 60.0f));
			player_arm->rotation = -dis.x - 45.0f + rotation;
		}
	}

	if (sword_Effect->frame.x == 7.0f)
	{
		sword_Col->visible = false;
		sword_Effect->visible = false;
	}

	player_Col->MoveWorldPos(moveDir * scalar * DELTA);
	player_Col->MoveWorldPos(DOWN * gravity * DELTA);
	gravity += 1000.0f * DELTA;

	for (int i = 0; i < AMAX; i++)
	{
		shadowTrail[i]->Update();
	}

	player_Col->Update();
	player_Idle->Update();
	player_Sword->Update();
	player_arm->Update();
	player_Run->Update();
	player_Jump->Update();
	player_Die->Update();
	player_Dust->Update();
	sword_Effect->Update();
	sword_Col->Update();
	player_Buttom->Update();
	player_LifeBase->Update();
	player_LifeBack->Update();
	player_Level->Update();
	player_Life->Update();

	for (int i = 0; i < 2; i++)
	{
		dash_Base[i]->Update();
		dash_Count[i]->Update();
	}
}

void Player::Render()
{
	for (int i = 0; i < AMAX; i++)
	{
		shadowTrail[i]->Render();
	}

	player_Col->Render();
	player_Dust->Render();
	player_Sword->Render();
	player_arm->Render();
	player_Idle->Render();
	player_Run->Render();
	player_Jump->Render();
	player_Die->Render();
	sword_Effect->Render();
	sword_Col->Render();
	player_Buttom->Render();
	player_LifeBack->Render();
	player_LifeBase->Render();
	player_Level->Render();
	player_Life->Render();

	for (int i = 0; i < 2; i++)
	{
		dash_Base[i]->Render();
		dash_Count[i]->Render();
	}
}
