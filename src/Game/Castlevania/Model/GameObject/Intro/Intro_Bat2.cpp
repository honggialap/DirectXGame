#include "Intro_Bat2.h"

Intro_Bat2::Intro_Bat2(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Intro\\Intro_Bat.xml";
}

Intro_Bat2::~Intro_Bat2()
{
}

void Intro_Bat2::Load()
{
	GameObject::Load();
}

void Intro_Bat2::Unload()
{
	GameObject::Unload();
}

void Intro_Bat2::Start()
{
	start = true;
	GetAnimator()->Play("0", true);

	initial = true;
	vx = -0.7;
	vy = -0.7;
	g = 0.01;
	defaultSpeed = 0.1;
}

void Intro_Bat2::Update(float elapsedMs)
{
	if (!start) Start();
	if (initial)
	{
		maxY = y;
		initial = false;
	}
	if (y <= maxY)
	{
		vy += g;
	}
	else
	{
		vx = 0.0f;
		vy = 0.0f;
	}

	x += vx * elapsedMs * defaultSpeed;
	y += vy * elapsedMs * defaultSpeed;

	GetAnimator()->Update(elapsedMs);
}

void Intro_Bat2::Render()
{
	GetAnimator()->Render();
}

void Intro_Bat2::Collided(pCollision& collision)
{
}

void Intro_Bat2::SpawnedHandler(pGameObject gameObject)
{
}

void Intro_Bat2::DestroyedHandler(pGameObject gameObject)
{
}