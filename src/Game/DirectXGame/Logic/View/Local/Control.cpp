#include "Control.h"

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::OnKeyDown(int keyCode)
{
	buttonState[keybinds[keyCode]] = Controller::ButtonState::Pressed;
}

void Controller::OnKeyUp(int keyCode)
{
	buttonState[keybinds[keyCode]] = Controller::ButtonState::Released;
}

void Controller::KeyState(BYTE* states)
{
	for (auto it : buttonState)
		previousButtonState[it.first] = it.second;
}

bool Controller::IsButtonDown(Button button)
{
	return buttonState[button];
}

bool Controller::IsButtonPressed(Button button)
{
	if (buttonState[button] == Pressed &&
		previousButtonState[button] == Released)
	{
		DebugOut(L"Button pressed %d\n", button);
		return true;
	}
	else return false;

}

bool Controller::IsButtonReleased(Button button)
{
	if (buttonState[button] == Released &&
		previousButtonState[button] == Pressed)
	{
		DebugOut(L"Button released %d\n", button);
		return true;
	}
	else return false;
}