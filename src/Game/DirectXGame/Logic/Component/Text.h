#pragma once
#ifndef __TEXT_RENDERER_H__
#define __TEXT_RENDERER_H__

#include "../../Include.h"
#include "../../Framework/Resource.h"
#include "../../Framework/Content/Font.h"
#include "Component.h"
#include "../GameObject.h"

struct Text
{

};

class TextRenderer : public Component
{
public:
	TextRenderer(pGameObject gameObject);
	~TextRenderer();

	void Add();
	void Get();
	void Set();
	void Render();
};

#endif // !__TEXT_RENDERER_H__
