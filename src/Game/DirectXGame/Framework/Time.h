#pragma once
#ifndef __TIME_H__
#define __TIME_H__

#include <chrono>

using namespace std;
using namespace std::chrono;

class GameTime
{
public:
	double elapsedMilliseconds;
	double totalElapsedMilliseconds;
};

typedef GameTime* pGameTime;

class Time
{
public:
	steady_clock clock;
	steady_clock::time_point startTimeStamp;
	steady_clock::time_point currentTimeStamp;
	steady_clock::time_point previousTimeStamp;
	duration<double, milli> elapsedTime;
	duration<double, milli> totalElapsedTime;

	pGameTime gameTime;

	Time();
	~Time();
	
	void Start();
	void Update();
	void Restart();
};

typedef Time* pTime;

#endif // !__TIME_H__
