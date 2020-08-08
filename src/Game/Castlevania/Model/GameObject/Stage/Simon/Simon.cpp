#include "Simon.h"

Simon::Simon(pScene scene) : GameObject(scene)
{
	playScene = dynamic_cast<pPlayScene>(scene);
	controller = dynamic_cast<pLocalPlayer>(playScene->players[0])->controller;
	source = "Castlevania\\Data\\GameObject\\Stage\\Simon\\Simon.xml";
}

Simon::~Simon()
{
	controller = nullptr;
	playScene = nullptr;
}

void Simon::Load()
{
	GameObject::Load();
}

void Simon::Unload()
{
	GameObject::Unload();
}

void Simon::Start()
{
	start = true;
	LoadStats();
}

void Simon::SetState(State state)
{
	this->state = state;

	switch (facing)
	{
	case Left:
		GetSpriteRenderer()->SetFlipSprite(SpriteRenderer::FlipSprite::None);
		GetSpriteRenderer()->SetFlipOffset(SpriteRenderer::FlipOffset::None);
		break;
	case Right:
		GetSpriteRenderer()->SetFlipSprite(SpriteRenderer::FlipSprite::Horizontal);
		GetSpriteRenderer()->SetFlipOffset(SpriteRenderer::FlipOffset::Horizontal);
		break;
	}

	switch (state)
	{
	case Simon::Idle:
		GetAnimator()->Play("idle");
		break;
		
	case Simon::Walk:
		GetAnimator()->Play("walk", true);
		break;
	
	case Simon::Crouch:
		GetAnimator()->Play("crouch");
		break;
	
	case Simon::Jump:
		GetAnimator()->Play("crouch");
		break;
	
	case Simon::Attack:
		//attackingTime = 300;
		//attacking = true;
		GetAnimator()->Play("attack");
		break;
	
	case Simon::SubAttack:
		//attackingTime = 300;
		//attacking = true;
		GetAnimator()->Play("attack");
		break;
	
	case Simon::CrouchAttack:
		GetAnimator()->Play("crouchAttack");
		//attackingTime = 300;
		//attacking = true;
		break;
	
	case Simon::Damaged:
		GetAnimator()->Play("hurt");
		//damaged = true;
		break;
	
	case Simon::PowerUp:
		break;
	
	case Simon::Dead:
		break;
	}
}

void Simon::Update(float elapsedMs)
{	
	if (!start) Start();

	switch (state)
	{
	case Simon::Idle:
		if (controller->IsButtonDown(Controller::Button::Left)) //&& grounded)
		{
			facing = Facing::Left;
			SetState(Walk);
		}
		else if (controller->IsButtonDown(Controller::Button::Right)) //&& grounded)
		{
			facing = Facing::Right;
			SetState(Walk);
		}

		if (controller->IsButtonDown(Controller::Button::Down))
			SetState(Crouch);

		if (controller->IsButtonDown(Controller::Button::Up)
			&& controller->IsButtonPressed(Controller::Button::B))
			SetState(SubAttack);
		else if (controller->IsButtonPressed(Controller::Button::B))
			SetState(Attack);
		break;

	case Simon::Walk:
	
		if ((facing == Left && !controller->IsButtonDown(Controller::Button::Left))
			|| (facing == Right && !controller->IsButtonDown(Controller::Button::Right)))
			//&& grounded)
			SetState(Idle);
		
		if (controller->IsButtonDown(Controller::Button::Down))
			SetState(Crouch);
		
		if (controller->IsButtonPressed(Controller::Button::A))
			//&& grounded)
			SetState(Jump);
		
		if (controller->IsButtonDown(Controller::Button::Up)
			&& controller->IsButtonPressed(Controller::Button::B))
			SetState(SubAttack);
		else if (controller->IsButtonPressed(Controller::Button::B))
			SetState(Attack);
		break;
	
	case Simon::Crouch:
		if (controller->IsButtonDown(Controller::Button::Left))
			facing = Facing::Left;
		else if (controller->IsButtonDown(Controller::Button::Right))
			facing = Facing::Right;
	
		if (!controller->IsButtonDown(Controller::Button::Down))
			SetState(Idle);
	
		if (controller->IsButtonPressed(Controller::Button::B))
			SetState(CrouchAttack);
		break;
	
	case Simon::Jump:
		if (controller->IsButtonDown(Controller::Button::Up)
			&& controller->IsButtonPressed(Controller::Button::B))
			SetState(SubAttack);
		else if (controller->IsButtonPressed(Controller::Button::B))
			SetState(CrouchAttack);
		break;
	
	case Simon::Attack:
		//if (attacking)
		//{
		//	attackingTime -= elapsedMs;
		//	if (attackingTime <= 0)
		//	{
		//		attacking = false;
		//		SetState(Idle);
		//	}
		//}
		break;
	
	case Simon::SubAttack:
		//if (attacking)
		//{
		//	attackingTime -= elapsedMs;
		//	if (attackingTime < 0)
		//	{
		//		attacking = false;
		//		SetState(Idle);
		//	}
		//}
		break;
	
	case Simon::CrouchAttack:
		//if (attacking)
		//{
		//	attackingTime -= elapsedMs;
		//	if (attackingTime < 0)
		//	{
		//		attacking = false;
		//		if (controller->IsButtonDown(Controller::Button::Down))
		//			SetState(Crouch);
		//		else SetState(Idle);
		//	}
		//}
		break;
	
	case Simon::Damaged:
		//if (!damaged) SetState(Idle);
		break;
	
	case Simon::PowerUp:
		break;
	
	case Simon::Dead:
		break;
	}


	//GetPhysics()->Update(elapsedMs);
	GetAnimator()->Update(elapsedMs);
}

void Simon::Render()
{
	GetAnimator()->Render();
}

void Simon::Collided(pCollision& collision)
{
	if (dynamic_cast<pSimon>(collision->gameObject))
	{
		collision->response = Collision::Block;
		if(collision->ny == -1) grounded = true;
	}
}

void Simon::SpawnedHandler(pGameObject gameObject)
{
}

void Simon::DestroyedHandler(pGameObject gameObject)
{
}

void Simon::SaveStats()
{
	xml_document prefabDoc;
	prefabDoc.load_file(source.c_str());
	//
	prefabDoc.save_file(source.c_str());
}

void Simon::LoadStats()
{
	xml_document prefabDoc;
	prefabDoc.load_file(source.c_str());
}

void Simon::ResetStats()
{
	xml_document prefabDoc;
	prefabDoc.load_file(source.c_str());
}

