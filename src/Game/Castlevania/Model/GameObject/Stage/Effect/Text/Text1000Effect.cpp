#include "Text1000Effect.h"

Text1000Effect::Text1000Effect(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Effect\\Text\\Text1000Effect.xml";
}

Text1000Effect::~Text1000Effect()
{
}

void Text1000Effect::Load()
{
	GameObject::Load();
}

void Text1000Effect::Unload()
{
	GameObject::Unload();
}

void Text1000Effect::Start()
{
	start = true;
}

void Text1000Effect::Update(float elapsedMs)
{
	if (!start) Start();
}

void Text1000Effect::Render()
{
	GetSpriteRenderer()->Render("10");
	GetSpriteRenderer()->Render("00");
}

void Text1000Effect::Collided(pCollision& collision)
{
}

void Text1000Effect::SpawnedHandler(pGameObject gameObject)
{
}

void Text1000Effect::DestroyedHandler(pGameObject gameObject)
{
}
