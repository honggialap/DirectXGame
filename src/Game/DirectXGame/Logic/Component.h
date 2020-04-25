#pragma once
#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "../Include.h"

enum class ComponentType
{
	Transform,
	Sprite,
	Animation,
	Body,
	Collider,
	Control,
	Camera
};

class Component
{
public:
	pGameObject gameObject;
	ComponentType componentType;

	void Attach(pGameObject gameObject);
	void Detach();
};

class Components
{
public:
	unordered_map<string, pComponent> components;
};

#endif // !__COMPONENT_H__