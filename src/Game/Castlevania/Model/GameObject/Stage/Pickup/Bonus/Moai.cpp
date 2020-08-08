#include "Moai.h"

Moai::Moai(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\PickUp\\Bonus\\Moai.xml";
}

Moai::~Moai()
{
	playScene = nullptr;
}

void Moai::Load()
{
	GameObject::Load();
}

void Moai::Unload()
{
	GameObject::Unload();
}

void Moai::Start()
{
	start = true;
	GetAnimator()->Play("idle", true);
}

void Moai::Update(float elapsedMs)
{
	if (!start)	Start();
	GetAnimator()->Update(elapsedMs);
}

void Moai::Render()
{
	GetAnimator()->Render();
}

void Moai::Collided(pCollision& collision)
{
}

void Moai::SpawnedHandler(pGameObject gameObject)
{
}

void Moai::DestroyedHandler(pGameObject gameObject)
{
}
