#include "Crown.h"

Crown::Crown(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\PickUp\\Bonus\\Crown.xml";
}

Crown::~Crown()
{
	playScene = nullptr;
}

void Crown::Load()
{
	GameObject::Load();
}

void Crown::Unload()
{
	GameObject::Unload();
}

void Crown::Start()
{
	start = true;
	GetAnimator()->Play("idle", true);
}

void Crown::Update(float elapsedMs)
{
	if (!start)	Start();
	GetAnimator()->Update(elapsedMs);
}

void Crown::Render()
{
	GetAnimator()->Render();
}

void Crown::Collided(pCollision& collision)
{
}

void Crown::SpawnedHandler(pGameObject gameObject)
{
}

void Crown::DestroyedHandler(pGameObject gameObject)
{
}
