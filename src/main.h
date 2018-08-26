#include <Arduino.h>
#include <Wire.h>
#include <RTClib.h>
#include <avr/eeprom.h>

#define TRIAC_PIN 9

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
