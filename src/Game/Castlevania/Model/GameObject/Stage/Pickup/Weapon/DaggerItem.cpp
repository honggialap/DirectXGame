#include "DaggerItem.h"

DaggerItem::DaggerItem(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\PickUp\\Weapon\\DaggerItem.xml";
}

DaggerItem::~DaggerItem()
{
	playScene = nullptr;
}

void DaggerItem::Load()
{
	GameObject::Load();
}

void DaggerItem::Unload()
{
	GameObject::Unload();
}

void DaggerItem::Start()
{
	start = true;
}

void DaggerItem::Update(float elapsedMs)
{
	if (!start)	Start();
}

void DaggerItem::Render()
{
	GetSpriteRenderer()->Render("daggerItem");
}

void DaggerItem::Collided(pCollision& collision)
{
}

void DaggerItem::SpawnedHandler(pGameObject gameObject)
{
}

void DaggerItem::DestroyedHandler(pGameObject gameObject)
{
}
