#include "Death2Effect.h"

Death2Effect::Death2Effect(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Effect\\Death2Effect.xml";
}

Death2Effect::~Death2Effect()
{
	playScene = nullptr;
}

void Death2Effect::Load()
{
	GameObject::Load();
}

void Death2Effect::Unload()
{
	GameObject::Unload();
}

void Death2Effect::Start()
{
	start = true;
	GetAnimator()->Play("death2Effect", true);
}

void Death2Effect::Update(float elapsedMs)
{
	if (!start)	Start();
	GetAnimator()->Update(elapsedMs);
}

void Death2Effect::Render()
{
	GetAnimator()->Render();
}

void Death2Effect::Collided(pCollision& collision)
{
}

void Death2Effect::SpawnedHandler(pGameObject gameObject)
{
}

void Death2Effect::DestroyedHandler(pGameObject gameObject)
{
}
