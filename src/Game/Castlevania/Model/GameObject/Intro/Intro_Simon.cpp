#include "Intro_Simon.h"

Intro_Simon::Intro_Simon(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Intro\\Intro_Simon.xml";
}

Intro_Simon::~Intro_Simon()
{
}

void Intro_Simon::Load()
{
	GameObject::Load();
}

void Intro_Simon::Unload()
{
	GameObject::Unload();
}

void Intro_Simon::Start()
{
	start = true;
	SetState(Walk);
}

void Intro_Simon::Update(float elapsedMs)
{
	if (!start) Start();

	switch (state)
	{
	case Walk:
		countdown -= elapsedMs;
		if (countdown <= 0) SetState(Intro);
		break;
	}

	x += -defaultSpeed * elapsedMs;

	GetAnimator()->Update(elapsedMs);
}

void Intro_Simon::Render()
{
	GetAnimator()->Render();
}

void Intro_Simon::Collided(pCollision& collision)
{
}

void Intro_Simon::SpawnedHandler(pGameObject gameObject)
{
}

void Intro_Simon::DestroyedHandler(pGameObject gameObject)
{
}

void Intro_Simon::SetState(State state)
{
	state = state;
	switch (state)
	{
	case Walk:
		GetAnimator()->Play("walk", true);
		countdown = 5000;
		defaultSpeed = 0.115;
		break;
	case Intro:
		GetAnimator()->Play("intro");
		defaultSpeed = 0;
		break;
	default:
		break;
	}
}

