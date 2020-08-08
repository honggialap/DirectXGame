#pragma once
#ifndef __CONTROL_H__
#define __CONTROL_H__

#include "../../../Include.h"
#include "../../../Framework/Input.h"

class Controller : public KeyHandler
{
public:
	enum Button
	{
		Up, Down,
		Left, Right,
		A, B,
		Start, Select
	};
	map<int, Button> keybinds;

	enum ButtonState
	{
		 Released, Pressed
	};
	map<Button, ButtonState> buttonState;
	map<Button, ButtonState> previousButtonState;

	Controller();
	~Controller();

	bool IsButtonDown(Button button);
	bool IsButtonPressed(Button button);
	bool IsButtonReleased(Button button);

	void OnKeyDown(int keyCode);
	void OnKeyUp(int keyCode);
	void KeyState(BYTE* states);
};

#endif // !__CONTROL_H__
