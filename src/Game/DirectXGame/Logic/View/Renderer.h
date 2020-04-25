#pragma once
#ifndef __RENDERER_H__
#define __RENDERER_H__

//scene - view component
class Renderer
{
	//pScene scene;
	//pCamera camera;
	//pGraphics graphics;
};

typedef Renderer* pRenderer;

class Renderable
{
public:
	pRenderer renderer;
	virtual void Render() = 0;
};

#endif // !__RENDERER_H__
