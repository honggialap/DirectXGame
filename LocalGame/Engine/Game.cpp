#include "Game.h"
#include "Debug.h"
#include <codecvt>
#include <locale>

CGame::CGame()
{
	_application = new CApplication();
	_time = new CTime();
}


CGame::~CGame()
{
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

	/* Framework initialize */
	_application->CreateGameWindow
	(
		hInstance,
		std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(
			gameSettingsNode.attribute("title").as_string()
		),
		gameSettingsNode.attribute("windowWidth").as_uint(),
		gameSettingsNode.attribute("windowHeight").as_uint()
	);
}


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
			DebugOut(L"Game Tick: %f \n", elapsedMs);
			elapsedMs = 0;
		}
		else Sleep(DWORD(msPerFrame - elapsedMs));
		
		done = _application->HandleMessage();
	}
}