#include "Component.h"

Component::Component()
{
}

Component::~Component()
{
}

void Component::Attach(pGameObject gameObject)	
{
	this->gameObject = gameObject;
}

void Component::Detach()
{
	this->gameObject = nullptr;
}

Components::Components(pGameObject gameObject)
{
	this->gameObject = gameObject;
}

Components::~Components()
{
	this->gameObject = nullptr;
}

void Components::Add(string id, pComponent component)
{
	components[id] = component;
}

pComponent Components::Get(string id)
{
	return components[id];
}

void Components::Remove(string id)
{
}

void Components::Clear()
{
}
