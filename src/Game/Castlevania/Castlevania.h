#pragma once
#ifndef __CASTLEVANIA_H__
#define __CASTLEVANIA_H__

#include "Include.h"
#include "../DirectXGame/Game.h"
#include "../Castlevania/Model/Scene/PlayScene.h"

class Castlevania : public Game
{
public:
	Castlevania(HINSTANCE hInstance);
	~Castlevania();
	virtual void LoadScene(string sceneID);
};

#endif // !__CASTLEVANIA_H__
