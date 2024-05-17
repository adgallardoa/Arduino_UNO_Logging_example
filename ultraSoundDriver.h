/*



You can use and modify this code under your own responsability.
By Adrian Gallardo
May 2024

*/

const int trigPin = 4;
const int echoPin = 5;

void SR04Begin(void){
  pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);  
}


// resturn the distance in cm
float SRDistance(void){
  float duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;    // assuming 343m/s of sound speed. Must be carefully set or compensated at extreme temperatures or atmospheric pressure changes

  return distance;
}