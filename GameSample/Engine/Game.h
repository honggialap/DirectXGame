#pragma once
#ifndef __GAME_H__
#define __GAME_H__

#pragma region INCLUDE
#include "Application.h"
#include "Time.h"
#include "Graphics.h"
#include "Input.h"
#include "Audio.h"
#include "pugixml.hpp"

#include "GameObject.h"

#include <map>
#include <vector>
#include <unordered_map>
#pragma endregion


/// <summary>
/// Handling scene.
/// </summary>
struct CScene
{
	bool _play;
	bool _load;
	std::string _source;
	std::vector<unsigned int> _gameObjects;

	CScene(std::string source)
	{
		_source = source;
		_load = false;
		_play = false;
	}
};
typedef CScene* pScene;


/// <summary>
/// Handling game loop.
/// </summary>
class CGame : public IKeyHandler
{
public:
	CGame();
	~CGame();


	/* Framework */
protected:
	pApplication _application = nullptr;
	pTime _time = nullptr;
	pGraphics _graphics = nullptr;
	pAudio _audio = nullptr;
	pInput _input = nullptr;

public:
	pApplication GetApplication() { return _application; }
	pTime GetTime() { return _time; }
	pGraphics GetGraphics() { return _graphics; }
	pAudio GetAudio() { return _audio; }
	pInput GetInput() { return _input; }


	/* Game loop */
protected:
	unsigned int _framePerSecond = 0;
	std::vector<unsigned int> _updateQueue;
	std::vector<unsigned int> _renderQueue;

public:
	void Load(HINSTANCE hInstance, std::string gameDataPath);
	void Run();
	void Update(float elapsedMs);
	void Render();
	void Shutdown();


	/* Camera */
protected:
	float _cameraX = 0;
	float _cameraY = 0;

public:
	void GetCamera(float& x, float& y) { x = _cameraX; y = _cameraY; }
	void MoveCameraTo(float x, float y) { _cameraX = x; _cameraY = y; }
	void MoveCameraBy(float x, float y) { _cameraX += x; _cameraY += y; }


	/* Button */
protected:
	std::map<int, bool> _currentButtonState;
	std::map<int, bool> _previousButtonState;

public:
	virtual void KeyState();
	virtual void OnKeyUp(int keyCode);
	virtual void OnKeyDown(int keyCode);

	void BindKey(int keyCode);
	bool IsKeyDown(int keyCode);
	bool IsKeyPressed(int keyCode);
	bool IsKeyReleased(int keyCode);


	/* Scene */
protected:
	std::map<unsigned int, pScene> _scene;

public:
	void PlayScene(unsigned int id);
	void StopScene(unsigned int id);
	void LoadScene();


	/* Game Object */
protected:
	unsigned int nextId = 0;
	std::unordered_map<unsigned int, pGameObject> _gameObjects;
	std::unordered_map<std::string, unsigned int> _dictionary;

public:
	pGameObject Create();
	pGameObject Get(unsigned int id);
	pGameObject Get(std::string name);
	void Purge();

	/* Grid */
protected:
	int _gridWidth = 0;
	int _gridHeight = 0;
	std::map<std::pair<int, int>, std::vector<unsigned int>> _grid;

public:

};
typedef CGame* pGame;

#endif // !__GAME_H__