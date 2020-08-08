#include "Intro_Cloud.h"

Intro_Cloud::Intro_Cloud(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	source = "Castlevania\\Data\\GameObject\\Intro\\Intro_Cloud.xml";
}

Intro_Cloud::~Intro_Cloud()
{
}

void Intro_Cloud::Load()
{
	GameObject::Load();
}

void Intro_Cloud::Unload()
{
	GameObject::Unload();
}

void Intro_Cloud::Start()
{
	start = true;
}

void Intro_Cloud::Update(float elapsedMs)
{
	if (!start) Start();
	x -= defaultSpeed * elapsedMs;
}

void Intro_Cloud::Render()
{
	GetSpriteRenderer()->Render("0");
}

void Intro_Cloud::Collided(pCollision& collision)
{
}

void Intro_Cloud::SpawnedHandler(pGameObject gameObject)
{
}

void Intro_Cloud::DestroyedHandler(pGameObject gameObject)
{
}