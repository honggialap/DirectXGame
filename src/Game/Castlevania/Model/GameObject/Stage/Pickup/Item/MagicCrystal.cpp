#include "MagicCrystal.h"

MagicCrystal::MagicCrystal(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\PickUp\\Item\\MagicCrystal.xml";
}

MagicCrystal::~MagicCrystal()
{
	playScene = nullptr;
}

void MagicCrystal::Load()
{
	GameObject::Load();
}

void MagicCrystal::Unload()
{
	GameObject::Unload();
}

void MagicCrystal::Start()
{
	start = true;
	GetAnimator()->Play("idle", true);
}

void MagicCrystal::Update(float elapsedMs)
{
	if (!start)	Start();
	GetAnimator()->Update(elapsedMs);
}

void MagicCrystal::Render()
{
	GetAnimator()->Render();
}

void MagicCrystal::Collided(pCollision& collision)
{
}

void MagicCrystal::SpawnedHandler(pGameObject gameObject)
{
}

void MagicCrystal::DestroyedHandler(pGameObject gameObject)
{
}
