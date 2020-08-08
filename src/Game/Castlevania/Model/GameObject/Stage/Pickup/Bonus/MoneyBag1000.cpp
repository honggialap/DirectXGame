#include "MoneyBag1000.h"

MoneyBag1000::MoneyBag1000(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\PickUp\\Bonus\\MoneyBag1000.xml";
}

MoneyBag1000::~MoneyBag1000()
{
	playScene = nullptr;
}

void MoneyBag1000::Load()
{
	GameObject::Load();
}

void MoneyBag1000::Unload()
{
	GameObject::Unload();
}

void MoneyBag1000::Start()
{
	start = true;
	GetAnimator()->Play("idle", true);
}

void MoneyBag1000::Update(float elapsedMs)
{
	if (!start)	Start();
	GetAnimator()->Update(elapsedMs);
}

void MoneyBag1000::Render()
{
	GetAnimator()->Render();
}

void MoneyBag1000::Collided(pCollision& collision)
{
}

void MoneyBag1000::SpawnedHandler(pGameObject gameObject)
{
}

void MoneyBag1000::DestroyedHandler(pGameObject gameObject)
{
}
