#pragma once

#ifndef __TIME_H__
#define __TIME_H__

#include "Chrono.h"

class Time
{
	// Singleton
private:
	static Time* __instance;
	Time();
public:
	static Time* GetInstance();
	~Time();

	// Chrono
private:
	steady_clock clock;

	steady_clock::time_point current;
	steady_clock::time_point previous;

	duration<double, std::milli> elapsedTime;
	duration<double, std::milli> totalElapsedTime;

public:

	//Framework component
public:
	void Initialize();
	void Shutdown();

	void Start();
	void Update();

	double GetElapsedMilliseconds(); //between update
	double GetTotalElapsedMilliseconds(); //from start
};

typedef Time* pTime;

#endif // !__TIME_H__