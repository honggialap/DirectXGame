#pragma once
#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include "../Include.h"
#include "../Game.h"
#include "Scene.h"
#include "Component/Component.h"
#include "Component/Sprite.h"
#include "Component/Animation.h"
#include "Component/Tilemap.h"
#include "Component/Text.h"
#include "Component/SoundSource.h"
#include "Component/Physics.h"

class GameObject
{
protected:
	string source;
	unordered_map<Component::Type, pComponent> components;

public:
	pScene scene;

	bool start;
	bool expired;
	bool enable;
	bool visible;
	
	int id;
	int layer;
	float x, y;
	int cellX, cellY;

public:
	GameObject(pScene scene);
	virtual ~GameObject() = 0;

	virtual void Load();
	virtual void Unload();

	void Activate() { this->enable = true; }
	void Deactivate() { this->enable = false; }
	void Show() { this->visible = true; }
	void Hide() { this->visible = false; }

	virtual void Start() = 0;
	virtual void Update(float elapsedMs) = 0;
	virtual void Render() = 0;

	void SetPosition(float x, float y);
	void GetPosition(float &x, float &y);
	void Translate(float x, float y);

	pSpriteRenderer GetSpriteRenderer();
	pAnimator GetAnimator();
	pTilemap GetTilemap();
	pTextRenderer GetTextRenderer();
	pSoundSource GetSoundSource();
	pPhysics GetPhysics();

	virtual void Collided(pCollision &collision) = 0;
	virtual void SpawnedHandler(pGameObject gameObject) = 0;
	virtual void DestroyedHandler(pGameObject gameObject) = 0;

	static bool LayerCompare(const pGameObject& a, const pGameObject& b);
};

#endif // !__GAME_OBJECT_H__