#include <Wire.h>


#define right_line_sens 2      // right sensor
#define left_line_sens 3       // left sensor

#define obst_sens_trig 9      // obstacle sensor trigger 
#define obst_sens_echo 10      // obstacle sensor echo reciver


#define left_mot_fwd A0        // left motor forward move
#define left_mot_bkwd A1       // left motor bakward move
#define right_mot_fwd A2       // right motor forward move
#define right_mot_bkwd A3      // right motor bakward move

#define s0 4        //s0 pin of color sensor 
#define s1 5        //s1 pin of color sensor
#define s2 6        //s2 pin of color sensor
#define s3 7        //s3 pin of color sensor
#define RGBout  8   //sensor output value

#define ledRed A4
#define ledGreen A5
#define ledBlue A6

int echo_time=0;
int dist=0;

int dataR=0;
int dataG=0;
int dataB=0;

int rls_val;
int lls_val;

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
  dist = (echo_time/2) / 35 ;
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

  if(dist>35 && !(isColor()))
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
    Serial.println("this is the RED color");
    analogWrite(ledRed,255);
    analogWrite(ledGreen,0);
    analogWrite(ledBlue,0);
   }
   if(isBlue())
   {
    Serial.println("this is the Blue color");
    analogWrite(ledRed,0);
    analogWrite(ledGreen,0);
    analogWrite(ledBlue,255);
   }
   if(isGreen())
   {
    Serial.println("this is the GREEN color");
    analogWrite(ledRed,0);
    analogWrite(ledGreen,255);
    analogWrite(ledBlue,0);
   }
   if(isOrange())
   {
    Serial.println("this is the orange color");
    analogWrite(ledRed,255);
    analogWrite(ledGreen,165);
    analogWrite(ledBlue,0);
   }
   if(isPurple())
   {
    Serial.println("this is the purple color");
    analogWrite(ledRed,160);
    analogWrite(ledGreen,32);
    analogWrite(ledBlue,240);
   }
   if(isPink())
   {
    Serial.println("this is the Pink color");
    analogWrite(ledRed,255);
    analogWrite(ledGreen,105);
    analogWrite(ledBlue,180);
   }
   if(isMagenta())
   {
    Serial.println("this is the Magenta color");
    analogWrite(ledRed,153);
    analogWrite(ledGreen,0);
    analogWrite(ledBlue,153);
   }
   if(isYellow())
   {
    Serial.println("this is the Yellow color");
    analogWrite(ledRed,255);
    analogWrite(ledGreen,255);
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
  if((dataR<45 && dataR>35) && (dataG<125 && dataG>102) && (dataB<95 && dataB>82))
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
  if((dataR<70 && dataR>55) && (dataG<50 && dataG>40) && (dataB<75 && dataB>60))
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
  if((dataR<85 && dataR>65) && (dataG<48 && dataG>37) && (dataB<30 && dataB>26))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isOrange()
{
  if((dataR<22 && dataR>18) && (dataG<50 && dataG>36) && (dataB<60 && dataB>45))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isPurple()
{
  if((dataR<45 && dataR>32) && (dataG<52 && dataG>45) && (dataB<32 && dataB>28))
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool isPink()
{
  if((dataR<22 && dataR>17) && (dataG<65 && dataG>56) && (dataB<38 && dataB>30))
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool isMagenta()
{
  if((dataR<73 && dataR>65) && (dataG<130 && dataG>105) && (dataB<80 && dataB>62))
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
  if((dataR<35 && dataR>25) && (dataG<35 && dataG>25) && (dataB<40 && dataB>29))
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
    if(isBlue() || isGreen() || isRed() || isYellow() || isPink() || isMagenta() || isPurple() || isOrange())
    {
      return true;
    }
    else
    {
      return false;
    }
  }
