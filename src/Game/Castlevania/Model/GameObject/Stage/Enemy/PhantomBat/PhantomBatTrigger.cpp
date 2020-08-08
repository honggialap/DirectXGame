#include "PhantomBatTrigger.h"

PhantomBatTrigger::PhantomBatTrigger(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "";
}

PhantomBatTrigger::~PhantomBatTrigger()
{
	playScene = nullptr;
}

void PhantomBatTrigger::Load()
{
	GameObject::Load();
}

void PhantomBatTrigger::Unload()
{
	GameObject::Unload();
}

void PhantomBatTrigger::Start()
{
	start = true;
}

void PhantomBatTrigger::Update(float elapsedMs)
{
	if (!start)	Start();
}

void PhantomBatTrigger::Render()
{
}

void PhantomBatTrigger::Collided(pCollision& collision)
{
}

void PhantomBatTrigger::SpawnedHandler(pGameObject gameObject)
{
}

void PhantomBatTrigger::DestroyedHandler(pGameObject gameObject)
{
}
