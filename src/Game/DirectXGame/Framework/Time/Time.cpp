#include "Time.h"

Time* Time::__instance = nullptr;

Time* Time::GetInstance()
{
	if (__instance == nullptr)
		__instance = new Time();

	return __instance;
}

Time::Time()
{
	elapsedTime = {0};
	totalElapsedTime = {0};
}

Time::~Time()
{

}

void Time::Initialize()
{

}

void Time::Shutdown()
{

}

void Time::Start()
{
	current = clock.now();
}

void Time::Update()
{
	previous = current;
	current = clock.now();
	duration<double, std::milli> delta = duration_cast<duration<double, std::milli>>(current - previous);

	elapsedTime = delta;
	totalElapsedTime += delta;
}

double Time::GetElapsedMilliseconds()
{
	return elapsedTime.count();
}

double Time::GetTotalElapsedMilliseconds()
{
	return totalElapsedTime.count();
}
