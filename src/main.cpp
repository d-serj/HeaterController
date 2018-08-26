// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       SmartHomeArduino.ino
    Created:	17.07.2018 20:15:56
    Author:     Serj
*/
#include "main.h"

DS3231 rtc;

heatTimes heatTime[7] =
{
	{.day = MONDAY,    .time = {{ 0, 1},  {2,  3},  {4,  5},  {6,  7} }},
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
	static uint16_t seconds = now.second();
	
	Serial.println(now.dayOfWeek());
	Serial.print(now.hour());
	Serial.print(":");
	Serial.println(now.minute());
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

bool needHeat()
{

}