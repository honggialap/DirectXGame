#include "Component.h"

void Component::Attach(pGameObject gameObject)
{
	this->gameObject = gameObject;
}

void Component::Detach()
{
	this->gameObject = nullptr;
}
