#include "MovingPlatform.h"

MovingPlatform::MovingPlatform(pScene scene) : GameObject::GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Prop\\MovingPlatform.xml";
}

MovingPlatform::~MovingPlatform()
{
}

void MovingPlatform::Load()
{
	GameObject::Load();
}

void MovingPlatform::Unload()
{
	GameObject::Unload();
}

void MovingPlatform::Start()
{
	start = true;
	GetPhysics()->Enable();
	GetPhysics()->SetCollider(10, 20, 0, 0);
}

void MovingPlatform::Update(float elapsedMs)
{
	if (!start) Start();
	GetPhysics()->Update(elapsedMs);
}

void MovingPlatform::Render()
{
	GetPhysics()->RenderBoundingBox();
	GetSpriteRenderer()->Render("movingPlatform");
}

void MovingPlatform::Collided(pCollision& collision)
{
}

void MovingPlatform::SpawnedHandler(pGameObject gameObject)
{
}

void MovingPlatform::DestroyedHandler(pGameObject gameObject)
{
}
