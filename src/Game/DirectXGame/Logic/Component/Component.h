#pragma once
#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "../../Include.h"

class Component
{
public:
	pGameObject gameObject;
	enum Type
	{
		SpriteRenderer,
		Animator,
		Tilemap,
		TextRenderer,
		SoundSource,
		Physics
	};
	Type type;

	Component(pGameObject gameObject);
	virtual ~Component() = 0;
};

#endif // !__COMPONENT_H__