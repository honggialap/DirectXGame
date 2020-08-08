#include "Text4000Effect.h"

Text4000Effect::Text4000Effect(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Effect\\Text\\Text4000Effect.xml";
}

Text4000Effect::~Text4000Effect()
{
}

void Text4000Effect::Load()
{
	GameObject::Load();
}

void Text4000Effect::Unload()
{
	GameObject::Unload();
}

void Text4000Effect::Start()
{
	start = true;
}

void Text4000Effect::Update(float elapsedMs)
{
	if (!start) Start();
}

void Text4000Effect::Render()
{
	GetSpriteRenderer()->Render("40");
	GetSpriteRenderer()->Render("00");
}

void Text4000Effect::Collided(pCollision& collision)
{
}

void Text4000Effect::SpawnedHandler(pGameObject gameObject)
{
}

void Text4000Effect::DestroyedHandler(pGameObject gameObject)
{
}
