#ifndef __VIEWPORT_H__
#define __VIEWPORT_H__

#include "../../../Include.h"

class Viewport
{
public:
	int left, top, right, bottom;

	Viewport();
	~Viewport();

	void SetBound(int left, int top, int right, int bottom);
	int GetWidth() { return right - left + 1; }
	int GetHeight() { return bottom - top + 1; }
};

#endif // !__VIEWPORT_H__