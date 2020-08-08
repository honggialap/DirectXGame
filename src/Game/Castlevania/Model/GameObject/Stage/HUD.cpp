#include "HUD.h"

HUD::HUD(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
}

HUD::~HUD()
{
}

void HUD::Load()
{
	GameObject::Load();
}

void HUD::Unload()
{
	GameObject::Unload();
}

void HUD::Start()
{
}

void HUD::Update(float elapsedMs)
{
}

void HUD::Render()
{
}

void HUD::Collided(pCollision& collision)
{
}

void HUD::SpawnedHandler(pGameObject gameObject)
{
}

void HUD::DestroyedHandler(pGameObject gameObject)
{
}
