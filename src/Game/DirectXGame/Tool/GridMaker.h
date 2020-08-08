#ifndef __GRID_MAKER_H__
#define __GRID_MAKER_H__

#include "../Library/pugixml/pugixml.hpp"
#include <string>

using namespace std;
using namespace pugi;

class GridMaker
{
public:
	void MakeGrid(string source);
};
typedef GridMaker* pGridMaker;

#endif // !__GRID_MAKER_H__