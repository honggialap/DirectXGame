#include "HunchbackTrigger.h"

HunchbackTrigger::HunchbackTrigger(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "";
}

HunchbackTrigger::~HunchbackTrigger()
{
	playScene = nullptr;
}

void HunchbackTrigger::Load()
{
	GameObject::Load();
}

void HunchbackTrigger::Unload()
{
	GameObject::Unload();
}

void HunchbackTrigger::Start()
{
	start = true;
}

void HunchbackTrigger::Update(float elapsedMs)
{
	if (!start)	Start();
}

void HunchbackTrigger::Render()
{
}

void HunchbackTrigger::Collided(pCollision& collision)
{
}

void HunchbackTrigger::SpawnedHandler(pGameObject gameObject)
{
}

void HunchbackTrigger::DestroyedHandler(pGameObject gameObject)
{
}
