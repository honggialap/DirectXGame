#pragma once
#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include "../Include.h"
#include "Component.h"
#include "GameObject.h"

class Transform : public Component
{
public:
	pGameObject gameObject;
	
	D3DXVECTOR3 transform;

	Transform();
	~Transform();
};


#endif
