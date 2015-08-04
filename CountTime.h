#include<iostream>
#include<Windows.h>
#include<time.h>
using namespace std;
struct stopWatch{
	LARGE_INTEGER start;
	LARGE_INTEGER stop;
};
// khai bao lop CStopWatch
class CStopWatch {
private:
	stopWatch timer;
	LARGE_INTEGER frequency;
	double LIToSecs(LARGE_INTEGER & L);
public:
	CStopWatch();
	void startTimer();
	void stopTimer();
	double getElapsedTime();
};
double CStopWatch::LIToSecs(LARGE_INTEGER & L)
{
	return ((double)L.QuadPart / (double)frequency.QuadPart);
}
CStopWatch::CStopWatch()
{
	timer.start.QuadPart = 0;
	timer.stop.QuadPart = 0;
	QueryPerformanceFrequency(&frequency);
}
void CStopWatch::startTimer()
{
	QueryPerformanceCounter(&timer.start);
}
void CStopWatch::stopTimer()
{
	QueryPerformanceCounter(&timer.stop);
}
double CStopWatch::getElapsedTime()
{
	LARGE_INTEGER time;
	time.QuadPart = timer.stop.QuadPart -timer.start.QuadPart;
	return LIToSecs(time);
}