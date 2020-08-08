#include "Text100Effect.h"

Text100Effect::Text100Effect(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Effect\\Text\\Text100Effect.xml";
}

Text100Effect::~Text100Effect()
{
}

void Text100Effect::Load()
{
	GameObject::Load();
}

void Text100Effect::Unload()
{
	GameObject::Unload();
}

void Text100Effect::Start()
{
	start = true;
}

void Text100Effect::Update(float elapsedMs)
{
	if (!start) Start();
}

void Text100Effect::Render()
{
	GetSpriteRenderer()->Render("10");
	GetSpriteRenderer()->Render("0");
}

void Text100Effect::Collided(pCollision& collision)
{
}

void Text100Effect::SpawnedHandler(pGameObject gameObject)
{
}

void Text100Effect::DestroyedHandler(pGameObject gameObject)
{
}
