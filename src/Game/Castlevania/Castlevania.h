#pragma once
#ifndef __CASTLEVANIA_H__
#define __CASTLEVANIA_H__

#include "../DirectXGame/Game.h"

class Castlevania : public Game

{
public:
	Castlevania(HINSTANCE hInstance);
	~Castlevania();
	virtual void Load(LPCWSTR dataFilePath);
};

#endif // !__CASTLEVANIA_H__
