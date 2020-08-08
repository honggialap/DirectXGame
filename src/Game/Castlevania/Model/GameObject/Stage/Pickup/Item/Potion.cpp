#include "Potion.h"

Potion::Potion(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\PickUp\\Item\\Potion.xml";
}

Potion::~Potion()
{
	playScene = nullptr;
}

void Potion::Load()
{
	GameObject::Load();
}

void Potion::Unload()
{
	GameObject::Unload();
}

void Potion::Start()
{
	start = true;
}

void Potion::Update(float elapsedMs)
{
	if (!start)	Start();
}

void Potion::Render()
{
	GetSpriteRenderer()->Render("potion");
}

void Potion::Collided(pCollision& collision)
{
}

void Potion::SpawnedHandler(pGameObject gameObject)
{
}

void Potion::DestroyedHandler(pGameObject gameObject)
{
}
