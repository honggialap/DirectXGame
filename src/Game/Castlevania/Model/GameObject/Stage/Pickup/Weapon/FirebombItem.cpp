#include "FirebombItem.h"

FirebombItem::FirebombItem(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\PickUp\\Weapon\\FirebombItem.xml";
}

FirebombItem::~FirebombItem()
{
	playScene = nullptr;
}

void FirebombItem::Load()
{
	GameObject::Load();
}

void FirebombItem::Unload()
{
	GameObject::Unload();
}

void FirebombItem::Start()
{
	start = true;
}

void FirebombItem::Update(float elapsedMs)
{
	if (!start)	Start();
}

void FirebombItem::Render()
{
	GetSpriteRenderer()->Render("firebombItem");
}

void FirebombItem::Collided(pCollision& collision)
{
}

void FirebombItem::SpawnedHandler(pGameObject gameObject)
{
}

void FirebombItem::DestroyedHandler(pGameObject gameObject)
{
}
