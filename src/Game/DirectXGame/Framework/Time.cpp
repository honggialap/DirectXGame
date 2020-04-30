#include "Time.h"

#pragma region GameTime

GameTime::GameTime()
{
	elapsedMilliseconds = 0;
	totalElapsedMilliseconds = 0;
}

GameTime::~GameTime()
{
}

#pragma endregion

#pragma region Time

Time::Time()
{
	gameTime = new GameTime();

	elapsedTime = { 0 };
	totalElapsedTime = { 0 };
}

Time::~Time()
{
	if (gameTime != nullptr)
	{
		delete gameTime;
		gameTime = nullptr;
	}
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

#pragma endregion