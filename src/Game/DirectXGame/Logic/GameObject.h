#pragma once
#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include <string>
#include <vector>
using namespace std;

#include "../Framework/Math.h"

#include "../Game.h"
#include "Scene.h"

class Game;
typedef Game* pGame;

class Scene;
typedef Scene* pScene;

class GameObject;
typedef GameObject* pGameObject;


class GameObject
{
public:
	pGame game;
	pScene scene;

	string id;
	bool enabled;
	bool visibled;

	D3DXVECTOR3 position;
	
	//pBody body;
	//vector<pSprite> sprites;
	//vector<pAnimationSet> animationSets;
	//vector<pColliders> colliders;
	
	pGameObject parent;
	vector<pGameObject> child;

	GameObject(pGame game, pScene scene);
	~GameObject();

	virtual void Update(pGameTime gameTime) = 0;
	virtual void Render() = 0;
};

typedef GameObject* pGameObject;

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

typedef GameObjects* pGameObjects;

#endif // !__GAME_OBJECT_H__
