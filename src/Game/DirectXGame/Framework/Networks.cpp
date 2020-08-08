#include "Networks.h"

Networks::Networks()
{
	networksDevice = new NetworksDevice();
}

Networks::~Networks()
{
	if (networksDevice != nullptr)
	{
		delete networksDevice;
		networksDevice = nullptr;
	}
}

void Networks::CreateNetworksDevice(pGameWindow gameWindow)
{
}
