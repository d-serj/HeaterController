// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       SmartHomeArduino.ino
    Created:	17.07.2018 20:15:56
    Author:     Serj
*/

#include <Arduino.h>
#include <Wire.h>
#include <RTClib.h>
#include <avr/eeprom.h>

#define TRIAC_PIN 9

DS3231 rtc;

enum DAYS
{
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY
};

/* Примерно так хранить в EEPROM */
enum EEPROM_DATE_STORAGE
{
	DAY,
	HOURS1,
	MINUTES1,
	HOURS2,
	MINUTES2
};

uint8_t frame[5] = { MONDAY, 23, 0, 7, 0 };
//DAYS temp = frame[DAY];
/********************************************/

struct heatTimes
{
	DAYS day;
	uint8_t time[4];
};

heatTimes heatTime[7] =
{
	{.day = MONDAY,    .time = { 1,  2,  3 }},
	{.day = TUESDAY,   .time = { 4,  5,  6 }},
	{.day = WEDNESDAY, .time = { 7,  8,  9 }},
	{.day = THURSDAY,  .time = { 10, 11, 12 }},
	{.day = FRIDAY,    .time = { 13, 14, 15 }},
	{.day = SATURDAY,  .time = { 16, 17, 18 }},
	{.day = SUNDAY,    .time = { 19, 20, 21 }},
};

//uint8_t times[] = { 2307, 2307, 2307, 2307, 2307, 2307, 2307 };

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
