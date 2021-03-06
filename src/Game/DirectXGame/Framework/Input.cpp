#include "Input.h"

Input::Input()
{
	inputDevice = new InputDevice();
	inputDevice->directInput = NULL;
	inputDevice->device = NULL;
}

Input::~Input()
{
	if (inputDevice->device != NULL) inputDevice->device->Release();
	inputDevice->device = NULL;

	if (inputDevice->directInput != NULL) inputDevice->directInput->Release();
	inputDevice->directInput = NULL;

	if (inputDevice != nullptr)
	{
		delete inputDevice;
		inputDevice = nullptr;
	}
}

void Input::CreateInputDevice(pGameWindow gameWindow)
{
	//create direct input object
	HRESULT hr = DirectInput8Create(
		gameWindow->hInstance,
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(VOID * *) & (inputDevice->directInput),
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
	HRESULT hr = inputDevice->device->GetDeviceState(sizeof(inputDevice->keyStates), inputDevice->keyStates);
	if (FAILED(hr))
	{
		// If the keyboard lost focus or was not acquired then try to get control back.
		if ((hr == DIERR_INPUTLOST) || (hr == DIERR_NOTACQUIRED))
		{
			HRESULT h = inputDevice->device->Acquire();
			if (h == DI_OK)
			{
				OutputDebugString(L"[INFO] Keyboard re-acquired.\n");
			}
			else return;
		}
		else
		{
			//DebugOut(L"[ERROR] DINPUT::GetDeviceState failed. Error: %d\n", hr);
			return;
		}
	}
	
	inputDevice->keyHandler->KeyState((BYTE*)& inputDevice->keyStates);
	
	// Collect all buffered events
	DWORD dwElements = inputDevice->KEYBOARD_BUFFER_SIZE;
	hr = inputDevice->device->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), inputDevice->keyEvents, &dwElements, 0);
	if (FAILED(hr))
	{
		//DebugOut(L"[ERROR] DINPUT::GetDeviceData failed. Error: %d\n", hr);
		return;
	}
	
	// Scan through all buffered events, check if the key is pressed or released
	for (DWORD i = 0; i < dwElements; i++)
	{
		int KeyCode = inputDevice->keyEvents[i].dwOfs;
		int KeyState = inputDevice->keyEvents[i].dwData;

		if ((KeyState & 0x80) > 0)
			inputDevice->keyHandler->OnKeyDown(KeyCode);
		else
			inputDevice->keyHandler->OnKeyUp(KeyCode);
	}
}

int Input::IsKeyDown(int KeyCode)
{
	return (inputDevice->keyStates[KeyCode] & 0x80) > 0;
}

void Input::SetKeyHandler(pKeyHandler keyEventHandler)
{
	inputDevice->keyHandler = keyEventHandler;
}