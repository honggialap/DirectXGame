#include "BrokenBrickEffect.h"

BrokenBrickEffect::BrokenBrickEffect(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Effect\\BrokenBrickEffect.xml";
}

BrokenBrickEffect::~BrokenBrickEffect()
{
	playScene = nullptr;
}

void BrokenBrickEffect::Load()
{
	GameObject::Load();
}

void BrokenBrickEffect::Unload()
{
	GameObject::Unload();
}

void BrokenBrickEffect::Start()
{
	start = true;
}

void BrokenBrickEffect::Update(float elapsedMs)
{
	if (!start)	Start();
}

void BrokenBrickEffect::Render()
{
	GetSpriteRenderer()->Render("brokenBrickEffect");
}

void BrokenBrickEffect::Collided(pCollision& collision)
{
}

void BrokenBrickEffect::SpawnedHandler(pGameObject gameObject)
{
}

void BrokenBrickEffect::DestroyedHandler(pGameObject gameObject)
{
}
