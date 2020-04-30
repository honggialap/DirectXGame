#pragma once
#ifndef __ULTILITIES_H__
#define __ULTILITIES_H__

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <signal.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <chrono>

#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <d3dx9math.h>
#include <dinput.h>
#include "../Library/pugixml/pugixml.hpp"
//#include <winsock2.h>
//#include <WS2tcpip.h>

using namespace std;
using namespace pugi;
using namespace std::chrono;

void DebugOut(const wchar_t* fmt, ...);

//vector<string> split(string line, string delimeter = "\t");

wstring ToWSTR(string st);
LPCWSTR ToLPCWSTR(string st);

#endif // !__ULTILITIES_H__
