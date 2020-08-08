#include "LargeHeart.h"

LargeHeart::LargeHeart(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\PickUp\\Item\\LargeHeart.xml";
}

LargeHeart::~LargeHeart()
{
	playScene = nullptr;
}

void LargeHeart::Load()
{
	GameObject::Load();
}

void LargeHeart::Unload()
{
	GameObject::Unload();
}

void LargeHeart::Start()
{
	start = true;
}

void LargeHeart::Update(float elapsedMs)
{
	if (!start)	Start();
}

void LargeHeart::Render()
{
	GetSpriteRenderer()->Render("largeHeart");
}

void LargeHeart::Collided(pCollision& collision)
{
}

void LargeHeart::SpawnedHandler(pGameObject gameObject)
{
}

void LargeHeart::DestroyedHandler(pGameObject gameObject)
{
}
