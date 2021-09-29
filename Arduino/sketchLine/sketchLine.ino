#include <Wire.h>


#define LS 2     // left sensor


void setup()
{
  Serial.begin(9600);
  pinMode(LS, INPUT);
 
}

void loop()
{
  int lsl= digitalRead(LS);

  //Serial.println(lsl);
  Serial.println(!(digitalRead(LS)));
 
  delay(2000);
}
