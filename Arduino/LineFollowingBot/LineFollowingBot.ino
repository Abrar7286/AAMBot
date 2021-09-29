#include <Wire.h>

/*------ Program for Line Follower Robot using Arduino----- */
/*-------definning Inputs------*/
#define RS 2      // right sensor
#define LS 3      // left sensor


/*-------definning Outputs------*/
#define LM1 A0       // left motor
#define LM2 A1       // left motor
#define RM1 A2       // right motor
#define RM2 A3       // right motor

void setup()
{
  Serial.begin(9600);
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
}

void loop()
{
  int lsl= digitalRead(LS);
  int lsr= digitalRead(RS);
  Serial.println(lsl);
  Serial.println(lsr);
  //delay(1000);


  if(digitalRead(LS) && digitalRead(RS))     // Move Forward
  {
    /*analogWrite(LM1, 80);
    analogWrite(LM2, 0);
    analogWrite(RM1, 80);
    analogWrite(RM2, 0);*/
    
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }
  
  if(!(digitalRead(LS)) && digitalRead(RS))     // Turn left
  {
    /*analogWrite(LM1, 0);
    analogWrite(LM2, 0);
    analogWrite(RM1, 80);
    analogWrite(RM2, 0);*/

    
   digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }
  
  if(digitalRead(LS) && !(digitalRead(RS)))     // turn right
  {
    /*analogWrite(LM1, 80);
    analogWrite(LM2, 0);
    analogWrite(RM1, 0);
    analogWrite(RM2, 0);*/
    
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
  
  if(!(digitalRead(LS)) && !(digitalRead(RS)))     // stop
  {
   /* analogWrite(LM1, 0);
    analogWrite(LM2, 0);
    analogWrite(RM1, 0);
    analogWrite(RM2, 0);*/
    
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
}
