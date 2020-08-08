#ifndef __FONT_H__
#define __FONT_H__

#include "../../Include.h"
#include "../../Framework/Graphics.h"

struct Font
{
	Font();
	~Font();
};

class Fonts
{
private:
	pGraphics graphics;
	unordered_map<string, pFont> fonts;

public:
	Fonts();
	~Fonts();

	void Add();
	pFont Get();
};

#endif // !__FONT_H__