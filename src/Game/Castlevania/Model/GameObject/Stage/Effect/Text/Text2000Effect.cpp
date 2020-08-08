#include "Text2000Effect.h"

Text2000Effect::Text2000Effect(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Effect\\Text\\Text2000Effect.xml";
}

Text2000Effect::~Text2000Effect()
{
}

void Text2000Effect::Load()
{
	GameObject::Load();
}

void Text2000Effect::Unload()
{
	GameObject::Unload();
}

void Text2000Effect::Start()
{
	start = true;
}

void Text2000Effect::Update(float elapsedMs)
{
	if (!start) Start();
}

void Text2000Effect::Render()
{
	GetSpriteRenderer()->Render("20");
	GetSpriteRenderer()->Render("00");
}

void Text2000Effect::Collided(pCollision& collision)
{
}

void Text2000Effect::SpawnedHandler(pGameObject gameObject)
{
}

void Text2000Effect::DestroyedHandler(pGameObject gameObject)
{
}
