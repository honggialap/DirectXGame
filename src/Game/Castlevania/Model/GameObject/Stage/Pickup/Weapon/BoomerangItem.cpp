#include "BoomerangItem.h"

BoomerangItem::BoomerangItem(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\PickUp\\Weapon\\BoomerangItem.xml";
}

BoomerangItem::~BoomerangItem()
{
	playScene = nullptr;
}

void BoomerangItem::Load()
{
	GameObject::Load();
}

void BoomerangItem::Unload()
{
	GameObject::Unload();
}

void BoomerangItem::Start()
{
	start = true;
}

void BoomerangItem::Update(float elapsedMs)
{
	if (!start)	Start();
}

void BoomerangItem::Render()
{
	GetSpriteRenderer()->Render("boomerangItem");
}

void BoomerangItem::Collided(pCollision& collision)
{
}

void BoomerangItem::SpawnedHandler(pGameObject gameObject)
{
}

void BoomerangItem::DestroyedHandler(pGameObject gameObject)
{
}
