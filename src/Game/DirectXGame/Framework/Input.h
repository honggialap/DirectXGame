#pragma once
#ifndef __INPUT_H__
#define __INPUT_H__

#include "../Include.h"
#include "Application.h"

class KeyHandler
{
public:
	virtual void KeyState(BYTE* state) = 0;
	virtual void OnKeyDown(int KeyCode) = 0;
	virtual void OnKeyUp(int KeyCode) = 0;
};

struct InputDevice
{
	static const int KEYBOARD_BUFFER_SIZE = 1024;
	static const int KEYSTATE_BUFFER_SIZE = 256;

	LPDIRECTINPUT8			directInput;						// The DirectInput object         
	LPDIRECTINPUTDEVICE8	device;								// The keyboard device
	BYTE					keyStates[KEYSTATE_BUFFER_SIZE] = {0};	// DirectInput keyboard state buffer 
	DIDEVICEOBJECTDATA		keyEvents[KEYBOARD_BUFFER_SIZE] = {0};	// Buffered keyboard data

	pKeyHandler keyHandler;
};

class Input
{
public:
	Input();
	~Input();

	pInputDevice inputDevice;
	void CreateInputDevice(pGameWindow gameWindow);

	void Update();
	int IsKeyDown(int KeyCode);
	void SetKeyHandler(pKeyHandler keyHandler);
};

#endif // !__INPUT_H__
