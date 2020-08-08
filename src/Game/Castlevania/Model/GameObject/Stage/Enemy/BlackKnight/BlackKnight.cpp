#include "BlackKnight.h"

BlackKnight::BlackKnight(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "";
}

BlackKnight::~BlackKnight()
{
	playScene = nullptr;
}

void BlackKnight::Load()
{
	GameObject::Load();
}

void BlackKnight::Unload()
{
	GameObject::Unload();
}

void BlackKnight::Start()
{
	start = true;
}

void BlackKnight::Update(float elapsedMs)
{
	if (!start)	Start();
}

void BlackKnight::Render()
{
}

void BlackKnight::Collided(pCollision& collision)
{
}

void BlackKnight::SpawnedHandler(pGameObject gameObject)
{
}

void BlackKnight::DestroyedHandler(pGameObject gameObject)
{
}
