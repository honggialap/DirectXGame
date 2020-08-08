#include "Time.h"

Time::Time()
{
	elapsedMilliseconds = 0;
	totalElapsedMilliseconds = 0;
}

Time::~Time()
{
}

void Time::Start()
{
	startTimeStamp = clock.now();
	currentTimeStamp = clock.now();
}

void Time::Update()
{
	previousTimeStamp = currentTimeStamp;
	currentTimeStamp = clock.now();
	elapsedMilliseconds = duration_cast<duration<float, milli>>
		(currentTimeStamp - previousTimeStamp).count();
	totalElapsedMilliseconds = duration_cast<duration<float, milli>>
		(currentTimeStamp - startTimeStamp).count();
}

void Time::Restart()
{
	elapsedMilliseconds = 0;
	totalElapsedMilliseconds = 0;
	Start();
}

float Time::ElapsedMilliseconds()
{
	return elapsedMilliseconds;
}

float Time::TotalElapsedMilliseconds()
{
	return totalElapsedMilliseconds;
}
