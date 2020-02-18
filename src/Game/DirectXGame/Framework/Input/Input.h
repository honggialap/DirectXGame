#pragma once

#ifndef __INPUT_H__
#define __INPUT_H__

#include "DirectInput.h"

class Input
{
	//Singleton
private:
	static Input* __instance;
	Input();
public:
	static Input* GetInstance();
	~Input();


	//DirectInput API
private:

public:

	//Framework component
public:
	void Initialize();
	void Shutdown();
};

typedef Input* pInput;

#endif // !__INPUT_H__