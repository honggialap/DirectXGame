#pragma once
#ifndef __GAMEMASTER_SAMPLE_H__
#define __GAMEMASTER_SAMPLE_H__

#pragma region INCLUDE
#include "../Engine/GameObject.h"
#pragma endregion

class CGameMasterSample : public CGameObject
{
public:
	CGameMasterSample(
		pGame game, pScene scene,
		unsigned int id, std::string name, std::string source,
		float x, float y, int gx, int gy, unsigned int layer
	) : CGameObject(game, scene, id, name, source, x, y, gx, gy, layer) {};

	virtual void Load();
	virtual void Start();
	virtual void Update(float elapsedMs);
	virtual void Render();
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);

	bool loadFrame;
	unsigned int sceneId;
	unsigned int nextSceneId;
	void SwitchScene(unsigned int sceneId);


};
typedef CGameMasterSample* pGameMasterSample;

#endif // !__GAMEMASTER_SAMPLE_H__
