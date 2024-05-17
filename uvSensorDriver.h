/*



You can use and modify this code under your own responsability.
By Adrian Gallardo
May 2024

*/

#define UVAPIN A0


int rawUvaRead(void){
  int resp = analogRead(UVAPIN);
  return resp;
}
