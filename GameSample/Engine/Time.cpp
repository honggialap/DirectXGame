#include "Time.h"
#include "Debug.h"

/// <summary>
/// Start clock.
/// </summary>
void CTime::Start()
{
	DebugOut(L"[Time] Start clock.\n");

	_elapsedMs = 0;
	_totalElapsedMs = 0;
	_startTimeStamp = _clock.now();
	_currentTimeStamp = _startTimeStamp;
}


/// <summary>
/// Tick clock.
/// </summary>
void CTime::Tick()
{
	_previousTimeStamp = _currentTimeStamp;
	_currentTimeStamp = _clock.now();

	_elapsedMs = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>
		(_currentTimeStamp - _previousTimeStamp).count();

	_totalElapsedMs = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>
		(_currentTimeStamp - _startTimeStamp).count();
}
