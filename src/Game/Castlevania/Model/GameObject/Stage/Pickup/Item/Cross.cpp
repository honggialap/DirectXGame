#include "Cross.h"

Cross::Cross(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\PickUp\\Item\\Cross.xml";
}

Cross::~Cross()
{
	playScene = nullptr;
}

void Cross::Load()
{
	GameObject::Load();
}

void Cross::Unload()
{
	GameObject::Unload();
}

void Cross::Start()
{
	start = true;
}

void Cross::Update(float elapsedMs)
{
	if (!start)	Start();
}

void Cross::Render()
{
	GetSpriteRenderer()->Render("cross");
}

void Cross::Collided(pCollision& collision)
{
}

void Cross::SpawnedHandler(pGameObject gameObject)
{
}

void Cross::DestroyedHandler(pGameObject gameObject)
{
}
