#include "Input.h"

InputDevice::InputDevice()
{
	directInput = NULL;					
	device = NULL;
}

InputDevice::~InputDevice()
{
	if (device != NULL) device->Release();
	device = NULL;

	if (directInput != NULL) directInput->Release();
	directInput = NULL;
}

Input::Input()
{
	inputDevice = new InputDevice();
}

Input::~Input()
{
	delete inputDevice;
	inputDevice = nullptr;
}

void Input::CreateInputDevice(pGameWindow gameWindow)
{
	//create direct input object
	HRESULT hr = DirectInput8Create(
				gameWindow->hInstance,
				DIRECTINPUT_VERSION,
				IID_IDirectInput8,
				(VOID * *)&(inputDevice->directInput),
				NULL);

	if (hr != DI_OK)
	{
		OutputDebugString(L"[ERROR] Direct Input create failed\n");
		return;
	}

	//create direct input device object
	hr = inputDevice->directInput->CreateDevice(
		GUID_SysKeyboard, &(inputDevice->device), NULL);

	if (hr != DI_OK)
	{
		OutputDebugString(L"[ERROR] Create Device failed\n");
		return;
	}

	// Set the data format to keyboard format
	DIPROPDWORD dipdw;
	dipdw.diph.dwSize = sizeof(DIPROPDWORD);
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipdw.diph.dwObj = 0;
	dipdw.diph.dwHow = DIPH_DEVICE;
	dipdw.dwData = inputDevice->KEYBOARD_BUFFER_SIZE; // Arbitary buffer size

	hr = inputDevice->device->SetDataFormat(&c_dfDIKeyboard);
	hr = inputDevice->device->SetCooperativeLevel(gameWindow->hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	hr = inputDevice->device->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);
	hr = inputDevice->device->Acquire();

	if (hr != DI_OK)
	{
		OutputDebugString(L"[ERROR] Input device acquire failed!\n");
		return;
	}

	OutputDebugString(L"[INFO] Keyboard has been initialized successfully\n");
}

void Input::Update()
{
	// Collect all key states first
	//HRESULT hr = inputDevice->device->GetDeviceState(sizeof(inputDevice->keyStates), inputDevice->keyStates);
	//if (FAILED(hr))
	//{
	//	// If the keyboard lost focus or was not acquired then try to get control back.
	//	if ((hr == DIERR_INPUTLOST) || (hr == DIERR_NOTACQUIRED))
	//	{
	//		HRESULT h = inputDevice->device->Acquire();
	//		if (h == DI_OK)
	//		{
	//			OutputDebugString(L"[INFO] Keyboard re-acquired.\n");
	//		}
	//		else return;
	//	}
	//	else
	//	{
	//		//DebugOut(L"[ERROR] DINPUT::GetDeviceState failed. Error: %d\n", hr);
	//		return;
	//	}
	//}
	//
	//keyHandler->KeyState((BYTE*)& keyStates);
	//
	//// Collect all buffered events
	//DWORD dwElements = KEYBOARD_BUFFER_SIZE;
	//hr = didv->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), keyEvents, &dwElements, 0);
	//if (FAILED(hr))
	//{
	//	//DebugOut(L"[ERROR] DINPUT::GetDeviceData failed. Error: %d\n", hr);
	//	return;
	//}
	//
	//// Scan through all buffered events, check if the key is pressed or released
	//for (DWORD i = 0; i < dwElements; i++)
	//{
	//	int KeyCode = keyEvents[i].dwOfs;
	//	int KeyState = keyEvents[i].dwData;
	//	if ((KeyState & 0x80) > 0)
	//		keyHandler->OnKeyDown(KeyCode);
	//	else
	//		keyHandler->OnKeyUp(KeyCode);
	//}
}

int Input::IsKeyDown()
{
	return 0;
}

void Input::SetKeyHandler()
{
}
