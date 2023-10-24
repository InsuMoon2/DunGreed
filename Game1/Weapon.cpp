#include "stdafx.h"

Weapon::Weapon()
{
	sword = new ObImage(L"CosmosSwordIcon.png");
	sword->scale = Vector2(33.0f, 11.0f) * 4.0f;
}

Weapon::~Weapon()
{
	SafeDelete(sword);
}

void Weapon::Update()
{
	sword->Update();
}

void Weapon::Render()
{
	sword->Render();
}
