/*
DS1307 Real Time Clock (RTC) Driver
-----------------------------------

This part of code controlls the real time clock (RTC) unit
embedded on the DataLogger Shield V1.0.
If after set the hour and turn off the system your RTC 
is not capable to keep the date and time running, then you should
consider replace the CR1220 coin cell for a new one.

DS1307 its communicated by I2C protocol to the MCU.
Said protocol requires 2 pins (For SDA and SCL buses) wich correspond
to A4 and A5 Arduino terminals respectively. THose pins are internally connected on
DataLogger Shield V1.0

You can use and modify this code under your own responsability.
By Adrian Gallardo
May 2024
*/

#include "RTClib.h"

RTC_DS1307 rtc;

// init the RTC and set compilation date/time is it is not set.
void rtcBegin(void){
  Serial.print(F("RTC init: "));
  if (! rtc.begin()) {
    Serial.println(F("Couldn't find RTC. The program will stop."));
    Serial.flush(); // wait until transmit all serial messages on transmit buffer
    abort();        // stop the program
  }

  if (! rtc.isrunning()) {
    Serial.println(F("RTC is NOT running, let's set the time!"));
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  // When time needs to be re-set on a previously configured device, the
  // following line sets the RTC to the date & time this sketch was compiled
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // This line sets the RTC with an explicit date & time, for example to set
  // January 21, 2014 at 3am you would call:
  // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));

  Serial.println(F("RTC OK"));
}


// Return a String with Date Time with format "yyyy-mm-dd hh:mm:ss"
String rtcDateTime(void){
  DateTime now = rtc.now(); 

  String resp = String(now.year()) + "-";
  if(now.month() < 10) resp += "0";
  resp += String(now.month()) + "-";
  if(now.day() < 10) resp += "0";
  resp += String(now.day()) + " ";

  if(now.hour() < 10) resp += "0";
  resp += String(now.hour()) + ":";
  if(now.minute() < 10) resp += "0";
  resp += String(now.minute()) + ":";
  if(now.second() < 10) resp += "0";
  resp += String(now.second());
  
  return resp;
}