#include "Death3Effect.h"

Death3Effect::Death3Effect(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Effect\\Death3Effect.xml";
}

Death3Effect::~Death3Effect()
{
	playScene = nullptr;
}

void Death3Effect::Load()
{
	GameObject::Load();
}

void Death3Effect::Unload()
{
	GameObject::Unload();
}

void Death3Effect::Start()
{
	start = true;
	GetAnimator()->Play("death3Effect", true);
}

void Death3Effect::Update(float elapsedMs)
{
	if (!start)	Start();
	GetAnimator()->Update(elapsedMs);
}

void Death3Effect::Render()
{
	GetAnimator()->Render();
}

void Death3Effect::Collided(pCollision& collision)
{
}

void Death3Effect::SpawnedHandler(pGameObject gameObject)
{
}

void Death3Effect::DestroyedHandler(pGameObject gameObject)
{
}
