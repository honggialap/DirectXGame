#include "MoneyBag100.h"

MoneyBag100::MoneyBag100(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\PickUp\\Bonus\\MoneyBag100.xml";
}

MoneyBag100::~MoneyBag100()
{
	playScene = nullptr;
}

void MoneyBag100::Load()
{
	GameObject::Load();
}

void MoneyBag100::Unload()
{
	GameObject::Unload();
}

void MoneyBag100::Start()
{
	start = true;
}

void MoneyBag100::Update(float elapsedMs)
{
	if (!start)	Start();
}

void MoneyBag100::Render()
{
	GetSpriteRenderer()->Render("moneyBag100");
}

void MoneyBag100::Collided(pCollision& collision)
{
}

void MoneyBag100::SpawnedHandler(pGameObject gameObject)
{
}

void MoneyBag100::DestroyedHandler(pGameObject gameObject)
{
}
