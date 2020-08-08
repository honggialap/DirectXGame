#include "Intro_Bat1.h"

Intro_Bat1::Intro_Bat1(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Intro\\Intro_Bat.xml";
}

Intro_Bat1::~Intro_Bat1()
{
}

void Intro_Bat1::Load()
{
	GameObject::Load();
}

void Intro_Bat1::Unload()
{
	GameObject::Unload();
}

void Intro_Bat1::Start()
{
	start = true;
	GetAnimator()->Play("0", true);
}

void Intro_Bat1::Update(float elapsedMs)
{
	if (!start) Start();
	x += defaultSpeed * elapsedMs;
	y += 0.5 * defaultSpeed * elapsedMs;
	GetAnimator()->Update(elapsedMs);
}

void Intro_Bat1::Render()
{
	GetAnimator()->Render();
}

void Intro_Bat1::Collided(pCollision& collision)
{
}

void Intro_Bat1::SpawnedHandler(pGameObject gameObject)
{
}

void Intro_Bat1::DestroyedHandler(pGameObject gameObject)
{
}