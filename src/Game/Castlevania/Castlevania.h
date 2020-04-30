#pragma once
#ifndef __CASTLEVANIA_H__
#define __CASTLEVANIA_H__

#include "Include.h"
#include "../DirectXGame/Game.h"
#include "Model/Scene/Stage1Scene.h"

class Castlevania : public Game
{
public:
	Castlevania(HINSTANCE hInstance);
	~Castlevania();
	
	void Load(LPCWSTR dataFilePath);
	void LoadPrefabs(LPCWSTR dataFilePath);
	void LoadScenes(LPCWSTR dataFilePath);
};

#endif // !__CASTLEVANIA_H__
