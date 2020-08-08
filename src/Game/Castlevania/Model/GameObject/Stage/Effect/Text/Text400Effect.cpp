#include "Text400Effect.h"

Text400Effect::Text400Effect(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Effect\\Text\\Text400Effect.xml";
}

Text400Effect::~Text400Effect()
{
}

void Text400Effect::Load()
{
	GameObject::Load();
}

void Text400Effect::Unload()
{
	GameObject::Unload();
}

void Text400Effect::Start()
{
	start = true;
}

void Text400Effect::Update(float elapsedMs)
{
	if (!start) Start();
}

void Text400Effect::Render()
{
	GetSpriteRenderer()->Render("40");
	GetSpriteRenderer()->Render("0");
}

void Text400Effect::Collided(pCollision& collision)
{
}

void Text400Effect::SpawnedHandler(pGameObject gameObject)
{
}

void Text400Effect::DestroyedHandler(pGameObject gameObject)
{
}
