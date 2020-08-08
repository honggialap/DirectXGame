#include "Text700Effect.h"

Text700Effect::Text700Effect(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Stage\\Effect\\Text\\Text700Effect.xml";
}

Text700Effect::~Text700Effect()
{
}

void Text700Effect::Load()
{
	GameObject::Load();
}

void Text700Effect::Unload()
{
	GameObject::Unload();
}

void Text700Effect::Start()
{
	if (!start) Start();
}

void Text700Effect::Update(float elapsedMs)
{
}

void Text700Effect::Render()
{
	GetSpriteRenderer()->Render("70");
	GetSpriteRenderer()->Render("0");
}

void Text700Effect::Collided(pCollision& collision)
{
}

void Text700Effect::SpawnedHandler(pGameObject gameObject)
{
}

void Text700Effect::DestroyedHandler(pGameObject gameObject)
{
}
