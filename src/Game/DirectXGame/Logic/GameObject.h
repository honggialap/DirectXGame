#pragma once
#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include "../Include.h"

#include "../Game.h"
#include "Scene.h"
#include "Component.h"
#include "Transform.h"
//#include "Sprite.h"
//#include "Animation.h"
//#include "Tilemap.h"
//#include "Physics.h"
//#include "Collision.h"

class GameObject
{
public:
	pGame game;
	pScene scene;

	string id;
	bool enabled;
	bool visibled;

	pComponents components;
	
	pGameObject parent;
	unordered_map<string, pGameObject> childs;

	GameObject(pGame game, pScene scene);
	~GameObject(); 

	virtual void Load() = 0;
	virtual void Update(pGameTime gameTime) = 0;
	virtual void Render() = 0;
};

class GameObjects
{
public:
	pGame game;
	pScene scene;

	vector<pGameObject> gameObjects;

	GameObjects(pGame game, pScene scene);
	~GameObjects();

	void Add();
	void Remove();
	void Get();
	void Clear();
};

#endif // !__GAME_OBJECT_H__
