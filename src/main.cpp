// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       SmartHomeArduino.ino
    Created:	17.07.2018 20:15:56
    Author:     Serj
*/
#include "main.h"

enum heaterState_t
{
	INITIAL = 0,
	HEAT,
	WAIT
} heatState;


#define TRIAC_PIN 9

enum DAYS
{
	MONDAY = 0,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY
};

struct time_t
{
	uint8_t hour;
	uint8_t minute;
};

struct heatTimes
{
	DAYS day;
	time_t time[4];
};



bool needHeat(const DateTime &time, const heatTimes *ptrHeatTime);

DS3231 rtc;

heatTimes heatTime[7] =
{
	{.day = MONDAY,    .time = {{12, 00}, {12, 20}, {4,  5},  {6,  7} }},
	{.day = TUESDAY,   .time = {{10, 30}, {21, 31}, {22, 32}, {23, 33} }},
	{.day = WEDNESDAY, .time = {{20, 30}, {21, 31}, {22, 32}, {23, 33} }},
	{.day = THURSDAY,  .time = {{30, 30}, {21, 31}, {22, 32}, {23, 33} }},
	{.day = FRIDAY,    .time = {{40, 30}, {21, 31}, {22, 32}, {23, 33} }},
	{.day = SATURDAY,  .time = {{50, 30}, {21, 31}, {22, 32}, {23, 33} }},
	{.day = SUNDAY,    .time = {{60, 30}, {21, 31}, {22, 32}, {23, 33} }},
};

void setup()
{
	Serial.begin(9600);
	pinMode(TRIAC_PIN, OUTPUT);
	pinMode(LED_BUILTIN, OUTPUT);
	Wire.begin();
	rtc.begin();
}

void loop()
{
	DateTime now = rtc.now();
	uint8_t day  = now.dayOfWeek();


	
	
	
	
	switch(heatState)
	{
		case INITIAL:
			if(needHeat(now, &heatTime[day]))
			{
				heatState = HEAT;
			}
			break;
		
		case WAIT:
			break;
		
		case HEAT:
			break;
		
		default:
			break;
	}


	delay(1000);
	//Serial.println(now.format());
	/*
	if (now.second() - seconds >= 10)
	{
		digitalWrite(LED_BUILTIN, HIGH);
		Serial.println(now.second());
		while (now.second() - seconds <= 12) 
		{
			now = rtc.now();
		}
		seconds = now.second();
	}

	else
	{
		digitalWrite(LED_BUILTIN, LOW);
	
	*/
}

bool needHeat(const DateTime &currentTime, const heatTimes *ptrHeatTime)
{
	uint8_t currentHour   = currentTime.hour();
	uint8_t currentMinute = currentTime.minute();
	uint8_t period        = 0;
 
	if (ptrHeatTime->time[period].hour >= currentHour)
	{
		if (ptrHeatTime->time[period].minute >= currentMinute)
			return true;
	}
	
	Serial.println(currentTime.dayOfWeek());
	Serial.print(currentTime.hour());
	Serial.print(":");
	Serial.println(currentTime.minute());

	return true;
}