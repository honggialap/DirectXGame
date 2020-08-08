#include "Component.h"

#pragma region Component

Component::Component(pGameObject gameObject)
{
	this->gameObject = gameObject;
}

Component::~Component()
{
	gameObject = nullptr;
}

#pragma endregion