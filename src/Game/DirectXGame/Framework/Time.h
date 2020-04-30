#pragma once
#ifndef __TIME_H__
#define __TIME_H__

#include "../Include.h"

class GameTime
{
public:
	double elapsedMilliseconds;
	double totalElapsedMilliseconds;

	GameTime();
	~GameTime();
};

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

#endif // !__TIME_H__
