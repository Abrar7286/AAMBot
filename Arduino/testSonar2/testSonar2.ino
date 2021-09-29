//done
#include <Wire.h>

#define obst_sens_trig 11      // obstacle sensor trigger 
#define obst_sens_echo 12      // obstacle sensor echo reciver

#define LM1 A0       // left motor
#define LM2 A1      // left motor
#define RM1 A2       // right motor
#define RM2 A3       // right motor


int echo_time=0;
int dist=0;

void setup()
{
 

  pinMode(obst_sens_trig, OUTPUT);
  pinMode(obst_sens_echo, INPUT);

  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  
  Serial.begin(9600);
  
  }

void loop()
{
  digitalWrite(obst_sens_trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(obst_sens_trig , LOW);


  echo_time = pulseIn(obst_sens_echo , HIGH);
  dist = (echo_time/2) / 35 ;
 // Serial.println(echo_time);
  Serial.println(dist);

  if(dist>35)
  {
    analogWrite(LM1, 130);
    analogWrite(LM2, 0);
    analogWrite(RM1, 130);
    analogWrite(RM2, 0);
    }
    else 
    {
      digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
      }

  delay(1000);
  
}
