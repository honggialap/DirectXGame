#include "SmallHeart.h"

SmallHeart::SmallHeart(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\PickUp\\Item\\SmallHeart.xml";
}

SmallHeart::~SmallHeart()
{
	playScene = nullptr;
}

void SmallHeart::Load()
{
	GameObject::Load();
}

void SmallHeart::Unload()
{
	GameObject::Unload();
}

void SmallHeart::Start()
{
	start = true;
}

void SmallHeart::Update(float elapsedMs)
{
	if (!start)	Start();
}

void SmallHeart::Render()
{
	GetSpriteRenderer()->Render("smallHeart");
}

void SmallHeart::Collided(pCollision& collision)
{
}

void SmallHeart::SpawnedHandler(pGameObject gameObject)
{
}

void SmallHeart::DestroyedHandler(pGameObject gameObject)
{
}
