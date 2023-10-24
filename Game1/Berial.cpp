#include "stdafx.h"

Berial::Berial()
{
	boss_Pattern = BOSSPATTERN::IDLE;
	ball_index = 0;
	sword_index = 0;
	shoot_index = 0;

	//보스 피격판정
	berial_Col = new ObRect();
	berial_Col->scale = Vector2(700.0f / 10.0f, 96.0f) * 3.0f;
	berial_Col->SetWorldPos(Vector2(10.0f, 75.0f));
	berial_Col->isFilled = false;
	berial_Col->visible = false;
	berial_Col->collider = COLLIDER::RECT;

	//IDLE
	idle_Head = new ObImage(L"idle_H.png");
	idle_Head->scale = Vector2(700.0f / 10.0f, 96.0f) * 4.0f;
	idle_Head->SetWorldPos(Vector2(-20.0f, 100.0f));
	idle_Head->maxFrame.x = 10.0f;
	idle_Head->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

	//왼손
	idle_Hand1 = new ObImage(L"idle.png");
	idle_Hand1->scale = Vector2(570.0f / 10.0f, 67.0f) * 4.0f;
	idle_Hand1->SetWorldPos(Vector2(-465.0f, -130.0f));
	idle_Hand1->maxFrame.x = 10.0f;
	idle_Hand1->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

	//오른손
	idle_Hand2 = new ObImage(L"idle.png");
	idle_Hand2->scale = Vector2(570.0f / 10.0f, 67.0f) * 3.5f;
	idle_Hand2->SetWorldPos(Vector2(480.0f, 230.0f));
	idle_Hand2->maxFrame.x = 10.0f;
	idle_Hand2->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	idle_Hand2->reverseLR = true;

	//피격 시 이미지 전환
	idle_shot = new ObImage(L"idle_shot.png");
	idle_shot->scale = Vector2(700.0f / 10.0f, 96.0f) * 4.0f;
	idle_shot->SetParentRT(*idle_Head);
	idle_shot->maxFrame.x = 10.0f;
	idle_shot->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	idle_shot->visible = false;

	//LASER
	//왼손 레이저
	laser_Hand1 = new ObImage(L"attack_Hand.png");
	laser_Hand1->scale = Vector2(1170.0f / 18.0f, 71.0f) * 4.0f;
	laser_Hand1->SetParentRT(*idle_Hand1);
	laser_Hand1->maxFrame.x = 18.0f;
	laser_Hand1->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	laser_Hand1->visible = false;
	laser_Hand1->reverseLR = false;

	laser_Head1 = new ObImage(L"L_head.png");
	laser_Head1->scale = Vector2(189.0f / 7.0f, 44.0f) * 4.0f;
	laser_Head1->SetParentRT(*idle_Hand1);
	laser_Head1->SetLocalPos(Vector2(-30.0f, -10.0f));
	laser_Head1->maxFrame.x = 7.0f;
	laser_Head1->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	laser_Head1->pivot = OFFSET_L;
	laser_Head1->visible = false;
	laser_Head1->reverseLR = false;

	for (int i = 0; i < LMAX; i++)
	{
		laser_Body1[i] = new ObImage(L"L_body.png");
		laser_Body1[i]->scale = Vector2(224.0f / 7.0f, 51.0f) * 4.0f;
		laser_Body1[i]->SetParentRT(*laser_Head1);
		laser_Body1[i]->SetWorldPos(Vector2(100.0f + (i * 224.0f / 7.0f * 4.0f), 2.0f));
		laser_Body1[i]->maxFrame.x = 7.0f;
		laser_Body1[i]->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		laser_Body1[i]->pivot = OFFSET_L;
		laser_Body1[i]->visible = false;
		laser_Body1[i]->reverseLR = false;
	}

	laser_Col = new ObRect();
	laser_Col->scale = Vector2(224.0f * 2.0f, 51.0f) * 4.0f;
	laser_Col->SetParentRT(*laser_Head1);
	//laser_Col->SetWorldPos(Vector2(0.0f + (10 * 224.0f / 7.0f * 4.0f), 2.0f));
	laser_Col->pivot = OFFSET_L;
	laser_Col->visible = true;
	laser_Col->isFilled = false;
	laser_Col->collider = COLLIDER::RECT;
	laser_Col->colOnOff = false;

	//오른손 레이저
	laser_Hand2 = new ObImage(L"attack_Hand.png");
	laser_Hand2->scale = Vector2(1170.0f / 18.0f, 71.0f) * 4.0f;
	laser_Hand2->SetParentRT(*idle_Hand2);
	laser_Hand2->maxFrame.x = 18.0f;
	laser_Hand2->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	laser_Hand2->visible = false;
	laser_Hand2->reverseLR = true;

	laser_Head2 = new ObImage(L"L_head.png");
	laser_Head2->scale = Vector2(189.0f / 7.0f, 44.0f) * 4.0f;
	laser_Head2->SetParentRT(*idle_Hand2);
	laser_Head2->SetLocalPos(Vector2(30.0f, -10.0f));
	laser_Head2->maxFrame.x = 7.0f;
	laser_Head2->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	laser_Head2->pivot = OFFSET_R;
	laser_Head2->visible = false;
	laser_Head2->reverseLR = true;

	for (int i = 0; i < LMAX; i++)
	{
		laser_Body2[i] = new ObImage(L"L_body.png");
		laser_Body2[i]->scale = Vector2(224.0f / 7.0f, 51.0f) * 4.0f;
		laser_Body2[i]->SetParentRT(*laser_Head2);
		laser_Body2[i]->SetWorldPos(Vector2(-100.0f - (i * 224.0f / 7.0f * 4.0f), 2.0f));
		laser_Body2[i]->maxFrame.x = 7.0f;
		laser_Body2[i]->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		laser_Body2[i]->pivot = OFFSET_R;
		laser_Body2[i]->visible = false;
		laser_Body2[i]->reverseLR = true;
	}

	laser_Col2 = new ObRect();
	laser_Col2->scale = Vector2(224.0f * 2.0f, 51.0f) * 4.0f;
	laser_Col2->SetParentRT(*laser_Head2);
	//laser_Col2->SetWorldPos(Vector2(-100.0f - (10 * 224.0f / 7.0f * 4.0f), 2.0f));
	laser_Col2->pivot = OFFSET_R;
	laser_Col2->visible = false;
	laser_Col2->isFilled = false;
	laser_Col2->collider = COLLIDER::RECT;
	laser_Col2->colOnOff = false;

	//SWORD
	for (int i = 0; i < SMAX; i++)
	{
		swords[i] = new Sword;
	}

	for (int i = 0; i < SMAX; i++)
	{
		swords[i]->sword_Col = new ObRect();
		swords[i]->sword_Col->scale = Vector2(65.0f, 21.0f) * 4.0f;
		swords[i]->sword_Col->SetWorldPos(Vector2(-200.0f + (i * 100.0f), 250.0f + 168.0f / 8.0f));
		swords[i]->sword_Col->visible = false;
		swords[i]->sword_Col->isFilled = false;
		swords[i]->sword_Col->collider = COLLIDER::RECT;
		swords[i]->sword_Col->colOnOff = false;

		swords[i]->sword_Default = new ObImage(L"S_default.png");
		swords[i]->sword_Default->scale = Vector2(65.0f, 21.0f) * 4.0f;
		swords[i]->sword_Default->SetParentRT(*swords[i]->sword_Col);
		swords[i]->sword_Default->visible = false;

		swords[i]->sword_Shoot = new ObImage(L"S_shoot.png");
		swords[i]->sword_Shoot->scale = Vector2(70.0f, 21.0f) * 4.0f;
		swords[i]->sword_Shoot->SetParentRT(*swords[i]->sword_Col);
		swords[i]->sword_Shoot->visible = false;

		swords[i]->sword_Charge = new ObImage(L"S_charge.png");
		swords[i]->sword_Charge->scale = Vector2(65.0f, 168.0f / 8.0f) * 4.0f;
		swords[i]->sword_Charge->SetParentRT(*swords[i]->sword_Shoot);
		swords[i]->sword_Charge->maxFrame.y = 8.0f;
		swords[i]->sword_Charge->ChangeAnim(ANIMSTATE::LOOP, 0.1f, false);
		swords[i]->sword_Charge->visible = false;

		swords[i]->sword_Hit = new ObImage(L"S_hit.png");
		swords[i]->sword_Hit->scale = Vector2(110.0f / 5.0f, 51.0f) * 4.0f;
		swords[i]->sword_Hit->SetParentRT(*swords[i]->sword_Col);
		swords[i]->sword_Hit->maxFrame.x = 5.0f;
		swords[i]->sword_Hit->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		swords[i]->sword_Hit->visible = false;
	}

	//BALL
	for (int i = 0; i < BMAX; i++)
	{
		balls[i] = new Ball();
	}

	ball_Head = new ObImage(L"attack_Head.png");
	ball_Head->scale = Vector2(700.0f / 10.0f, 128.0f) * 4.0f;
	ball_Head->SetParentRT(*idle_Head);
	ball_Head->maxFrame.x = 10.0f;
	ball_Head->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	ball_Head->visible = false;

	ball_HeadShot = new ObImage(L"attack_shot.png");
	ball_HeadShot->scale = Vector2(700.0f / 10.0f, 128.0f) * 4.0f;
	ball_HeadShot->SetParentRT(*idle_Head);
	ball_HeadShot->maxFrame.x = 10.0f;
	ball_HeadShot->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	ball_HeadShot->visible = false;

	ball_Circle = new ObImage(L"circle.png");
	ball_Circle->scale = Vector2(500.0f / 10.0f, 50.0f) * 4.0f;
	ball_Circle->SetWorldPosX(10.0f);
	ball_Circle->maxFrame.x = 10.0f;
	ball_Circle->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	ball_Circle->visible = false;

	for (int i = 0; i < BMAX; i++)
	{
		balls[i]->ball_Col[0] = new ObCircle;
		balls[i]->ball_Col[0]->scale = Vector2(26.0f / 2.0f, 13.0f) * 4.0f;
		balls[i]->ball_Col[0]->SetWorldPos(Vector2(0.0f, 0.0f));
		balls[i]->ball_Col[0]->visible = false;
		balls[i]->ball_Col[0]->isFilled = false;
		balls[i]->ball_Col[0]->collider = COLLIDER::CIRCLE;

		balls[i]->ball_Col[1] = new ObCircle;
		balls[i]->ball_Col[1]->scale = Vector2(26.0f / 2.0f, 13.0f) * 4.0f;
		balls[i]->ball_Col[1]->SetWorldPos(Vector2(0.0f, 0.0f));
		balls[i]->ball_Col[1]->visible = false;
		balls[i]->ball_Col[1]->isFilled = false;
		balls[i]->ball_Col[1]->collider = COLLIDER::CIRCLE;

		balls[i]->ball_Col[2] = new ObCircle;
		balls[i]->ball_Col[2]->scale = Vector2(26.0f / 2.0f, 13.0f) * 4.0f;
		balls[i]->ball_Col[2]->SetWorldPos(Vector2(0.0f, 0.0f));
		balls[i]->ball_Col[2]->visible = false;
		balls[i]->ball_Col[2]->isFilled = false;
		balls[i]->ball_Col[2]->collider = COLLIDER::CIRCLE;

		balls[i]->ball_Col[3] = new ObCircle;
		balls[i]->ball_Col[3]->scale = Vector2(26.0f / 2.0f, 13.0f) * 4.0f;
		balls[i]->ball_Col[3]->SetWorldPos(Vector2(0.0f, 0.0f));
		balls[i]->ball_Col[3]->visible = false;
		balls[i]->ball_Col[3]->isFilled = false;
		balls[i]->ball_Col[3]->collider = COLLIDER::CIRCLE;

		balls[i]->ball[0] = new ObImage(L"bullet.png");
		balls[i]->ball[0]->scale = Vector2(26.0f / 2.0f, 13.0f) * 4.0f;
		balls[i]->ball[0]->SetParentRT(*balls[i]->ball_Col[0]);
		balls[i]->ball[0]->maxFrame.x = 2.0f;
		balls[i]->ball[0]->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		balls[i]->ball[0]->visible = false;
		balls[i]->ball[0]->colOnOff = false;

		balls[i]->ball[1] = new ObImage(L"bullet.png");
		balls[i]->ball[1]->scale = Vector2(26.0f / 2.0f, 13.0f) * 4.0f;
		balls[i]->ball[1]->SetParentRT(*balls[i]->ball_Col[1]);
		balls[i]->ball[1]->maxFrame.x = 2.0f;
		balls[i]->ball[1]->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		balls[i]->ball[1]->visible = false;
		balls[i]->ball[1]->colOnOff = false;

		balls[i]->ball[2] = new ObImage(L"bullet.png");
		balls[i]->ball[2]->scale = Vector2(26.0f / 2.0f, 13.0f) * 4.0f;
		balls[i]->ball[2]->SetParentRT(*balls[i]->ball_Col[2]);
		balls[i]->ball[2]->maxFrame.x = 2.0f;
		balls[i]->ball[2]->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		balls[i]->ball[2]->visible = false;
		balls[i]->ball[2]->colOnOff = false;

		balls[i]->ball[3] = new ObImage(L"bullet.png");
		balls[i]->ball[3]->scale = Vector2(26.0f / 2.0f, 13.0f) * 4.0f;
		balls[i]->ball[3]->SetParentRT(*balls[i]->ball_Col[3]);
		balls[i]->ball[3]->maxFrame.x = 2.0f;
		balls[i]->ball[3]->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		balls[i]->ball[3]->visible = false;
		balls[i]->ball[3]->colOnOff = false;

		ball_Fx = new ObImage(L"bullet_Fx.png");
		ball_Fx->scale = Vector2(248.0f / 8.0f, 31.0f) * 4.0f;
		ball_Fx->SetParentRT(*balls[i]->ball[0]);
		ball_Fx->maxFrame.x = 8.0f;
		ball_Fx->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		ball_Fx->visible = false;

	}

	ball_Particle = new ObImage(L"particle.png");
	ball_Particle->scale = Vector2(240.0f / 8.0f, 30.0f) * 9.0f;
	ball_Particle->SetParentRT(*ball_Circle);
	ball_Particle->maxFrame.x = 8.0f;
	ball_Particle->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	ball_Particle->visible = false;

	//DIE
	die_Head_Col = new ObRect();
	die_Head_Col->scale = Vector2(70.0f, 77.0f) * 3.0f;
	die_Head_Col->SetParentRT(*berial_Col);
	die_Head_Col->SetWorldPos(Vector2(0.0f, -100.0f));
	die_Head_Col->visible = false;
	die_Head_Col->isFilled = false;
	die_Head_Col->pivot = OFFSET_B;
	die_Head_Col->collider = COLLIDER::RECT;

	die_Head = new ObImage(L"head.png");
	die_Head->scale = Vector2(70.0f, 77.0f) * 4.0f;
	die_Head->SetParentRT(*die_Head_Col);
	die_Head->SetWorldPos(Vector2(-30.0f, 100.0f));
	die_Head->visible = false;

	die_Mouth_Col = new ObRect();
	die_Mouth_Col->scale = Vector2(49.0f, 31.0f) * 4.0f;
	die_Mouth_Col->SetParentRT(*berial_Col);
	die_Mouth_Col->SetWorldPos(Vector2(0.0f, -150.0f));
	die_Mouth_Col->visible = false;
	die_Mouth_Col->isFilled = false;
	die_Mouth_Col->pivot = OFFSET_B;
	die_Mouth_Col->collider = COLLIDER::RECT;

	die_Mouth = new ObImage(L"mouth.png");
	die_Mouth->scale = Vector2(49.0f, 31.0f) * 4.0f;
	die_Mouth->SetParentRT(*die_Mouth_Col);
	die_Mouth->SetWorldPos(Vector2(0.0f, 0.0f));
	die_Mouth->visible = false;

	for (int i = 0; i < 50; i++)
	{
		die_Effect[i] = new ObImage(L"Die.png");
		die_Effect[i]->scale = Vector2(550.0f / 11.0f, 50.0f) * 4.0f;
		die_Effect[i]->SetWorldPos(Vector2(0.0f, 0.0f));
		die_Effect[i]->maxFrame.x = 11.0f;
		die_Effect[i]->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		die_Effect[i]->visible = false;
	}

	boss_LifeBack = new ObImage(L"BossLifeBack.png");
	boss_LifeBack->scale = Vector2(125.0f, 16.0f) * 4.0f;
	boss_LifeBack->SetWorldPos(Vector2(-150.0f, -300.0f));
	boss_LifeBack->pivot = OFFSET_L;
	boss_LifeBack->visible = true;
	boss_LifeBack->space = SPACE::SCREEN;

	boss_LifeBase = new ObImage(L"BossLifeBase.png");
	boss_LifeBase->scale = Vector2(125.0f, 16.0f) * 4.0f;
	boss_LifeBase->pivot = OFFSET_L;
	boss_LifeBase->SetParentRT(*boss_LifeBack);
	boss_LifeBase->visible = true;
	boss_LifeBase->space = SPACE::SCREEN;

	boss_Icon = new ObImage(L"boss_icon.png");
	boss_Icon->scale = Vector2(86.0f, 61.0f) * 0.6f;
	boss_Icon->pivot = OFFSET_L;
	boss_Icon->SetParentRT(*boss_LifeBack);
	boss_Icon->SetWorldPosX(20.0f);
	boss_Icon->visible = true;
	boss_Icon->space = SPACE::SCREEN;

	boss_Life = new ObImage(L"LifeBar.png");
	boss_Life->scale = Vector2(100.0f, 10.0f) * 4.0f;
	boss_Life->pivot = OFFSET_L;
	boss_Life->SetParentRT(*boss_LifeBack);
	boss_Life->SetWorldPosX(90.0f);
	boss_Life->visible = true;
	boss_Life->space = SPACE::SCREEN;

	//플레이어
	player = new Player();

	SOUND->AddSound("iceball.wav", "Laser", false);
	SOUND->AddSound("slimeball.wav", "Sword", false);
	SOUND->AddSound("random5.wav", "Ball", false);
	SOUND->AddSound("random6.wav", "Ball", false);

	for (int i = 0; i < 4; i++)
	{
		balls[i]->ball[0]->visible = false;
		balls[i]->ball[1]->visible = false;
		balls[i]->ball[2]->visible = false;
		balls[i]->ball[3]->visible = false;
	}
}

Berial::~Berial()
{
	SafeDelete(idle_Head);
	SafeDelete(idle_Hand1);
	SafeDelete(idle_Hand2);
	SafeDelete(berial_Col);
	SafeDelete(idle_shot);
	SafeDelete(laser_Hand1);
	SafeDelete(laser_Hand2);
	SafeDelete(laser_Head1);
	SafeDelete(laser_Head2);
	SafeDelete(ball_Head);
	SafeDelete(ball_HeadShot);
	SafeDelete(ball_Circle);
	SafeDelete(ball_Fx);
	SafeDelete(ball_Particle);

	for (int i = 0; i < LMAX; i++)
	{
		SafeDelete(laser_Body1[i]);
		SafeDelete(laser_Body2[i]);
	}

	for (int i = 0; i < SMAX; i++)
	{
		SafeDelete(swords[i]->sword_Default);
		SafeDelete(swords[i]->sword_Charge);
		SafeDelete(swords[i]->sword_Hit);
		SafeDelete(swords[i]->sword_Shoot);
	}

	for (int i = 0; i < BMAX; i++)
	{
		SafeDelete(balls[i]);
	}
}

void Berial::Update()
{
	if (boss_Pattern == BOSSPATTERN::IDLE)
	{
		balls[ball_index]->ball[0]->colOnOff = false;
		balls[ball_index]->ball[1]->colOnOff = false;
		balls[ball_index]->ball[2]->colOnOff = false;
		balls[ball_index]->ball[3]->colOnOff = false;
		//보스 히트판정
		if (isDamaged)
		{
			damageTime -= DELTA;

			idle_Head->visible = false;
			idle_shot->visible = true;

			if (damageTime < 0.0f)
			{
				idle_Head->visible = true;
				idle_shot->visible = false;
				isDamaged = false;
			}
		}

		AllInvisible();

		idle_Hand1->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		idle_Head->visible = true;
		idle_Hand1->visible = true;
		idle_Hand2->visible = true;
		die_Head->visible = false;
		die_Mouth->visible = false;
		berial_Col->visible = false;
		
		laser_Col->colOnOff = false;
		laser_Col2->colOnOff = false;
		
		for (int i = 0; i < BMAX; i++)
		{
			balls[i]->ball[0]->colOnOff = false;
			balls[i]->ball[1]->colOnOff = false;
			balls[i]->ball[2]->colOnOff = false;
			balls[i]->ball[3]->colOnOff = false;
		}

		for (int i = 0; i < SMAX; i++)
		{
			swords[i]->sword_Col->colOnOff = false;
		}

		//IDLE -> LLASER
		if (INPUT->KeyDown('1'))
		{
			cout << "왼쪽 LASER" << endl;
			boss_Pattern = BOSSPATTERN::LLASER;
			idle_Hand1->visible = false;
			laser_Hand1->visible = true;

			laser_Hand1->ChangeAnim(ANIMSTATE::ONCE, 0.1f);

		}

		//IDLE -> RLASER
		if (INPUT->KeyDown('2'))
		{
			cout << "오른쪽 LASER" << endl;
			boss_Pattern = BOSSPATTERN::RLASER;
			idle_Hand2->visible = false;
			laser_Hand2->visible = true;

			laser_Hand2->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
		}

		//IDLE -> SWORD
		if (INPUT->KeyDown('3'))
		{
			cout << "SWORD" << endl;
			boss_Pattern = BOSSPATTERN::SWORD;

			for (int i = 0; i < SMAX; i++)
			{
				swords[sword_index]->sword_Charge->ChangeAnim(ANIMSTATE::ONCE, 0.08f, false);
			}
		}

		//IDLE -> BALL
		if (INPUT->KeyDown('4'))
		{
			cout << "BALL" << endl;
			boss_Pattern = BOSSPATTERN::BALL;
			idle_Head->visible = false;
			ball_Head->visible = true;
			ball_Circle->visible = true;
			ball_Particle->visible = true;
		
			//공 발사
			for (int i = 0; i < BMAX; i++)
			{
				ball_Circle->rotation += 6.0f * ToRadian;
				ball_Circle->Update();
				balls[i]->fireDir[0] = ball_Circle->GetRight();
				balls[i]->fireDir[1] = ball_Circle->GetUp();
				balls[i]->fireDir[2] = ball_Circle->GetRight();
				balls[i]->fireDir[3] = ball_Circle->GetUp();
			}

			ball_Head->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			ball_HeadShot->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
		}

		//IDLE -> DIE
		if (boss_HP == 0.0f)
		{
			boss_Pattern = BOSSPATTERN::DIE;

			for (int i = 0; i < 50; i++)
			{
				die_Effect[i]->visible = true;
				die_Effect[i]->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			}
		}
	}

	else if (boss_Pattern == BOSSPATTERN::LLASER)
	{
		//보스 히트판정
		if (isDamaged)
		{
			damageTime -= DELTA;

			idle_Head->visible = false;
			idle_shot->visible = true;

			if (damageTime < 0.0f)
			{
				idle_Head->visible = true;
				idle_shot->visible = false;
				isDamaged = false;
			}

		}

		//LLASER -> IDLE
		for (int i = 0; i < LMAX; i++)
		{
			if (laser_Hand1->frame.x == 9.0f)
			{
				SOUND->Play("Laser");
				laser_Head1->visible = true;
				laser_Body1[i]->visible = true;
				laser_Col->visible = false;
				laser_Col->colOnOff = true;
				

				laser_Head1->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
				laser_Body1[i]->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			}

			if (laser_Body1[i]->frame.x == 6.0f)
			{
				boss_Pattern = BOSSPATTERN::IDLE;
				laser_Hand1->visible = false;
				laser_Head1->visible = false;
				laser_Body1[i]->visible = false;
				laser_Col->visible = true;

				idle_Hand1->visible = true;
				laser_Hand1->visible = false;

				laser_Hand1->frame.x = 0;
				laser_Head1->frame.x = 0;
				laser_Body1[i]->frame.x = 0;
			}
		}

		//LLASER -> DIE
		if (boss_HP == 0.0f)
		{
			boss_Pattern = BOSSPATTERN::DIE;

			for (int i = 0; i < 50; i++)
			{
				die_Effect[i]->visible = true;
				die_Effect[i]->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			}
		}
	}

	else if (boss_Pattern == BOSSPATTERN::RLASER)
	{
		//보스 히트판정
		if (isDamaged)
		{
			damageTime -= DELTA;

			idle_Head->visible = false;
			idle_shot->visible = true;

			if (damageTime < 0.0f)
			{
				idle_Head->visible = true;
				idle_shot->visible = false;
				isDamaged = false;
			}
		}

		//RLASER -> IDLE
		for (int i = 0; i < LMAX; i++)
		{
			if (laser_Hand2->frame.x == 9.0f)
			{
				SOUND->Play("Laser");
				laser_Head2->visible = true;
				laser_Body2[i]->visible = true;
				laser_Col2->visible = false;
				laser_Col2->colOnOff = true;

				laser_Head2->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
				laser_Body2[i]->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			}

			if (laser_Body2[i]->frame.x == 6.0f)
			{
				boss_Pattern = BOSSPATTERN::IDLE;
				laser_Hand2->visible = false;
				laser_Head2->visible = false;
				laser_Body2[i]->visible = false;
				laser_Col2->visible = true;

				idle_Hand2->visible = true;
				laser_Hand2->visible = false;

				laser_Hand2->frame.x = 0;
				laser_Head2->frame.x = 0;
				laser_Body2[i]->frame.x = 0;
			}
		}

		//RLASER -> DIE
		if (boss_HP == 0.0f)
		{
			boss_Pattern = BOSSPATTERN::DIE;

			for (int i = 0; i < 50; i++)
			{
				die_Effect[i]->visible = true;
				die_Effect[i]->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			}
		}
	}

	else if (boss_Pattern == BOSSPATTERN::SWORD)
	{
		//보스 히트판정
		if (isDamaged)
		{
			damageTime -= DELTA;

			idle_Head->visible = false;
			idle_shot->visible = true;

			if (damageTime < 0.0f)
			{
				idle_Head->visible = true;
				idle_shot->visible = false;
				isDamaged = false;
			}

		}
	
		//SWORD -> IDLE
		if (TIMER->GetTick(sword_Timer, sword_Interval))
		{
			swords[sword_index]->sword_Default->visible = true;
			swords[sword_index]->sword_Charge->visible = true;
			//swords[sword_index]->sword_Col->visible = true;
			swords[sword_index]->sword_Col->colOnOff = true;

			sword_index++;

			if (sword_index == sword_Num)
			{
				sword_index = 0;
			}
		}

		if (swords[5]->sword_Default->visible)
		{
			if (TIMER->GetTick(shoot_Timer, shoot_Interval))
			{
				SOUND->Stop("Sword");
				SOUND->Play("Sword");
				swords[shoot_index]->sword_Default->visible = false;
				swords[shoot_index]->sword_Charge->visible = false;
				swords[shoot_index]->sword_Shoot->visible = true;

				shoot_index++;

				if (shoot_index == shoot_Num)
				{
					shoot_index = 0;
				}
			}
		}

		//SWORD -> DIE
		if (boss_HP == 0.0f)
		{
			boss_Pattern = BOSSPATTERN::DIE;

			for (int i = 0; i < 50; i++)
			{
				die_Effect[i]->visible = true;
				die_Effect[i]->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			}
		}
	}

	else if (boss_Pattern == BOSSPATTERN::BALL)
	{
		//보스 히트판정
		if (isDamaged)
		{
			damageTime -= DELTA;

			ball_Head->visible = false;
			ball_HeadShot->visible = true;

			if (damageTime < 0.0f)
			{
				ball_Head->visible = true;
				ball_HeadShot->visible = false;
				isDamaged = false;
			}
		}

		//BALL -> IDLE
		if (TIMER->GetTick(ball_Timer, ball_Interval))
		{
			if (ball_index < ball_Num)
			{
				SOUND->Stop("Ball");
				SOUND->Play("Ball");

				//balls[ball_index]->ball_Col[0]->visible = true;
				balls[ball_index]->ball_Col[0]->SetWorldPos(Vector2(0.0f, 0.0f));
				balls[ball_index]->ball[0]->visible = true;
				//balls[ball_index]->ball[0]->colOnOff = true;

				//balls[ball_index]->ball_Col[1]->visible = true;
				balls[ball_index]->ball_Col[1]->SetWorldPos(Vector2(0.0f, 0.0f));
				balls[ball_index]->ball[1]->visible = true;
				//balls[ball_index]->ball[1]->colOnOff = true;

				//balls[ball_index]->ball_Col[2]->visible = true;
				balls[ball_index]->ball_Col[2]->SetWorldPos(Vector2(0.0f, 0.0f));
				balls[ball_index]->ball[2]->visible = true;
				//balls[ball_index]->ball[2]->colOnOff = true;

				//balls[ball_index]->ball_Col[3]->visible = true;
				balls[ball_index]->ball_Col[3]->SetWorldPos(Vector2(0.0f, 0.0f));
				balls[ball_index]->ball[3]->visible = true;
				//balls[ball_index]->ball[3]->colOnOff = true;

				ball_index++;
			}
		}

		for (int i = 0; i < BMAX; i++)
		{
			balls[i]->ball_Col[0]->MoveWorldPos(balls[i]->fireDir[0] * 200.0f * DELTA);
			balls[i]->ball_Col[1]->MoveWorldPos(balls[i]->fireDir[1] * 200.0f * DELTA);
			balls[i]->ball_Col[2]->MoveWorldPos(balls[i]->fireDir[2] * -200.0f * DELTA);
			balls[i]->ball_Col[3]->MoveWorldPos(balls[i]->fireDir[3] * -200.0f * DELTA);
		}

		//공 위치
		for (int i = 0; i < BMAX; i++)
		{
			Vector2 ball_Dir = balls[i]->ball[0]->GetWorldPos() - idle_Head->GetWorldPos();
			float b_distance = ball_Dir.Length();

			if (b_distance > 3000)
			{
				//boss_Pattern = BOSSPATTERN::IDLE;
				cout << "Reset" << endl;
				Reset();
			}
		}

		//BALL -> DIE
		if (boss_HP == 0.0f)
		{
			boss_Pattern = BOSSPATTERN::DIE;

			for (int i = 0; i < 50; i++)
			{
				die_Effect[i]->visible = true;
				die_Effect[i]->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			}
		}
	}

	else if (boss_Pattern == BOSSPATTERN::DIE)
	{
		AllInvisible();

		for (int i = 0; i < 50; i++)
		{
			die_Effect[i]->visible = true;
		}

		die_Head->visible = true;
		die_Mouth->visible = true;
		berial_Col->colOnOff = false;

		die_Head_Col->MoveWorldPos(DOWN * dh_scalar * DELTA);
		die_Mouth_Col->MoveWorldPos(DOWN * dm_scalar * DELTA);
	}

	//IDLE로 상태 바꾸기
	if (INPUT->KeyDown('5'))
	{
		cout << "IDLE" << endl;

		Reset();

		AllInvisible();

		idle_Head->visible = true;
		idle_Hand1->visible = true;
		idle_Hand2->visible = true;
	}

	//DIE로 바꾸기
	if (INPUT->KeyDown('6'))
	{
		AllInvisible();

		cout << "DIE" << endl;

		for (int i = 0; i < 50; i++)
		{
			die_Effect[i]->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
		}
		
		boss_Pattern = BOSSPATTERN::DIE;

	}

	idle_Head->Update();
	idle_Hand1->Update();
	idle_Hand2->Update();
	berial_Col->Update();
	idle_shot->Update();
	laser_Hand1->Update();
	laser_Hand2->Update();
	laser_Head1->Update();
	laser_Head2->Update();

	for (int i = 0; i < LMAX; i++)
	{
		laser_Body1[i]->Update();
		laser_Body2[i]->Update();
	}

	laser_Col->Update();
	laser_Col2->Update();

	for (int i = 0; i < SMAX; i++)
	{
		swords[i]->sword_Default->Update();
		swords[i]->sword_Charge->Update();
		swords[i]->sword_Hit->Update();
		swords[i]->sword_Shoot->Update();
		swords[i]->sword_Col->Update();
	}

	for (int i = 0; i < BMAX; i++)
	{
		balls[i]->ball[0]->Update();
		balls[i]->ball[1]->Update();
		balls[i]->ball[2]->Update();
		balls[i]->ball[3]->Update();

		balls[i]->ball_Col[0]->Update();
		balls[i]->ball_Col[1]->Update();
		balls[i]->ball_Col[2]->Update();
		balls[i]->ball_Col[3]->Update();
	}

	ball_Head->Update();
	ball_HeadShot->Update();
	ball_Circle->Update();
	ball_Fx->Update();
	ball_Particle->Update();
	player->Update();
	die_Head->Update();
	die_Mouth->Update();
	die_Head_Col->Update();
	die_Mouth_Col->Update();
	boss_LifeBack->Update();
	boss_LifeBase->Update();
	boss_Icon->Update();
	boss_Life->Update();

	for (int i = 0; i < 50; i++)
	{
		die_Effect[i]->Update();
	}
}

void Berial::Render()
{
	//player->Render();
	idle_Head->Render();
	idle_Hand1->Render();
	idle_Hand2->Render();
	berial_Col->Render();
	idle_shot->Render();
	laser_Hand1->Render();
	laser_Hand2->Render();
	laser_Head1->Render();
	laser_Head2->Render();

	for (int i = 0; i < LMAX; i++)
	{
		laser_Body1[i]->Render();
		laser_Body2[i]->Render();
	}

	laser_Col->Render();
	laser_Col2->Render();

	for (int i = 0; i < SMAX; i++)
	{
		swords[i]->sword_Default->Render();
		swords[i]->sword_Charge->Render();
		swords[i]->sword_Hit->Render();
		swords[i]->sword_Shoot->Render();
		swords[i]->sword_Col->Render();
	}

	ball_Particle->Render();
	ball_Circle->Render();
	ball_HeadShot->Render();
	ball_Head->Render();

	for (int i = 0; i < BMAX; i++)
	{
		balls[i]->ball[0]->Render();
		balls[i]->ball[1]->Render();
		balls[i]->ball[2]->Render();
		balls[i]->ball[3]->Render();

		balls[i]->ball_Col[0]->Render();
		balls[i]->ball_Col[1]->Render();
		balls[i]->ball_Col[2]->Render();
		balls[i]->ball_Col[3]->Render();
	}

	ball_Fx->Render();

	die_Mouth->Render();
	die_Head->Render();
	die_Mouth_Col->Render();
	die_Head_Col->Render();

	for (int i = 0; i < 50; i++)
	{
		die_Effect[i]->Render();
	}

	boss_LifeBack->Render();
	boss_LifeBase->Render();
	boss_Icon->Render();
	boss_Life->Render();
}

void Berial::Reset()
{
	boss_Pattern = BOSSPATTERN::IDLE;

	ball_index = 0;
	sword_index = 0;
	shoot_index = 0;

	//보스 피격판정
	berial_Col->scale = Vector2(700.0f / 10.0f, 96.0f) * 3.0f;
	berial_Col->SetWorldPos(Vector2(10.0f, 75.0f));
	berial_Col->isFilled = false;
	berial_Col->visible = false;
	berial_Col->collider = COLLIDER::RECT;

	//IDLE
	idle_Head->scale = Vector2(700.0f / 10.0f, 96.0f) * 4.0f;
	idle_Head->SetWorldPos(Vector2(-20.0f, 100.0f));
	idle_Head->maxFrame.x = 10.0f;
	idle_Head->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

	//피격 시 이미지 전환
	idle_shot->scale = Vector2(700.0f / 10.0f, 96.0f) * 4.0f;
	idle_shot->SetParentRT(*idle_Head);
	idle_shot->maxFrame.x = 10.0f;
	idle_shot->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	idle_shot->visible = false;

	for (int i = 0; i < SMAX; i++)
	{
		swords[i]->sword_Col->scale = Vector2(65.0f, 21.0f) * 4.0f;
		swords[i]->sword_Col->SetWorldPos(Vector2(-200.0f + (i * 100.0f), 250.0f + 168.0f / 8.0f));
		swords[i]->sword_Col->visible = false;
		swords[i]->sword_Col->isFilled = false;
		swords[i]->sword_Col->collider = COLLIDER::RECT;

		swords[i]->sword_Default->scale = Vector2(65.0f, 21.0f) * 4.0f;
		swords[i]->sword_Default->SetParentRT(*swords[i]->sword_Col);
		swords[i]->sword_Default->visible = false;

		swords[i]->sword_Shoot->scale = Vector2(70.0f, 21.0f) * 4.0f;
		swords[i]->sword_Shoot->SetParentRT(*swords[i]->sword_Col);
		swords[i]->sword_Shoot->visible = false;

		swords[i]->sword_Charge->scale = Vector2(65.0f, 168.0f / 8.0f) * 4.0f;
		swords[i]->sword_Charge->SetParentRT(*swords[i]->sword_Shoot);
		swords[i]->sword_Charge->maxFrame.y = 8.0f;
		swords[i]->sword_Charge->ChangeAnim(ANIMSTATE::LOOP, 0.1f, false);
		swords[i]->sword_Charge->visible = false;

		swords[i]->sword_Hit->scale = Vector2(110.0f / 5.0f, 51.0f) * 4.0f;
		swords[i]->sword_Hit->SetParentRT(*swords[i]->sword_Col);
		swords[i]->sword_Hit->maxFrame.x = 5.0f;
		swords[i]->sword_Hit->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		swords[i]->sword_Hit->visible = false;
	}

	ball_Head->scale = Vector2(700.0f / 10.0f, 128.0f) * 4.0f;
	ball_Head->SetParentRT(*idle_Head);
	ball_Head->maxFrame.x = 10.0f;
	ball_Head->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	ball_Head->visible = false;

	ball_HeadShot->scale = Vector2(700.0f / 10.0f, 128.0f) * 4.0f;
	ball_HeadShot->SetParentRT(*idle_Head);
	ball_HeadShot->maxFrame.x = 10.0f;
	ball_HeadShot->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	ball_HeadShot->visible = false;

	ball_Circle->scale = Vector2(500.0f / 10.0f, 50.0f) * 4.0f;
	ball_Circle->SetWorldPosX(10.0f);
	ball_Circle->maxFrame.x = 10.0f;
	ball_Circle->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	ball_Circle->visible = false;

	for (int i = 0; i < BMAX; i++)
	{
		balls[i]->ball_Col[0]->scale = Vector2(26.0f / 2.0f, 13.0f) * 4.0f;
		balls[i]->ball_Col[0]->SetWorldPos(Vector2(0.0f, 0.0f));
		balls[i]->ball_Col[0]->visible = false;
		balls[i]->ball_Col[0]->isFilled = false;

		balls[i]->ball_Col[1]->scale = Vector2(26.0f / 2.0f, 13.0f) * 4.0f;
		balls[i]->ball_Col[1]->SetWorldPos(Vector2(0.0f, 0.0f));
		balls[i]->ball_Col[1]->visible = false;
		balls[i]->ball_Col[1]->isFilled = false;

		balls[i]->ball_Col[2]->scale = Vector2(26.0f / 2.0f, 13.0f) * 4.0f;
		balls[i]->ball_Col[2]->SetWorldPos(Vector2(0.0f, 0.0f));
		balls[i]->ball_Col[2]->visible = false;
		balls[i]->ball_Col[2]->isFilled = false;

		balls[i]->ball_Col[3]->scale = Vector2(26.0f / 2.0f, 13.0f) * 4.0f;
		balls[i]->ball_Col[3]->SetWorldPos(Vector2(0.0f, 0.0f));
		balls[i]->ball_Col[3]->visible = false;
		balls[i]->ball_Col[3]->isFilled = false;

		balls[i]->ball[0]->scale = Vector2(26.0f / 2.0f, 13.0f) * 4.0f;
		balls[i]->ball[0]->SetParentRT(*balls[i]->ball_Col[0]);
		balls[i]->ball[0]->maxFrame.x = 2.0f;
		balls[i]->ball[0]->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		balls[i]->ball[0]->visible = false;

		balls[i]->ball[1]->scale = Vector2(26.0f / 2.0f, 13.0f) * 4.0f;
		balls[i]->ball[1]->SetParentRT(*balls[i]->ball_Col[1]);
		balls[i]->ball[1]->maxFrame.x = 2.0f;
		balls[i]->ball[1]->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		balls[i]->ball[1]->visible = false;

		balls[i]->ball[2]->scale = Vector2(26.0f / 2.0f, 13.0f) * 4.0f;
		balls[i]->ball[2]->SetParentRT(*balls[i]->ball_Col[2]);
		balls[i]->ball[2]->maxFrame.x = 2.0f;
		balls[i]->ball[2]->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		balls[i]->ball[2]->visible = false;

		balls[i]->ball[3]->scale = Vector2(26.0f / 2.0f, 13.0f) * 4.0f;
		balls[i]->ball[3]->SetParentRT(*balls[i]->ball_Col[3]);
		balls[i]->ball[3]->maxFrame.x = 2.0f;
		balls[i]->ball[3]->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		balls[i]->ball[3]->visible = false;

		ball_Fx->scale = Vector2(248.0f / 8.0f, 31.0f) * 4.0f;
		ball_Fx->SetParentRT(*balls[i]->ball[0]);
		ball_Fx->maxFrame.x = 8.0f;
		ball_Fx->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		ball_Fx->visible = false;

	}

	ball_Particle->scale = Vector2(240.0f / 8.0f, 30.0f) * 9.0f;
	ball_Particle->SetParentRT(*ball_Circle);
	ball_Particle->maxFrame.x = 8.0f;
	ball_Particle->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	ball_Particle->visible = false;

	//DIE
	die_Head_Col = new ObRect();
	die_Head_Col->scale = Vector2(70.0f, 77.0f) * 3.0f;
	die_Head_Col->SetParentRT(*berial_Col);
	die_Head_Col->SetWorldPos(Vector2(0.0f, -100.0f));
	die_Head_Col->visible = false;
	die_Head_Col->isFilled = false;
	die_Head_Col->pivot = OFFSET_B;
	die_Head_Col->collider = COLLIDER::RECT;

	die_Head->scale = Vector2(70.0f, 77.0f) * 4.0f;
	die_Head->SetParentRT(*die_Head_Col);
	die_Head->SetWorldPos(Vector2(-30.0f, 100.0f));
	die_Head->visible = false;

	die_Mouth_Col = new ObRect();
	die_Mouth_Col->scale = Vector2(49.0f, 31.0f) * 4.0f;
	die_Mouth_Col->SetParentRT(*berial_Col);
	die_Mouth_Col->SetWorldPos(Vector2(0.0f, -150.0f));
	die_Mouth_Col->visible = false;
	die_Mouth_Col->isFilled = false;
	die_Mouth_Col->pivot = OFFSET_B;
	die_Mouth_Col->collider = COLLIDER::RECT;

	die_Mouth->scale = Vector2(49.0f, 31.0f) * 4.0f;
	die_Mouth->SetParentRT(*die_Mouth_Col);
	die_Mouth->SetWorldPos(Vector2(0.0f, 0.0f));
	die_Mouth->visible = false;

	for (int i = 0; i < 50; i++)
	{
		die_Effect[i]->scale = Vector2(550.0f / 11.0f, 50.0f) * 4.0f;
		die_Effect[i]->SetWorldPos(Vector2(0.0f, 0.0f));
		die_Effect[i]->maxFrame.x = 11.0f;
		die_Effect[i]->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		die_Effect[i]->visible = false;
	}
}


