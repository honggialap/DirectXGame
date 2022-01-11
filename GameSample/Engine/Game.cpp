#include "Game.h"
#include "Debug.h"
#include <codecvt>
#include <locale>


CGame::CGame()
{
	_application = new CApplication();
	_time = new CTime();
	_graphics = new CGraphics();
	_audio = new CAudio();
	_input = new CInput();
}


CGame::~CGame()
{
	if (_input != nullptr)
	{
		delete _input;
		_input = nullptr;
	}

	if (_audio != nullptr)
	{
		delete _audio;
		_audio = nullptr;
	}

	if (_graphics != nullptr)
	{
		delete _graphics;
		_graphics = nullptr;
	}

	if (_time != nullptr)
	{
		delete _time;
		_time = nullptr;
	}

	if (_application != nullptr)
	{
		delete _application;
		_application = nullptr;
	}
}


/// <summary>
/// Load game data and resource.
/// </summary>
/// <param name="hInstance">- Process handler, pass by WinMain.</param>
/// <param name="gameDataPath">- Game data file path.</param>
void CGame::Load(HINSTANCE hInstance, std::string gameDataPath)
{
	/* Read file */
	pugi::xml_document gameDataDoc;
	gameDataDoc.load_file(gameDataPath.c_str());


	/* Game settings */
	pugi::xml_node gameSettingsNode = gameDataDoc.child("GameData").child("GameSettings");
	_framePerSecond = gameSettingsNode.attribute("framePerSecond").as_uint();


	/* Framework */
	_application->CreateGameWindow
	(
		hInstance,
		std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(
			gameSettingsNode.attribute("title").as_string()
		),
		gameSettingsNode.attribute("windowWidth").as_uint(),
		gameSettingsNode.attribute("windowHeight").as_uint()
	);

	_graphics->Initialize(
		_application->GetWindow()
	);

	_input->Initialize(
		_application->GetInstance(),
		_application->GetWindow(),
		this
	);


	/* Texture */
	for (pugi::xml_node textureNode = gameDataDoc.child("GameData").child("Texture");
		textureNode;
		textureNode = textureNode.next_sibling("Texture"))
		_graphics->LoadTexture(
			textureNode.attribute("id").as_uint(),
			std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(
				textureNode.attribute("source").as_string()
			)
		);


	/* Sound Clip */
	for (pugi::xml_node soundClipNode = gameDataDoc.child("GameData").child("SoundClip");
		soundClipNode;
		soundClipNode = soundClipNode.next_sibling("SoundClip"))
	{
	}


	/* Button */
	for (pugi::xml_node buttonNode = gameDataDoc.child("GameData").child("Button");
		buttonNode;
		buttonNode = buttonNode.next_sibling("Button"))
		BindKey(buttonNode.attribute("keyCode").as_int());
}


#pragma region Game loop


/// <summary>
/// Run game loop.
/// </summary>
void CGame::Run()
{
	float msPerFrame = 1000.0f / _framePerSecond;
	float elapsedMs = 0;
	bool done = false;

	_time->Start();
	while (!done)
	{
		_time->Tick();
		elapsedMs += _time->GetElapsedMs();

		if (elapsedMs >= msPerFrame)
		{
			_input->ProcessKeyboard();
			Update(elapsedMs);
			Render();
			elapsedMs = 0;
		}
		else Sleep(DWORD(msPerFrame - elapsedMs));

		done = _application->HandleMessage();
	}
	Shutdown();
}

void CGame::Update(float elapsedMs)
{
}

void CGame::Render()
{
	_graphics->GetDevice()->ClearRenderTargetView(
		_graphics->GetRenderTargetView(),
		D3DXCOLOR(200.0f / 255, 200.0f / 255, 255.0f / 255, 0.0f)
	);
	_graphics->GetSpriteHandler()->Begin(D3DX10_SPRITE_SORT_TEXTURE);

	FLOAT NewBlendFactor[4] = { 0,0,0,0 };
	_graphics->GetDevice()->OMSetBlendState(_graphics->GetBlendStateAlpha(), NewBlendFactor, 0xffffffff);

	//Render calls

	_graphics->GetSpriteHandler()->End();
	_graphics->GetSwapChain()->Present(0, 0);
}


void CGame::Shutdown()
{
	_graphics->Shutdown();
	//_audio->Shutdown();
	_input->Shutdown();
}

#pragma endregion


#pragma region Button

void CGame::KeyState()
{
	_previousButtonState = _currentButtonState;
}


void CGame::OnKeyUp(int keyCode)
{
	_currentButtonState[keyCode] = false;
}


void CGame::OnKeyDown(int keyCode)
{
	_currentButtonState[keyCode] = true;
}


void CGame::BindKey(int keyCode)
{
	_previousButtonState[keyCode] = false;
	_currentButtonState[keyCode] = false;
}


bool CGame::IsKeyDown(int keyCode)
{
	return _currentButtonState[keyCode];
}


bool CGame::IsKeyPressed(int keyCode)
{
	return
		!_previousButtonState[keyCode]
		&& _currentButtonState[keyCode];
}


bool CGame::IsKeyReleased(int keyCode)
{
	return
		_previousButtonState[keyCode]
		&& !_currentButtonState[keyCode];
}

#pragma endregion


#pragma region Scene

#pragma endregion


#pragma region GameObject

#pragma endregion
