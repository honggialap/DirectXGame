#include "Intro.h"

Intro::Intro(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Intro\\Intro.xml";
}

Intro::~Intro()
{
}

void Intro::Load()
{
	GameObject::Load();
}

void Intro::Unload()
{

	GameObject::Unload();
}

void Intro::Start()
{
	start = true;
	introTimer = 6000;
}

void Intro::Update(float elapsedMs)
{
	if (!start) Start();
	if (introTimer > 0) introTimer -= elapsedMs;
	else scene->SwitchScene("title");
}

void Intro::Render()
{
}

void Intro::Collided(pCollision& collision)
{
}

void Intro::SpawnedHandler(pGameObject gameObject)
{
}

void Intro::DestroyedHandler(pGameObject gameObject)
{
}
