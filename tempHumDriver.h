/*
DHT11 Air Temperature and Relative Humidity sensor driver
---------------------------------------------------------

REQUIRES the following Arduino libraries:
 - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
 - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

You can use and modify this code under your own responsability.
By Adrian Gallardo
May 2024

*/



#include "DHT.h"

#define DHTPIN 3     // Digital pin connected to the DHT sensor

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

void dhtBegin(void){
  dht.begin();  
}