#include "Title_Bat.h"

Title_Bat::Title_Bat(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Title\\Title_Bat.xml";
}

Title_Bat::~Title_Bat()
{
}

void Title_Bat::Load()
{
	GameObject::Load();
}

void Title_Bat::Unload()
{
	GameObject::Unload();
}

void Title_Bat::Start()
{
	start = true;
	SetState(State::Begin);
}

void Title_Bat::Update(float elapsedMs)
{
	if (!start) Start();
	switch (state)
	{
	case State::Begin:
		countdown -= elapsedMs;
		if (countdown <= 0) SetState(State::Loop);
		break;
	}
	GetAnimator()->Update(elapsedMs);
}

void Title_Bat::Render()
{
	GetAnimator()->Render();
}

void Title_Bat::Collided(pCollision& collision)
{
}

void Title_Bat::SpawnedHandler(pGameObject gameObject)
{
}

void Title_Bat::DestroyedHandler(pGameObject gameObject)
{
}

void Title_Bat::SetState(State state)
{
	this->state = state;
	switch (state)
	{
	case State::Begin:
		countdown = 3200;
		GetAnimator()->Play("begin");
		break;

	case State::Loop:
		GetAnimator()->Play("loop", true);
		break;

	case State::Pause:
		GetAnimator()->Pause();
		break;
	}
}
