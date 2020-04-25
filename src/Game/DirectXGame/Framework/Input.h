#pragma once
#ifndef __INPUT_H__
#define __INPUT_H__

#include "../Include.h"

#include <dinput.h>
#include "Application.h"

class KeyEventHandler
{
public:
	virtual void KeyState(BYTE* state) = 0;
	virtual void OnKeyDown(int KeyCode) = 0;
	virtual void OnKeyUp(int KeyCode) = 0;
};

typedef KeyEventHandler* pKeyEventHanlder;

class InputDevice
{
public:
	static const int KEYBOARD_BUFFER_SIZE = 1024;
	static const int KEYSTATE_BUFFER_SIZE = 256;

	LPDIRECTINPUT8			directInput;						// The DirectInput object         
	LPDIRECTINPUTDEVICE8	device;								// The keyboard device
	BYTE					keyStates[KEYSTATE_BUFFER_SIZE] = {0};	// DirectInput keyboard state buffer 
	DIDEVICEOBJECTDATA		keyEvents[KEYBOARD_BUFFER_SIZE] = {0};	// Buffered keyboard data

	//	LPKEYEVENTHANDLER keyHandler;

	InputDevice();
	~InputDevice();
};

typedef InputDevice* pInputDevice;

class Input
{
public:
	pInputDevice inputDevice;
	
	Input();
	~Input();

	void CreateInputDevice(pGameWindow gameWindow);
	
	void Update();
	int	IsKeyDown();
	void SetKeyHandler();
};

typedef Input* pInput;

#endif // !__INPUT_H__
