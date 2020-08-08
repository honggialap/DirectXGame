#include "MoneyBag700.h"

MoneyBag700::MoneyBag700(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\PickUp\\Bonus\\MoneyBag700.xml";
}

MoneyBag700::~MoneyBag700()
{
	playScene = nullptr;
}

void MoneyBag700::Load()
{
	GameObject::Load();
}

void MoneyBag700::Unload()
{
	GameObject::Unload();
}

void MoneyBag700::Start()
{
	start = true;
}

void MoneyBag700::Update(float elapsedMs)
{
	if (!start)	Start();
}

void MoneyBag700::Render()
{
	GetSpriteRenderer()->Render("moneyBag700");
}

void MoneyBag700::Collided(pCollision& collision)
{
}

void MoneyBag700::SpawnedHandler(pGameObject gameObject)
{
}

void MoneyBag700::DestroyedHandler(pGameObject gameObject)
{
}
