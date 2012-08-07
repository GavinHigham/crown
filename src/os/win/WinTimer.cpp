/*
Copyright (c) 2012 Daniele Bartolini, Simone Boscaratto

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
*/

#include <windows.h>
#include "Timer.h"

namespace Crown
{

Timer::Timer()
{
	mPreciseTimer = (QueryPerformanceFrequency((LARGE_INTEGER*) &mFrequency) == TRUE);

	if (mPreciseTimer)
	{
		QueryPerformanceCounter((LARGE_INTEGER*) &mCreationTime);
	}
	else
	{
		mFrequency = 1000;
		mCreationTime = timeGetTime();
	}

	Reset();
}

Timer::~Timer()
{
}

void Timer::Reset()
{
	if (mPreciseTimer)
	{
		QueryPerformanceCounter((LARGE_INTEGER*) &mCreationTime);
	}
	else
	{
		mCreationTime = timeGetTime();
	}
}

ulong Timer::GetMilliseconds() const
{
	ulong currentTime;

	if (mPreciseTimer)
	{
		QueryPerformanceCounter((LARGE_INTEGER*) &currentTime);
	}
	else
	{
		currentTime = timeGetTime();
	}

	return (ulong) ((currentTime - mCreationTime) / (mFrequency / 1000));
}

ulong Timer::GetMicroseconds() const
{
	ulong currentTime;

	if (mPreciseTimer)
	{
		QueryPerformanceCounter((LARGE_INTEGER*) &currentTime);
	}
	else
	{
		currentTime = timeGetTime();
	}

	//I'm using doubles here because if the timer isn't precise, it's always going to say
	//0us because of the integer calculus.
	return (ulong)((currentTime - mCreationTime) / (mFrequency/1000000.0));
}


void Timer::StartMilliseconds()
{
	if (mPreciseTimer)
	{
		QueryPerformanceCounter((LARGE_INTEGER*) &mStartTime);
	}
	else
	{
		mStartTime = timeGetTime();
	}
}

ulong Timer::StopMilliseconds() const
{
	ulong currentTime;

	if (mPreciseTimer)
	{
		QueryPerformanceCounter((LARGE_INTEGER*) &currentTime);
	}
	else
	{
		currentTime = timeGetTime();
	}

	return (ulong) ((currentTime - mStartTime) / (mFrequency / 1000));
}

void Timer::StartMicroseconds()
{
	if (mPreciseTimer)
	{
		QueryPerformanceCounter((LARGE_INTEGER*) &mStartTime);
	}
	else
	{
		mStartTime = timeGetTime();
	}
}

ulong Timer::StopMicroseconds() const
{
	ulong currentTime;

	if (mPreciseTimer)
	{
		QueryPerformanceCounter((LARGE_INTEGER*) &currentTime);
	}
	else
	{
		currentTime = timeGetTime();
	}

	//I'm using doubles here because if the timer isn't precise, it's always going to say
	//0us because of the integer calculus.
	return (ulong)((currentTime - mStartTime) / (mFrequency/1000000.0));
}

} // namespace Crown

