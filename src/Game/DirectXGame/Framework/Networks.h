#pragma once
#ifndef __NETWORKS_H__
#define __NETWORKS_H__

#include "../Include.h"

struct NetworksDevice
{

};

class Networks
{
public:
	Networks();
	~Networks();

	pNetworksDevice networksDevice;
	void CreateNetworksDevice(pGameWindow gameWindow);
};

#endif // !__NETWORKS_H__
