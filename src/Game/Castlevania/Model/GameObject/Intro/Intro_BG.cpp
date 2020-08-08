#include "Intro_BG.h"

Intro_BG::Intro_BG(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Intro\\Intro_BG.xml";
}

Intro_BG::~Intro_BG()
{
}

void Intro_BG::Load()
{
	GameObject::Load();
}

void Intro_BG::Unload()
{
	GameObject::Unload();
}

void Intro_BG::Start()
{
	start = true;
}

void Intro_BG::Update(float elapsedMs)
{
	if (!start) Start();
}

void Intro_BG::Render()
{
	GetSpriteRenderer()->Render("0");
}

void Intro_BG::Collided(pCollision& collision)
{
}

void Intro_BG::SpawnedHandler(pGameObject gameObject)
{
}

void Intro_BG::DestroyedHandler(pGameObject gameObject)
{
}