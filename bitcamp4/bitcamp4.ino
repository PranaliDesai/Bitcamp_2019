
#include <math.h>
int buzzerpin=8;
int ledpin=13;
// defines pins numbers
const int trigPin = 2; 
const int echoPin = 3;
// defines variables
long duration;
int distance;
int flag=0;
void setup() {
  Serial.begin(9600); // initialize Serial communication
  pinMode(buzzerpin, OUTPUT);
  pinMode(ledpin, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}

void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);  
if ( distance >  10)
{
  digitalWrite(ledpin, HIGH);
  flag=flag+1;
  }
}
