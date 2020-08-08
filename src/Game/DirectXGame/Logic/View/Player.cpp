#include "Player.h"

Player::Player(pScene scene)
{
	this->scene = scene;
}

Player::~Player()
{
	scene = nullptr;
}