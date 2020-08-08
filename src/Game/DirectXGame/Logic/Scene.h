#pragma once
#ifndef __SCECE_H__
#define __SCENE_H__

#include "../Include.h"
#include "../Game.h"
#include "GameObject.h"
#include "Camera.h"
#include "View/Local/LocalPlayer.h"
#include "View/Local/Control.h"
#include "View/Local/Viewport.h"

class Scene
{
public:
	// Game
	pGame game;

	// Scene
	bool done;
	bool loading;
	string source;
	enum Mode
	{
		Local,
		Client,
		Server
	};
	Mode mode;
	string nextScene;

	Scene(pGame game);
	virtual ~Scene() = 0;
	void SwitchScene(string sceneID);
	virtual void Load();
	virtual void Unload();

	// Player
	int playerID;
	unordered_map<int, pPlayer> players;

	// Camera
	int cameraID;
	unordered_map<int, pCamera> cameras;

	// Grid
	float cellWidth, cellHeight;
	map<pair<int, int>, vector<int>> grid;

	void CalculateCell(int positionX, int positionY, int& cellX, int& cellY);
	void AddCell(int gameObjectID, int column, int row);
	void RemoveCell(int gameObjectID);
	void UpdateCell(int gameObjectID);
	void GetLocalGroup(vector<int>* list, int cellX, int cellY);

	// Game object
	int gameObjectID;
	unordered_map<int, pGameObject> dictionary;
	vector<pGameObject> addedObjects;
	vector<pGameObject> removedObjects;
	vector<pGameObject> updateSequence;
	vector<pGameObject> renderSequence;

	virtual pGameObject Spawn(string prefabID, float positionX, float positionY);
	virtual void Destroy(int id);
	void Update(float elapsedMs);
	void Render();
private:
	void Add();
	void Remove();
	void SortByRenderLayer();
};

#endif // !__SCECE_H__
