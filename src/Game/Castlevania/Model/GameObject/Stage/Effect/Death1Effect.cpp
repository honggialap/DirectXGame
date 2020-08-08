#include "Death1Effect.h"

Death1Effect::Death1Effect(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Effect\\Death1Effect.xml";
}

Death1Effect::~Death1Effect()
{
	playScene = nullptr;
}

void Death1Effect::Load()
{
	GameObject::Load();
}

void Death1Effect::Unload()
{
	GameObject::Unload();
}

void Death1Effect::Start()
{
	start = true;
	GetAnimator()->Play("death1Effect", true);
}

void Death1Effect::Update(float elapsedMs)
{
	if (!start)	Start();
	GetAnimator()->Update(elapsedMs);
}

void Death1Effect::Render()
{
	GetAnimator()->Render();
}

void Death1Effect::Collided(pCollision& collision)
{
}

void Death1Effect::SpawnedHandler(pGameObject gameObject)
{
}

void Death1Effect::DestroyedHandler(pGameObject gameObject)
{
}
