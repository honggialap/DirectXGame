#include "LocalPlayer.h"

LocalPlayer::LocalPlayer(pScene scene) : Player::Player(scene)
{
	type = Player::Type::Local;
	this->controller = new Controller();
	this->viewport = new Viewport();
}

LocalPlayer::~LocalPlayer()
{
	if (viewport != nullptr)
	{
		delete viewport;
		viewport = nullptr;
	}

	if (controller != nullptr)
	{
		delete controller;
		controller = nullptr;
	}

	scene = nullptr;
}
