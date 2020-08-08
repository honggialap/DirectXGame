#include "Viewport.h"

Viewport::Viewport()
{
	left = 0;
	top = 0;
	right = 0;
	bottom = 0;
}

Viewport::~Viewport()
{
}

void Viewport::SetBound(int left, int top, int right, int bottom)
{
	this->left = left;
	this->top = top;
	this->right = right;
	this->bottom = bottom;
}

