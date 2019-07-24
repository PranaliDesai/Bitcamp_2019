#include <TinyGPS++.h>
#include <SoftwareSerial.h>
static const uint32_t GPSBaud = 9600;
TinyGPSPlus gps;
SoftwareSerial ss(10, 11);
int a;
int b; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ss.begin(GPSBaud);
  pinMode(7, INPUT);
}

void loop()
{

  //a = digitalRead(7);
  a=0;
  //Serial.print(a);
  {
    if (Serial.available() > 0) //recieving
    {
      //digitalWrite(2,HIGH);
      char val = Serial.read();
      Serial.write(val);

    }
  }
  {
    if (Serial.available() > 0) //sending
    {
  
      char val1 = Serial.read();
      Serial.print(val1);
       }
  }

  if (a == 1)
  {
    gps1();
  }
  else
  { }
}

void gps1()
{ 

  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0){
   
    if (gps.encode(ss.read()))
      displayInfo();
  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));

    while (true);
  }
}
}
void displayInfo()
{

  Serial.println(gps.satellites.value());

  Serial.print(F("Location: "));
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
    //Serial.end();
  }
  else
  {
    Serial.print(F("INVALID"));
    delay(2000);
 
  }
  
}
