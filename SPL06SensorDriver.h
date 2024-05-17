/* This sensor driver require SPL06-001 library by rv701
  wiring:
  SCL: A5
  SDA: A4
  VIN: 5v
  GND: GND

  It is highly recommended review library and sensor documents for proper calibration process

  sensor document:
  https://forum.arduino.cc/uploads/short-url/eSOwUHkPIfinQQV0bhsAtYRGf7Y.pdf


You can use and modify this code under your own responsability.
By Adrian Gallardo
May 2024

*/
#include <SPL06-007.h>
#include <Wire.h>

void barometherBegin(void){
  SPL_init(); // Setup initial SPL chip registers  
}

int presureRead(void){
  int pres = get_praw();
  return pres;
}

