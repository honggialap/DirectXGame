#include "HitEffect.h"

HitEffect::HitEffect(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Effect\\HitEffect.xml";
}

HitEffect::~HitEffect()
{
	playScene = nullptr;
}

void HitEffect::Load()
{
	GameObject::Load();
}

void HitEffect::Unload()
{
	GameObject::Unload();
}

void HitEffect::Start()
{
	start = true;
}

void HitEffect::Update(float elapsedMs)
{
	if (!start)	Start();
}

void HitEffect::Render()
{
	GetSpriteRenderer()->Render("hitEffect");
}

void HitEffect::Collided(pCollision& collision)
{
}

void HitEffect::SpawnedHandler(pGameObject gameObject)
{
}

void HitEffect::DestroyedHandler(pGameObject gameObject)
{
}
