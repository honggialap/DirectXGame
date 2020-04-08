#include "Time.h"

Time::Time()
{
	gameTime = new GameTime();

	gameTime->elapsedMilliseconds = 0;
	gameTime->totalElapsedMilliseconds = 0;

	elapsedTime = { 0 };
	totalElapsedTime = { 0 };
}

Time::~Time()
{
	delete gameTime;
	gameTime = nullptr;
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
	duration<double, milli> delta = duration_cast<duration<double, milli>>(currentTimeStamp - previousTimeStamp);

	elapsedTime = delta;
	totalElapsedTime += delta;

	gameTime->elapsedMilliseconds = elapsedTime.count();
	gameTime->totalElapsedMilliseconds = totalElapsedTime.count();
}

void Time::Restart()
{
	gameTime->elapsedMilliseconds = 0;
	gameTime->totalElapsedMilliseconds = 0;

	elapsedTime = { 0 };
	totalElapsedTime = { 0 };

	Start();
}