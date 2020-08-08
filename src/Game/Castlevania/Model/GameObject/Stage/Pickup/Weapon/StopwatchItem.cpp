#include "StopwatchItem.h"

StopwatchItem::StopwatchItem(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\PickUp\\Weapon\\StopwatchItem.xml";
}

StopwatchItem::~StopwatchItem()
{
	playScene = nullptr;
}

void StopwatchItem::Load()
{
	GameObject::Load();
}

void StopwatchItem::Unload()
{
	GameObject::Unload();
}

void StopwatchItem::Start()
{
	start = true;
}

void StopwatchItem::Update(float elapsedMs)
{
	if (!start)	Start();
}

void StopwatchItem::Render()
{
	GetSpriteRenderer()->Render("stopwatchItem");
}

void StopwatchItem::Collided(pCollision& collision)
{
}

void StopwatchItem::SpawnedHandler(pGameObject gameObject)
{
}

void StopwatchItem::DestroyedHandler(pGameObject gameObject)
{
}
