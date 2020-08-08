#include "AxeItem.h"

AxeItem::AxeItem(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\PickUp\\Weapon\\AxeItem.xml";
}

AxeItem::~AxeItem()
{
	playScene = nullptr;
}

void AxeItem::Load()
{
	GameObject::Load();
}

void AxeItem::Unload()
{
	GameObject::Unload();
}

void AxeItem::Start()
{
	start = true;
}

void AxeItem::Update(float elapsedMs)
{
	if (!start)	Start();
}

void AxeItem::Render()
{
	GetSpriteRenderer()->Render("axeItem");
}

void AxeItem::Collided(pCollision& collision)
{
}

void AxeItem::SpawnedHandler(pGameObject gameObject)
{
}

void AxeItem::DestroyedHandler(pGameObject gameObject)
{
}
