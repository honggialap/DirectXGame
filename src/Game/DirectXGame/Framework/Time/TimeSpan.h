#pragma once

#ifndef __TIME_SPAN_H__
#define __TIME_SPAN_H__

#include "Chrono.h"

struct TimeSpan
{
	duration<double, milliseconds> duration;

};

#endif // !__TIME_SPAN_H__