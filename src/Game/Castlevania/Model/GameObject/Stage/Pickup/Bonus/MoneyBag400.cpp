#include "MoneyBag400.h"

MoneyBag400::MoneyBag400(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\PickUp\\Bonus\\MoneyBag400.xml";
}

MoneyBag400::~MoneyBag400()
{
	playScene = nullptr;
}

void MoneyBag400::Load()
{
	GameObject::Load();
}

void MoneyBag400::Unload()
{
	GameObject::Unload();
}

void MoneyBag400::Start()
{
	start = true;
}

void MoneyBag400::Update(float elapsedMs)
{
	if (!start)	Start();
}

void MoneyBag400::Render()
{
	GetSpriteRenderer()->Render("moneyBag400");
}

void MoneyBag400::Collided(pCollision& collision)
{
}

void MoneyBag400::SpawnedHandler(pGameObject gameObject)
{
}

void MoneyBag400::DestroyedHandler(pGameObject gameObject)
{
}
