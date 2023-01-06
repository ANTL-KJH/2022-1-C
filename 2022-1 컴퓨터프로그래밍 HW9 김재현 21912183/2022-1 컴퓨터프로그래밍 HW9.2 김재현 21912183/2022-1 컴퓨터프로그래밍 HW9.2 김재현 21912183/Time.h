/* Time.h */
#ifndef TIME_H
#define TIME_H
#define HOUR 3600	//1시간은 3600 sec
#define MIN 60	//1분은 60sec
#define NUM_TIMES 5
typedef struct
{
	int hour;
	int min;
	int sec;
} Time;
Time inputTime();
Time initTime(int h, int m, int s);
void printTime(const Time* t);
void incrementTime(Time* t, int incr_sec);
int convert_to_Sec(const Time* t);
int compareTime(const Time* t1, const Time* t2);
void selectSortTime(Time* times, int size);
#endif