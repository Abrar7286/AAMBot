#include <Wire.h>




#define obst_sens_trig 11      // obstacle sensor trigger 
#define obst_sens_echo 12      // obstacle sensor echo reciver




int echo_time=0;
int dist=0;

void setup()
{
 

  pinMode(obst_sens_trig, OUTPUT);
  pinMode(obst_sens_echo, INPUT);
  
  
  Serial.begin(9600);
  
  }

void loop()
{
  digitalWrite(obst_sens_trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(obst_sens_trig , LOW);


  echo_time = pulseIn(obst_sens_echo , HIGH);
  dist = (echo_time/2) / 25 ;
 // Serial.println(echo_time);
  Serial.println(dist);

  delay(1000);
  
}
