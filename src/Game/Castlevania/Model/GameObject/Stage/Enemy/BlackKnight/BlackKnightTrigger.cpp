#include "BlackKnightTrigger.h"

BlackKnightTrigger::BlackKnightTrigger(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "";
}

BlackKnightTrigger::~BlackKnightTrigger()
{
	playScene = nullptr;
}

void BlackKnightTrigger::Load()
{
	GameObject::Load();
}

void BlackKnightTrigger::Unload()
{
	GameObject::Unload();
}

void BlackKnightTrigger::Start()
{
	start = true;
}

void BlackKnightTrigger::Update(float elapsedMs)
{
	if (!start)	Start();
}

void BlackKnightTrigger::Render()
{
}

void BlackKnightTrigger::Collided(pCollision& collision)
{
}

void BlackKnightTrigger::SpawnedHandler(pGameObject gameObject)
{
}

void BlackKnightTrigger::DestroyedHandler(pGameObject gameObject)
{
}
