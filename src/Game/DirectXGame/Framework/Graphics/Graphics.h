#pragma once

#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include "Direct3D.h"

class Graphics
{
	//Singleton
private:
	static Graphics* __instance;
	Graphics();
public:
	static Graphics* GetInstance();
	~Graphics();


	//Direct3D API
private:

public:

	//Framework component
public:
	void Initialize();
	void Shutdown();
};

typedef Graphics* pGraphics;

#endif // !__GRAPHICS_H__