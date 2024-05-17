/*
SD card driver
--------------
This part of code show you how to implement an SD card for datalogging 
pupposes.



You can use and modify this code under your own responsability.
By Adrian Gallardo
May 2024

*/

#include <SPI.h>
#include <SD.h>

const int chipSelect = 10;  // This is how its internally connected on DataLogger Shield V1.0 board


void sdBegin(void){
  Serial.print(F("SD: "));

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println(F("failed, or not present. program will stop"));
    // don't do anything more:
    while (1);
  }
  Serial.println(F("OK"));
}

bool saveString(String fileName, String dataLine){
  bool saveStatus = false;
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("fileName", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataLine);
    dataFile.close();
    saveStatus = true;
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening " + fileName);
  }

  return saveStatus;

}