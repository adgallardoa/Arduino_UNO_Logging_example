/*
Arduino UNO datalogging Test!
------------------------------

This scketch show you how to implement a basic datalogging system from scratch with the
use of low cost arduino compatible modules.

Hardware required:
- Arduino UNO board
- DataLogger Shield V1.0 (RTC DS1307 with SD-card reader) / Requires "RTClib.h", "Wire.h", "SPI.h" and "SD.h" libraries 
- DHT11 air temperature and relative humidity sensor      / Requires "DHT.h" and "Adafruit_Sensor.h" libraries
- UVM30A - Analog UV detection sensor for wavelength between 200-370nm;
- HC-SR04 - 5V Ultrasonic Distance Sensor
- Resistive Soil Moisture Sensor
- SPL06-007 - Digital pressure sensor                     / Requires "SPL06-007.h" library

In order to simplify the main code and make it easier to understand and modify, a ".h" file 
has been generated for each element of the system. These files must be stored in the same 
folder as this main scketch.


Special attention
------------------
1- Arduino UNO board contains an Atmega328P mucrocontroller unit (MCU), wich has only 32KB for 
program memory and 2KB of SRAM for variables wich is not too much nowadays where we're familiar 
with high power computers, so you should use it wisely in order to avoid non controlled MCU crashes.

2- The wiring of this example requires many connections to 5V and GND by the sensors considered, 
so the electrical connection must be made carefully in order to avoid short circuits in our system.


You can use and modify this code under your own responsability.

by Adrian Gallardo
May 2024
*/

// Controller codes for each element of the system
#include "rtcDriver.h"
#include "sdDriver.h"
#include "tempHumDriver.h"
#include "uvSensorDriver.h"
#include "ultraSoundDriver.h"
#include "resistiveMoistureSensor.h"
#include "SPL06SensorDriver.h"


// This function is executed one time at beggining of program
void setup() {
  Serial.begin(115200);   // Remember set this baud rate at your serial monitor!
  while (!Serial) ;       // wait for serial ready
  Serial.println(F("\nDatalogger sample\n")); // System init title

  // Initial setup for each integrated component
  rtcBegin();
  sdBegin();
  dhtBegin();
  SR04Begin();
  barometherBegin();
}


// This code runs in an infinite loop after setup function
void loop() {
  // read sensors
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int UVA = rawUvaRead();
  float dist = SRDistance();
  int soilMoist = moitSensRead();
  int presUncalibrated = presureRead();

  // generate a new dataline
  String data = "";
  data += rtcDateTime();
  data += ",HR," + String(h);
  data += ",TC," + String(t);
  data += ",UV," + String(UVA);
  data += ",SR," + String(dist);
  data += ",SM," + String(soilMoist);
  data += ",BP," + String(presUncalibrated);

  // show new dataline by serial monitor
  Serial.println(data);

  // try to save new dataline on sd card
  if(saveString("datalog.txt",data)){
    Serial.println("Saved data");
  }else{
    Serial.println("dataloging Error");
  }

  // wait 10 seconds until next cycle
  delay(10000);

  // start this loop again
}
