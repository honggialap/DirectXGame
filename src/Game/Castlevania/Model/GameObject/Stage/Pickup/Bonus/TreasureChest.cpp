#include "TreasureChest.h"

TreasureChest::TreasureChest(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\PickUp\\Bonus\\TreasureChest.xml";
}

TreasureChest::~TreasureChest()
{
	playScene = nullptr;
}

void TreasureChest::Load()
{
	GameObject::Load();
}

void TreasureChest::Unload()
{
	GameObject::Unload();
}

void TreasureChest::Start()
{
	start = true;
	GetAnimator()->Play("idle", true);
}

void TreasureChest::Update(float elapsedMs)
{
	if (!start)	Start();
	GetAnimator()->Update(elapsedMs);
}

void TreasureChest::Render()
{
	GetAnimator()->Render();
}

void TreasureChest::Collided(pCollision& collision)
{
}

void TreasureChest::SpawnedHandler(pGameObject gameObject)
{
}

void TreasureChest::DestroyedHandler(pGameObject gameObject)
{
}
