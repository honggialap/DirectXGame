#pragma once
#ifndef __PHYSICS_H__
#define __PHYSICS_H__

#include "../Include.h"

class Body
{
public:
	pGameObject gameObject;

	double mass;
	bool dynamicBody;
};

#endif // !__PHYSICS_H__
