#include <Wire.h>


#define right_line_sens 2      // right sensor
#define left_line_sens 3       // left sensor

#define obst_sens_trig 4      // obstacle sensor trigger 
#define obst_sens_echo 5      // obstacle sensor echo reciver


#define left_mot_fwd 6        // left motor forward move
#define left_mot_bkwd 7       // left motor bakward move
#define right_mot_fwd 8       // right motor forward move
#define right_mot_bkwd 9      // right motor bakward move

#define s0 10        //color sensor s0 pin
#define s1 11       //s1 pin of color sensor
#define s2 12       //s2 pin of color sensor
#define s3 13       //s3 pin of color sensor
#define RGBout A0     //sensor output value

#define ledRed A4
#define ledGreen A5
#define ledBlue A6

int echo_time=0;
int dist=0;

int dataR=0;
int dataG=0;
int dataB=0;

void setup()
{
  pinMode(right_line_sens, INPUT);
  pinMode(left_line_sens, INPUT);

  pinMode(obst_sens_trig, OUTPUT);
  pinMode(obst_sens_echo, INPUT);
  
  pinMode(left_mot_fwd, OUTPUT);
  pinMode(left_mot_bkwd, OUTPUT);
  pinMode(right_mot_fwd, OUTPUT);
  pinMode(right_mot_bkwd, OUTPUT);
  
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(RGBout,INPUT);
  
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
 
 Serial.begin(9600);

   digitalWrite(s0,HIGH);
   digitalWrite(s1,HIGH);

  
  }

void loop()
{
  int rls_val= digitalRead(right_line_sens);
  int lls_val= digitalRead(left_line_sens);
  Serial.println(rls_val);
  Serial.println(lls_val);
  //delay(1000);

  digitalWrite(obst_sens_trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(obst_sens_trig , LOW);

  echo_time = pulseIn(obst_sens_echo , HIGH);
  dist = (echo_time/2) / 25 ;
 // Serial.println(echo_time);
  Serial.println(dist);
  
   digitalWrite(s2,LOW);
   digitalWrite(s3,LOW);
   dataR=pulseIn(RGBout,LOW);
   delay(20);

   digitalWrite(s2,HIGH);
   digitalWrite(s3,HIGH);
   dataG=pulseIn(RGBout,LOW);
   delay(20);

   digitalWrite(s2,LOW);
   digitalWrite(s3,HIGH);
   dataB=pulseIn(RGBout,LOW);
   delay(20);

  if(dist>20 && !(isColor()))
  {
    if(!(rls_val) && !(lls_val))     // Move Forward
    {
      move_fwd();
    }
  
    if(!(lls_val) && rls_val)     // Turn right
    {
      turn_right();
    }
  
    if(lls_val && !(rls_val))     // turn left
    {
      turn_left();
    } 
    if(rls_val && lls_val)     // stop
    {
      stop_bot();
    }
  }
  else if(isColor())
  {
    stop_bot();
    delay(8000);
    if(isRed())
    {
      Serial.println("This is node#1: Red Node");
      analogWrite(ledRed,255);
      analogWrite(ledGreen,0);
      analogWrite(ledBlue,0);
    }
    if(isBlue())
    {
      Serial.println("This is node#2: Blue Node");
      analogWrite(ledRed,0);
      analogWrite(ledGreen,0);
      analogWrite(ledBlue,255);
    }
    if(isGreen())
    {
      Serial.println("This is node#3: Green Node");
      analogWrite(ledRed,0);
      analogWrite(ledGreen,255);
      analogWrite(ledBlue,0);
    }
    if(isYellow())
    {
      Serial.println("This is node#4: Yellow Node");
      analogWrite(ledRed,255);
      analogWrite(ledGreen,224);
      analogWrite(ledBlue,0);
    }
    move_fwd();
    }
  else 
  {
    stop_bot();
    }
}

void move_fwd()
{  
    digitalWrite(left_mot_fwd, HIGH);
    digitalWrite(left_mot_bkwd, LOW);
    digitalWrite(right_mot_fwd, HIGH);
    digitalWrite(right_mot_bkwd, LOW);
  }
  void turn_right()
  {
    
    digitalWrite(left_mot_fwd, HIGH);
    digitalWrite(left_mot_bkwd, LOW);
    digitalWrite(right_mot_fwd, LOW);
    digitalWrite(right_mot_bkwd, LOW);
  
  }
  void turn_left()
  {
      
    digitalWrite(left_mot_fwd, LOW);
    digitalWrite(left_mot_bkwd, LOW);
    digitalWrite(right_mot_fwd, HIGH);
    digitalWrite(right_mot_bkwd, LOW);
  
  }
  void stop_bot()
  {
        
    digitalWrite(left_mot_fwd, LOW);
    digitalWrite(left_mot_bkwd, LOW);
    digitalWrite(right_mot_fwd, LOW);
    digitalWrite(right_mot_bkwd, LOW);
  
    }
  
  bool isRed()
  {
    if((dataR<10 && dataR>6) && (dataG<30 && dataG>25) && (dataB<22 && dataB>18))
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool isGreen()
  {
    if((dataR<14 && dataR>10) && (dataG<12 && dataG>8) && (dataB<14 && dataB>10))
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool isBlue()
  {
    if((dataR<43 && dataR>38) && (dataG<30 && dataG>20) && (dataB<14 && dataB>8))
    {
      return true;
    }
    else
    {
    return false;
    }
  }

  bool isYellow()
  {
    if((dataR<8 && dataR>5) && (dataG<10 && dataG>6) && (dataB<15 && dataB>10))
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  bool isColor()
  {
    if(isBlue() || isGreen() || isRed() || isYellow())
    {
      return true;
    }
    else
    {
      return false;
    }
  }
