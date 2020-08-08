#include "Title_Label.h"

Title_Label::Title_Label(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Title\\Title_Label.xml";
}

Title_Label::~Title_Label()
{
	playScene = nullptr;
}

void Title_Label::Load()
{
	GameObject::Load();
}

void Title_Label::Unload()
{
	GameObject::Unload();
}

void Title_Label::Start()
{
	start = true;
	SetState(State::Begin);
}

void Title_Label::Update(float elapsedMs)
{
	if (!start) Start();
	GetAnimator()->Update(elapsedMs);
}

void Title_Label::Render()
{
	GetAnimator()->Render();
}

void Title_Label::Collided(pCollision& collision)
{
}

void Title_Label::SpawnedHandler(pGameObject gameObject)
{
}

void Title_Label::DestroyedHandler(pGameObject gameObject)
{
}

void Title_Label::SetState(State state)
{
	this->state = state;
	switch (state)
	{
	case State::Begin:
		GetAnimator()->Play("idle");
		break;

	case State::StartGame:
		GetAnimator()->Play("blink", true);
		break;
	}
}
