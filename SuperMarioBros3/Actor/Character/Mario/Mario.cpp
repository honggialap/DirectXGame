#pragma region INCLUDE
#include "Mario.h"
#include "../../../SuperMarioBros3.h"

#include "../../Prop/Platform/Platform.h"

#include "../../../Engine/Framework/Debug.h"
#pragma endregion

void CMario::Load()
{
	CGameObject::Load();

	/* Read file */
	pugi::xml_document prefab;
	prefab.load_file(_source.c_str());

	/* Command */
	pugi::xml_node bindingCommandNode = prefab.child("Prefab").child("Command");
	LEFT = bindingCommandNode.attribute("LEFT").as_int();
	UP = bindingCommandNode.attribute("UP").as_int();
	RIGHT = bindingCommandNode.attribute("RIGHT").as_int();
	DOWN = bindingCommandNode.attribute("DOWN").as_int();
	ACTION = bindingCommandNode.attribute("ACTION").as_int();
	JUMP = bindingCommandNode.attribute("JUMP").as_int();

	/* Small Body */
	pugi::xml_node smallBodyNode = prefab.child("Prefab").child("SmallBody");
	_renderSmallBody = smallBodyNode.attribute("render").as_bool();
	SMALL_BODY_WIDTH = smallBodyNode.attribute("width").as_float();
	SMALL_BODY_HEIGHT = smallBodyNode.attribute("height").as_float();
	SMALL_BODY_OFFSETX = smallBodyNode.attribute("offsetX").as_float();
	SMALL_BODY_OFFSETY = smallBodyNode.attribute("offsetY").as_float();

	/* Large Body */
	pugi::xml_node largeBodyNode = prefab.child("Prefab").child("LargeBody");
	_renderLargeBody = largeBodyNode.attribute("render").as_bool();
	LARGE_BODY_WIDTH = largeBodyNode.attribute("width").as_float();
	LARGE_BODY_HEIGHT = largeBodyNode.attribute("height").as_float();
	LARGE_BODY_OFFSETX = largeBodyNode.attribute("offsetX").as_float();
	LARGE_BODY_OFFSETY = largeBodyNode.attribute("offsetY").as_float();

	/* Movement Stats */
	pugi::xml_node movementStatsNode = prefab.child("Prefab").child("MovementStats");
	GRAVITY = movementStatsNode.attribute("GRAVITY").as_float();
	DRAG = movementStatsNode.attribute("DRAG").as_float();

	WALK_ACCELERATION = movementStatsNode.attribute("WALK_ACCELERATION").as_float();
	WALK_SPEED_LIMIT = movementStatsNode.attribute("WALK_SPEED_LIMIT").as_float();

	RUN_ACCELERATION = movementStatsNode.attribute("RUN_ACCELERATION").as_float();
	RUN_SPEED_LIMIT = movementStatsNode.attribute("RUN_SPEED_LIMIT").as_float();

	FULL_ACCELERATION = movementStatsNode.attribute("FULL_ACCELERATION").as_float();
	FULL_SPEED_LIMIT = movementStatsNode.attribute("FULL_SPEED_LIMIT").as_float();

	MOMENTUM_INCREASE_RATE = movementStatsNode.attribute("MOMENTUM_INCREASE_RATE").as_float();
	MOMENTUM_DECREASE_RATE = movementStatsNode.attribute("MOMENTUM_DECREASE_RATE").as_float();
	MOMENTUM_LIMIT = movementStatsNode.attribute("MOMENTUM_LIMIT").as_float();

	JUMP_FORCE = movementStatsNode.attribute("JUMP_FORCE").as_float();
	FULL_SPEED_JUMP_FORCE = movementStatsNode.attribute("FULL_SPEED_JUMP_FORCE").as_float();
	JUMP_LIMIT = movementStatsNode.attribute("JUMP_LIMIT").as_float();

	IDLE_THRESHOLD = movementStatsNode.attribute("IDLE_THRESHOLD").as_float();	
}

void CMario::Start()
{
	CGameObject::Start();
}

void CMario::Update(float elapsedMs)
{
	if (!_start) Start();
	CameraControl();

	_vy -= GRAVITY * elapsedMs;
	if (_ground) _vx *= DRAG;

	_momentum -= MOMENTUM_DECREASE_RATE * elapsedMs;
	if (_momentum < 0) _momentum = 0;

	std::vector<pGameObject> collidables = _game->GetLocal(_id);
	_collider->Process(elapsedMs, &collidables);

	HandleAction(elapsedMs);

	DebugOut(L"vx %f | ", _vx);
	DebugOut(L"momentum %f \n", _momentum);
}

void CMario::Render()
{
	if (_renderSmallBody) _sprites[SPR_MARIO_S_BBOX]->Render(_x, _y);
	if (_renderLargeBody) _sprites[SPR_MARIO_L_BBOX]->Render(_x, _y);

	switch (_action)
	{
	case CMario::EAction::IDLE:
	{
		switch (_power)
		{
		case CMario::EPower::SMALL:
		{
			if (_left)	_sprites[SPR_MARIO_S_IDLE_LEFT]->Render(_x, _y);
			else		_sprites[SPR_MARIO_S_IDLE_RIGHT]->Render(_x, _y);
		}
		break;
		case CMario::EPower::LARGE:
		{
			if (_left)	_sprites[SPR_MARIO_L_IDLE_LEFT]->Render(_x, _y);
			else		_sprites[SPR_MARIO_L_IDLE_RIGHT]->Render(_x, _y);
		}
		break;
		case CMario::EPower::FIRE:
		{
			if (_left)	_sprites[SPR_MARIO_F_IDLE_LEFT]->Render(_x, _y);
			else		_sprites[SPR_MARIO_F_IDLE_RIGHT]->Render(_x, _y);
		}
		break;
		case CMario::EPower::RACCOON:
		{
			if (_left)	_sprites[SPR_MARIO_R_IDLE_LEFT]->Render(_x, _y);
			else		_sprites[SPR_MARIO_R_IDLE_RIGHT]->Render(_x, _y);
		}
		break;
		}
	}
	break;

	case CMario::EAction::WALK:
	{
		switch (_power)
		{
		case CMario::EPower::SMALL:
		{
			if (_left)	_animations[ANI_MARIO_S_WALK_LEFT]->Render(_x, _y);
			else		_animations[ANI_MARIO_S_WALK_RIGHT]->Render(_x, _y);
		}
		break;
		case CMario::EPower::LARGE:
		{
			if (_left)	_animations[ANI_MARIO_L_WALK_LEFT]->Render(_x, _y);
			else		_animations[ANI_MARIO_L_WALK_RIGHT]->Render(_x, _y);
		}
		break;
		case CMario::EPower::FIRE:
		{
			if (_left)	_animations[ANI_MARIO_F_WALK_LEFT]->Render(_x, _y);
			else		_animations[ANI_MARIO_F_WALK_RIGHT]->Render(_x, _y);
		}
		break;
		case CMario::EPower::RACCOON:
		{
			if (_left)	_animations[ANI_MARIO_R_WALK_LEFT]->Render(_x, _y);
			else		_animations[ANI_MARIO_R_WALK_RIGHT]->Render(_x, _y);
		}
		break;
		}
	}
	break;

	case CMario::EAction::RUN:
	{
		switch (_power)
		{
		case CMario::EPower::SMALL:
		{
			if (_fullSpeed)
			{
				if (_left)	_animations[ANI_MARIO_S_RUN_LEFT]->Render(_x, _y);
				else		_animations[ANI_MARIO_S_RUN_RIGHT]->Render(_x, _y);
			}
			else
			{
				if (_left)	_animations[ANI_MARIO_S_WALK_LEFT]->Render(_x, _y);
				else		_animations[ANI_MARIO_S_WALK_RIGHT]->Render(_x, _y);

			}
		}
		break;
		case CMario::EPower::LARGE:
		{
			if (_fullSpeed)
			{
				if (_left)	_animations[ANI_MARIO_L_RUN_LEFT]->Render(_x, _y);
				else		_animations[ANI_MARIO_L_RUN_RIGHT]->Render(_x, _y);
			}
			else
			{
				if (_left)	_animations[ANI_MARIO_L_WALK_LEFT]->Render(_x, _y);
				else		_animations[ANI_MARIO_L_WALK_RIGHT]->Render(_x, _y);
			}
		}
		break;
		case CMario::EPower::FIRE:
		{
			if (_fullSpeed)
			{
				if (_left)	_animations[ANI_MARIO_F_RUN_LEFT]->Render(_x, _y);
				else		_animations[ANI_MARIO_F_RUN_RIGHT]->Render(_x, _y);
			}
			else
			{
				if (_left)	_animations[ANI_MARIO_F_WALK_LEFT]->Render(_x, _y);
				else		_animations[ANI_MARIO_F_WALK_RIGHT]->Render(_x, _y);
			}
		}
		break;
		case CMario::EPower::RACCOON:
		{
			if (_fullSpeed)
			{
				if (_left)	_animations[ANI_MARIO_R_RUN_LEFT]->Render(_x, _y);
				else		_animations[ANI_MARIO_R_RUN_RIGHT]->Render(_x, _y);
			}
			else
			{
				if (_left)	_animations[ANI_MARIO_R_WALK_LEFT]->Render(_x, _y);
				else		_animations[ANI_MARIO_R_WALK_RIGHT]->Render(_x, _y);
			}
		}
		break;
		}
	}
	break;

	case CMario::EAction::JUMP:
	{
		switch (_power)
		{
		case CMario::EPower::SMALL:
		{
			if (_fullSpeed)
			{
				if (_left)	_sprites[SPR_MARIO_S_FLY_LEFT]->Render(_x, _y);
				else		_sprites[SPR_MARIO_S_FLY_RIGHT]->Render(_x, _y);
			}
			else
			{
				if (_left)	_sprites[SPR_MARIO_S_JUMP_LEFT]->Render(_x, _y);
				else		_sprites[SPR_MARIO_S_JUMP_RIGHT]->Render(_x, _y);
			}
		}
		break;
		case CMario::EPower::LARGE:
		{
			if (_fullSpeed)
			{
				if (_left)	_sprites[SPR_MARIO_L_FLY_LEFT]->Render(_x, _y);
				else		_sprites[SPR_MARIO_L_FLY_RIGHT]->Render(_x, _y);
			}
			else
			{
				if (_left)	_sprites[SPR_MARIO_L_JUMP_LEFT]->Render(_x, _y);
				else		_sprites[SPR_MARIO_L_JUMP_RIGHT]->Render(_x, _y);
			}
		}
		break;
		case CMario::EPower::FIRE:
		{
			if (_fullSpeed)
			{
				if (_left)	_sprites[SPR_MARIO_F_FLY_LEFT]->Render(_x, _y);
				else		_sprites[SPR_MARIO_F_FLY_RIGHT]->Render(_x, _y);
			}
			else
			{
				if (_left)	_sprites[SPR_MARIO_F_JUMP_LEFT]->Render(_x, _y);
				else		_sprites[SPR_MARIO_F_JUMP_RIGHT]->Render(_x, _y);
			}
		}
		break;
		case CMario::EPower::RACCOON:
		{
			if (_fullSpeed)
			{
				if (_left)	_sprites[SPR_MARIO_R_FLY1_LEFT]->Render(_x, _y);
				else		_sprites[SPR_MARIO_R_FLY1_RIGHT]->Render(_x, _y);
			}
			else
			{
				if (_left)	_sprites[SPR_MARIO_R_JUMP_LEFT]->Render(_x, _y);
				else		_sprites[SPR_MARIO_R_JUMP_RIGHT]->Render(_x, _y);
			}
		}
		break;
		}
	}
	break;

	}
}

#pragma region STATE MACHINE

void CMario::HandleAction(float elapsedMs)
{
	switch (_action)
	{
	case CMario::EAction::IDLE:
		Idle(elapsedMs);
		break;

	case CMario::EAction::WALK:
		Walk(elapsedMs);
		break;

	case CMario::EAction::RUN:
		Run(elapsedMs);
		break;

	case CMario::EAction::JUMP:
		Jump(elapsedMs);
		break;
	}
}

void CMario::Idle(float elapsedMs)
{
	switch (_actionStage)
	{
	case CMario::EActionStage::ENTRY:
	{
		_run = false;
	}
	_actionStage = EActionStage::PROGRESS;
	break;

	case CMario::EActionStage::PROGRESS:
	{
		if (_game->IsKeyDown(LEFT) && !_game->IsKeyDown(RIGHT))
		{
			_left = true;
			if (_game->IsKeyDown(ACTION)) SetNextAction(EAction::RUN);
			else SetNextAction(EAction::WALK);
		}
		else if (_game->IsKeyDown(RIGHT) && !_game->IsKeyDown(LEFT))
		{
			_left = false;
			if (_game->IsKeyDown(ACTION)) SetNextAction(EAction::RUN);
			else SetNextAction(EAction::WALK);
		}

		if (_ground && _game->IsKeyPressed(JUMP))
		{
			SetNextAction(EAction::JUMP);
		}
	}
	break;

	case CMario::EActionStage::EXIT:
	{

	}
	NextAction();
	break;
	}
}

void CMario::Walk(float elapsedMs)
{
	switch (_actionStage)
	{
	case CMario::EActionStage::ENTRY:
	{
		/* Animation Start */
		switch (_power)
		{
		case CMario::EPower::SMALL:
		{
			_animations[ANI_MARIO_S_WALK_LEFT]->Play(true);
			_animations[ANI_MARIO_S_WALK_RIGHT]->Play(true);
		}
		break;

		case CMario::EPower::LARGE:
		{
			_animations[ANI_MARIO_L_WALK_LEFT]->Play(true);
			_animations[ANI_MARIO_L_WALK_RIGHT]->Play(true);
		}
		break;

		case CMario::EPower::FIRE:
		{
			_animations[ANI_MARIO_F_WALK_LEFT]->Play(true);
			_animations[ANI_MARIO_F_WALK_RIGHT]->Play(true);
		}
		break;

		case CMario::EPower::RACCOON:
		{
			_animations[ANI_MARIO_R_WALK_LEFT]->Play(true);
			_animations[ANI_MARIO_R_WALK_RIGHT]->Play(true);
		}
		break;
		}
		_run = false;
	}
	_actionStage = EActionStage::PROGRESS;
	break;

	case CMario::EActionStage::PROGRESS:
	{
		if (_game->IsKeyDown(LEFT) && !_game->IsKeyDown(RIGHT))
		{
			_left = true;
			if (_game->IsKeyDown(ACTION)) SetNextAction(EAction::RUN);
			else
			{
				if (_vx > -WALK_SPEED_LIMIT)
				{
					_vx -= WALK_ACCELERATION * elapsedMs;
					if (_vx < -WALK_SPEED_LIMIT) _vx = -WALK_SPEED_LIMIT;
				}
				else _vx -= WALK_ACCELERATION * elapsedMs;
				_walkSpeedFactor = abs(_vx / RUN_SPEED_LIMIT);
			}
		}
		else if (_game->IsKeyDown(RIGHT) && !_game->IsKeyDown(LEFT))
		{
			_left = false;
			if (_game->IsKeyDown(ACTION)) SetNextAction(EAction::RUN);
			else
			{
				if (_vx < WALK_SPEED_LIMIT)
				{
					_vx += WALK_ACCELERATION * elapsedMs;
					if (_vx > WALK_SPEED_LIMIT) _vx = WALK_SPEED_LIMIT;
				}
				else _vx += WALK_ACCELERATION * elapsedMs;
				_walkSpeedFactor = abs(_vx / RUN_SPEED_LIMIT);
			}
		}

		if ((_left && _vx > -IDLE_THRESHOLD) || (!_left && _vx < IDLE_THRESHOLD)) 
			SetNextAction(EAction::IDLE);

		if (_ground && _game->IsKeyPressed(JUMP))
			SetNextAction(EAction::JUMP);

		/* Animation Update */
		switch (_power)
		{
		case CMario::EPower::SMALL:
		{
			_animations[ANI_MARIO_S_WALK_LEFT]->Update(elapsedMs * _walkSpeedFactor);
			_animations[ANI_MARIO_S_WALK_RIGHT]->Update(elapsedMs * _walkSpeedFactor);
		}
		break;

		case CMario::EPower::LARGE:
		{
			_animations[ANI_MARIO_L_WALK_LEFT]->Update(elapsedMs * _walkSpeedFactor);
			_animations[ANI_MARIO_L_WALK_RIGHT]->Update(elapsedMs * _walkSpeedFactor);
		}
		break;

		case CMario::EPower::FIRE:
		{
			_animations[ANI_MARIO_F_WALK_LEFT]->Update(elapsedMs * _walkSpeedFactor);
			_animations[ANI_MARIO_F_WALK_RIGHT]->Update(elapsedMs * _walkSpeedFactor);
		}
		break;

		case CMario::EPower::RACCOON:
		{
			_animations[ANI_MARIO_R_WALK_LEFT]->Update(elapsedMs * _walkSpeedFactor);
			_animations[ANI_MARIO_R_WALK_RIGHT]->Update(elapsedMs * _walkSpeedFactor);
		}
		break;
		}
	}
	break;

	case CMario::EActionStage::EXIT:
	{
		/* Animation Stop */
		switch (_power)
		{
		case CMario::EPower::SMALL:
		{
			_animations[ANI_MARIO_S_WALK_LEFT]->Stop();
			_animations[ANI_MARIO_S_WALK_RIGHT]->Stop();
		}
		break;

		case CMario::EPower::LARGE:
		{
			_animations[ANI_MARIO_L_WALK_LEFT]->Stop();
			_animations[ANI_MARIO_L_WALK_RIGHT]->Stop();
		}
		break;

		case CMario::EPower::FIRE:
		{
			_animations[ANI_MARIO_F_WALK_LEFT]->Stop();
			_animations[ANI_MARIO_F_WALK_RIGHT]->Stop();
		}
		break;

		case CMario::EPower::RACCOON:
		{
			_animations[ANI_MARIO_R_WALK_LEFT]->Stop();
			_animations[ANI_MARIO_R_WALK_RIGHT]->Stop();
		}
		break;
		}
	}
	NextAction();
	break;
	}
}

void CMario::Run(float elapsedMs)
{
	switch (_actionStage)
	{
	case CMario::EActionStage::ENTRY:
	{
		switch (_power)
		{
		case CMario::EPower::SMALL:
		{
			_animations[ANI_MARIO_S_WALK_LEFT]->Play(true);
			_animations[ANI_MARIO_S_WALK_RIGHT]->Play(true);
			_animations[ANI_MARIO_S_RUN_LEFT]->Play(true);
			_animations[ANI_MARIO_S_RUN_RIGHT]->Play(true);
		}
		break;

		case CMario::EPower::LARGE:
		{
			_animations[ANI_MARIO_L_WALK_LEFT]->Play(true);
			_animations[ANI_MARIO_L_WALK_RIGHT]->Play(true);
			_animations[ANI_MARIO_L_RUN_LEFT]->Play(true);
			_animations[ANI_MARIO_L_RUN_RIGHT]->Play(true);
		}
		break;

		case CMario::EPower::FIRE:
		{
			_animations[ANI_MARIO_F_WALK_LEFT]->Play(true);
			_animations[ANI_MARIO_F_WALK_RIGHT]->Play(true);
			_animations[ANI_MARIO_F_RUN_LEFT]->Play(true);
			_animations[ANI_MARIO_F_RUN_RIGHT]->Play(true);
		}
		break;

		case CMario::EPower::RACCOON:
		{
			_animations[ANI_MARIO_R_WALK_LEFT]->Play(true);
			_animations[ANI_MARIO_R_WALK_RIGHT]->Play(true);
			_animations[ANI_MARIO_R_RUN_LEFT]->Play(true);
			_animations[ANI_MARIO_R_RUN_RIGHT]->Play(true);
		}
		break;
		}
		_run = true;
	}
	_actionStage = EActionStage::PROGRESS;
	break;

	case CMario::EActionStage::PROGRESS:
	{
		if (_vx != 0)
		{
			_momentum += MOMENTUM_INCREASE_RATE * elapsedMs;
			if (_momentum > MOMENTUM_LIMIT)
			{
				_momentum = MOMENTUM_LIMIT;
				_fullSpeed = true;
			}
			else
			{
				_fullSpeed = false;
			}
		}
		
		if (_game->IsKeyDown(LEFT) && !_game->IsKeyDown(RIGHT))
		{
			_left = true;
			if (!_game->IsKeyDown(ACTION)) SetNextAction(EAction::WALK);
			else
			{
				if (_fullSpeed)
				{
					if (_vx > -FULL_SPEED_LIMIT)
					{
						_vx -= FULL_ACCELERATION * elapsedMs;
						if (_vx < -FULL_SPEED_LIMIT) _vx = -FULL_SPEED_LIMIT;
					}
					else _vx -= FULL_ACCELERATION * elapsedMs;
				}
				else
				{
					if (_vx > -RUN_SPEED_LIMIT)
					{
						_vx -= RUN_ACCELERATION * elapsedMs;
						if (_vx < -RUN_SPEED_LIMIT) _vx = -RUN_SPEED_LIMIT;
					}
					else _vx -= RUN_ACCELERATION * elapsedMs;
				}
				_walkSpeedFactor = abs(_vx / WALK_SPEED_LIMIT);
			}
		}
		else if (_game->IsKeyDown(RIGHT) && !_game->IsKeyDown(LEFT))
		{
			_left = false;
			if (!_game->IsKeyDown(ACTION)) SetNextAction(EAction::WALK);
			else
			{
				if (_fullSpeed)
				{
					if (_vx < FULL_SPEED_LIMIT)
					{
						_vx += FULL_ACCELERATION * elapsedMs;
						if (_vx > FULL_SPEED_LIMIT) _vx = FULL_SPEED_LIMIT;
					}
					else _vx += FULL_ACCELERATION * elapsedMs;

				}
				else
				{
					if (_vx < RUN_SPEED_LIMIT)
					{
						_vx += RUN_ACCELERATION * elapsedMs;
						if (_vx > RUN_SPEED_LIMIT) _vx = RUN_SPEED_LIMIT;
					}
					else _vx += RUN_ACCELERATION * elapsedMs;
				}
				_walkSpeedFactor = abs(_vx / WALK_SPEED_LIMIT);
			}
		}

		if ((_left && _vx > -IDLE_THRESHOLD) || (!_left && _vx < IDLE_THRESHOLD))
			SetNextAction(EAction::IDLE);

		if (_ground && _game->IsKeyPressed(JUMP))
			SetNextAction(EAction::JUMP);

		/* Animation Update */
		switch (_power)
		{
		case CMario::EPower::SMALL:
		{
			_animations[ANI_MARIO_S_WALK_LEFT]->Update(elapsedMs * _walkSpeedFactor);
			_animations[ANI_MARIO_S_WALK_RIGHT]->Update(elapsedMs * _walkSpeedFactor);
			_animations[ANI_MARIO_S_RUN_LEFT]->Update(elapsedMs * _walkSpeedFactor);
			_animations[ANI_MARIO_S_RUN_RIGHT]->Update(elapsedMs * _walkSpeedFactor);
		}
		break;

		case CMario::EPower::LARGE:
		{
			_animations[ANI_MARIO_L_WALK_LEFT]->Update(elapsedMs * _walkSpeedFactor);
			_animations[ANI_MARIO_L_WALK_RIGHT]->Update(elapsedMs * _walkSpeedFactor);
			_animations[ANI_MARIO_L_RUN_LEFT]->Update(elapsedMs* _walkSpeedFactor);
			_animations[ANI_MARIO_L_RUN_RIGHT]->Update(elapsedMs* _walkSpeedFactor);
		}
		break;

		case CMario::EPower::FIRE:
		{
			_animations[ANI_MARIO_F_WALK_LEFT]->Update(elapsedMs * _walkSpeedFactor);
			_animations[ANI_MARIO_F_WALK_RIGHT]->Update(elapsedMs * _walkSpeedFactor);
			_animations[ANI_MARIO_F_RUN_LEFT]->Update(elapsedMs* _walkSpeedFactor);
			_animations[ANI_MARIO_F_RUN_RIGHT]->Update(elapsedMs* _walkSpeedFactor);
		}
		break;

		case CMario::EPower::RACCOON:
		{
			_animations[ANI_MARIO_R_WALK_LEFT]->Update(elapsedMs * _walkSpeedFactor);
			_animations[ANI_MARIO_R_WALK_RIGHT]->Update(elapsedMs * _walkSpeedFactor);
			_animations[ANI_MARIO_R_RUN_LEFT]->Update(elapsedMs* _walkSpeedFactor);
			_animations[ANI_MARIO_R_RUN_RIGHT]->Update(elapsedMs* _walkSpeedFactor);
		}
		break;
		}
	}
	break;

	case CMario::EActionStage::EXIT:
	{
		/* Animation Stop */
		switch (_power)
		{
		case CMario::EPower::SMALL:
		{
			_animations[ANI_MARIO_S_WALK_LEFT]->Stop();
			_animations[ANI_MARIO_S_WALK_RIGHT]->Stop();
			_animations[ANI_MARIO_S_RUN_LEFT]->Stop();
			_animations[ANI_MARIO_S_RUN_RIGHT]->Stop();
		}
		break;

		case CMario::EPower::LARGE:
		{
			_animations[ANI_MARIO_L_WALK_LEFT]->Stop();
			_animations[ANI_MARIO_L_WALK_RIGHT]->Stop();
			_animations[ANI_MARIO_L_RUN_LEFT]->Stop();
			_animations[ANI_MARIO_L_RUN_RIGHT]->Stop();
		}
		break;

		case CMario::EPower::FIRE:
		{
			_animations[ANI_MARIO_F_WALK_LEFT]->Stop();
			_animations[ANI_MARIO_F_WALK_RIGHT]->Stop();
			_animations[ANI_MARIO_F_RUN_LEFT]->Stop();
			_animations[ANI_MARIO_F_RUN_RIGHT]->Stop();
		}
		break;

		case CMario::EPower::RACCOON:
		{
			_animations[ANI_MARIO_R_WALK_LEFT]->Stop();
			_animations[ANI_MARIO_R_WALK_RIGHT]->Stop();
			_animations[ANI_MARIO_R_RUN_LEFT]->Stop();
			_animations[ANI_MARIO_R_RUN_RIGHT]->Stop();
		}
		break;
		}
	}
	NextAction();
	break;
	}
}

void CMario::Jump(float elapsedMs)
{
	switch (_actionStage)
	{
	case CMario::EActionStage::ENTRY:
	{
		_fall = false;
		_ground = false;
		_jumpLimit = JUMP_LIMIT;
		if(_fullSpeed) _vy = FULL_SPEED_JUMP_FORCE;
		else _vy = JUMP_FORCE;
	}
	_actionStage = EActionStage::PROGRESS;
	break;

	case CMario::EActionStage::PROGRESS:
	{
		if (!_fall)
		{			
			if (_game->IsKeyReleased(JUMP)) _fall = true;

			if (_game->IsKeyDown(JUMP) && _jumpLimit > 0)
			{
				_jumpLimit -= elapsedMs;
				if (_fullSpeed) _vy = FULL_SPEED_JUMP_FORCE;
				else _vy = JUMP_FORCE;
			}
			else _fall = true;
		}

		if (_game->IsKeyDown(LEFT))
		{
			_left = true;

			if (_fullSpeed)
			{
				if (_vx > -FULL_SPEED_LIMIT) _vx -= WALK_ACCELERATION * elapsedMs;
				else _vx = -FULL_SPEED_LIMIT;
			}
			else if (_run)
			{
				if (_vx > -RUN_SPEED_LIMIT) _vx -= WALK_ACCELERATION * elapsedMs;
				else _vx = -RUN_SPEED_LIMIT;
			}
			else if (!_run && !_fullSpeed)
			{
				if (_vx > -WALK_SPEED_LIMIT) _vx -= WALK_ACCELERATION * elapsedMs;
				else _vx = -WALK_SPEED_LIMIT;
			}
		}
		else if (_game->IsKeyDown(RIGHT))
		{
			_left = false;

			if (_fullSpeed)
			{
				if (_vx < FULL_SPEED_LIMIT) _vx += WALK_ACCELERATION * elapsedMs;
				else _vx = FULL_SPEED_LIMIT;
			}
			else if (_run)
			{
				if (_vx < RUN_SPEED_LIMIT) _vx += WALK_ACCELERATION * elapsedMs;
				else _vx = RUN_SPEED_LIMIT;
			}
			else if (!_run && !_fullSpeed)
			{
				if (_vx < WALK_SPEED_LIMIT) _vx += WALK_ACCELERATION * elapsedMs;
				else _vx = WALK_SPEED_LIMIT;
			}
		}

		if (_ground) SetNextAction(EAction::IDLE);
	}
	break;

	case CMario::EActionStage::EXIT:
	{
	}
	NextAction();
	break;
	}
}

void CMario::CameraControl()
{
	_game->MoveCameraTo(
		_x - _game->GetGraphics()->GetBackBufferWidth() / 2,
		_y + _game->GetGraphics()->GetBackBufferHeight() / 2
	);
}

#pragma endregion

#pragma region COLLISION

int CMario::IsCollidable()
{
	switch (_action)
	{
	case CMario::EAction::IDLE:
	case CMario::EAction::WALK:
	case CMario::EAction::RUN:
	case CMario::EAction::JUMP:
		return 1;
		break;

	default:
		return 0;
	}
}

int CMario::IsBlocking()
{
	return 0;
}

void CMario::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	switch (_power)
	{
	case CMario::EPower::SMALL:
	{
		switch (_action)
		{
		case CMario::EAction::IDLE:
		case CMario::EAction::WALK:
		case CMario::EAction::RUN:
		case CMario::EAction::JUMP:
			left = _x + SMALL_BODY_OFFSETX - (SMALL_BODY_WIDTH / 2);
			right = _x + SMALL_BODY_OFFSETX + (SMALL_BODY_WIDTH / 2);
			top = _y + SMALL_BODY_OFFSETY + (SMALL_BODY_HEIGHT / 2);
			bottom = _y + SMALL_BODY_OFFSETY - (SMALL_BODY_HEIGHT / 2);
			break;
		}
	}
	break;
	case CMario::EPower::LARGE:
	case CMario::EPower::FIRE:
	case CMario::EPower::RACCOON:
		switch (_action)
		{
		case CMario::EAction::IDLE:
		case CMario::EAction::WALK:
		case CMario::EAction::RUN:
		case CMario::EAction::JUMP:
			left = _x + LARGE_BODY_OFFSETX - (LARGE_BODY_WIDTH / 2);
			right = _x + LARGE_BODY_OFFSETX + (LARGE_BODY_WIDTH / 2);
			top = _y + LARGE_BODY_OFFSETY + (LARGE_BODY_HEIGHT / 2);
			bottom = _y + LARGE_BODY_OFFSETY - (LARGE_BODY_HEIGHT / 2);
			break;
		}
		break;
	}
}

void CMario::OnNoCollision(float elapsedMs)
{
	_x += _vx * elapsedMs;
	_y += _vy * elapsedMs;
}

void CMario::OnCollisionWith(pCollision collision)
{
	if (dynamic_cast<pPlatform>(collision->_target))
		OnCollisionWithPlatform(collision);
}

void CMario::OnCollisionWithPlatform(pCollision collision)
{
	auto platform = dynamic_cast<pPlatform>(collision->_target);
	if (platform->_solid)
	{
		if (collision->_ny != 0 && collision->_target->IsBlocking())
		{
			_vy = 0;
			if (collision->_ny > 0) _ground = true;
		}

		if (collision->_nx != 0 && collision->_target->IsBlocking())
		{
			_vx = 0;
		}
	}
	else
	{
		if (collision->_ny != 0 && !collision->_target->IsBlocking())
		{
			float top = 0;
			float temp = 0;
			collision->_target->GetBoundingBox(temp, top, temp, temp);

			_y = top + BLOCK_PUSH_FACTOR;
			_vy = 0;
			_ground = true;
		}
	}
}

#pragma endregion