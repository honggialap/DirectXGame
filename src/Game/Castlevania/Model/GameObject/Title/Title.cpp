#include "Title.h"

Title::Title(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	controller = dynamic_cast<pLocalPlayer>(playScene->players[0])->controller;
	source = "Castlevania\\Data\\GameObject\\Title\\Title.xml";
}

Title::~Title()
{
	playScene = nullptr;
	controller = nullptr;
}

void Title::Load()
{
	GameObject::Load();
}

void Title::Unload()
{
	GameObject::Unload();
}

void Title::Start()
{
	start = true;
	SetState(State::Begin);
}

void Title::Update(float elapsedMs)
{
	if (!start) Start();

	switch (state)
	{
	case State::Begin:
		if (controller->IsButtonPressed(Controller::Start))
			SetState(State::StartGame);
		break;

	case State::StartGame:
		if (titleTimer > 0) titleTimer -= elapsedMs;
		else scene->SwitchScene("intro");
		break;
	}
}

void Title::Render()
{
}

void Title::Collided(pCollision& collision)
{
}

void Title::SpawnedHandler(pGameObject gameObject)
{
	if (dynamic_cast<pTitle_Label>(gameObject))
		label = dynamic_cast<pTitle_Label>(gameObject);
	else if (dynamic_cast<pTitle_Bat>(gameObject))
		bat = dynamic_cast<pTitle_Bat>(gameObject);
}

void Title::DestroyedHandler(pGameObject gameObject)
{
	if (label == gameObject) label = nullptr;
	else if (bat == gameObject) bat = nullptr;
}

void Title::SetState(State state)
{
	this->state = state;
	switch (state)
	{
	case State::Begin:
		break;

	case State::StartGame:
		bat->SetState(Title_Bat::State::Pause);
		label->SetState(Title_Label::State::StartGame);
		titleTimer = 1750;
		break;
	}
}
