/*



You can use and modify this code under your own responsability.
By Adrian Gallardo
May 2024

*/

#define SOILMOISTPIN A1

int moitSensRead(void){
  int moist = analogRead(SOILMOISTPIN);
  
  return moist;
}