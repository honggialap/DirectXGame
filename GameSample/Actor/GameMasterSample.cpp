#include "GameMasterSample.h"
#include "../GameSample.h"
#include "../Engine/Debug.h"

void CGameMasterSample::Load()
{
}

void CGameMasterSample::Start()
{
	CGameObject::Start();

	sceneId = 1;
	nextSceneId = 1;
	_game->PlayScene(1);
}

void CGameMasterSample::Update(float elapsedMs)
{
	if (!_start) Start();
	
	if (_game->IsKeyDown(203))
		_game->MoveCameraBy(-1, 0);
	else if (_game->IsKeyDown(205))
		_game->MoveCameraBy(1, 0);

	if (_game->IsKeyDown(200))
		_game->MoveCameraBy(0, 1);
	else if (_game->IsKeyDown(208))
		_game->MoveCameraBy(0, -1);

	if (_game->IsKeyDown(2)) SwitchScene(1);
	if (_game->IsKeyDown(3)) SwitchScene(2);

	if (loadFrame)
	{
		_game->PlayScene(sceneId);
		loadFrame = false;
	}

	if (nextSceneId != sceneId)
	{
		_game->StopScene(sceneId);
		sceneId = nextSceneId;
		loadFrame = true;
	}
}

void CGameMasterSample::Render()
{
}

void CGameMasterSample::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
}

void CGameMasterSample::SwitchScene(unsigned int sceneId)
{
	nextSceneId = sceneId;
}
