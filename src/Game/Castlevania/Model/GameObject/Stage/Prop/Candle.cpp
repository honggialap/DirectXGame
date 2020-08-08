#include "Candle.h"

Candle::Candle(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Prop\\Candle.xml";
}

Candle::~Candle()
{
}

void Candle::Load()
{
	GameObject::Load();
}

void Candle::Unload()
{
	GameObject::Unload();
}

void Candle::Start()
{
	start = true;
	GetPhysics()->Enable();
	GetPhysics()->SetCollider(10, 20, 0, 0);
	GetAnimator()->Play("idle", true);
}

void Candle::Update(float elapsedMs)
{
	if (!start) Start();
	GetPhysics()->Update(elapsedMs);
	GetAnimator()->Update(elapsedMs);
}

void Candle::Render()
{
	GetPhysics()->RenderBoundingBox();
	GetAnimator()->Render();
}

void Candle::Collided(pCollision& collision)
{
}

void Candle::SpawnedHandler(pGameObject gameObject)
{
}

void Candle::DestroyedHandler(pGameObject gameObject)
{
}
