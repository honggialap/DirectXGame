#pragma once
#ifndef __TIME_H__
#define __TIME_H__

#include "../Include.h"

class Time
{
private:
	steady_clock clock;
	steady_clock::time_point startTimeStamp;
	steady_clock::time_point currentTimeStamp;
	steady_clock::time_point previousTimeStamp;

	float elapsedMilliseconds;
	float totalElapsedMilliseconds;
public:
	Time();
	~Time();

	void Start();
	void Update();
	void Restart();

	float ElapsedMilliseconds();
	float TotalElapsedMilliseconds();
};

#endif // !__TIME_H__
