//done
#include <Wire.h>

#define right_line_sens 2      // right sensor
#define left_line_sens 3       // left sensor

#define obst_sens_trig 11      // obstacle sensor trigger 
#define obst_sens_echo 12      // obstacle sensor echo reciver

#define left_mot_fwd A0        // left motor forward move
#define left_mot_bkwd A1       // left motor bakward move
#define right_mot_fwd A2       // right motor forward move
#define right_mot_bkwd A3      // right motor bakward move

int echo_time=0;
int dist=0;

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

  Serial.begin(9600);
  
  }

void loop()
{
  rls_val= digitalRead(right_line_sens);
  lls_val= digitalRead(left_line_sens);
  
  /*digitalWrite(obst_sens_trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(obst_sens_trig , LOW);

  echo_time = pulseIn(obst_sens_echo , HIGH);
  dist = (echo_time/2) / 25 ;
 // Serial.println(echo_time);
  Serial.println(dist);*/


  if(!(rls_val) && !(lls_val))     // Move Forward
  {
    move_fwd();
  }
  
  if(!(lls_val) && rls_val)     // Turn right
  {
    /*delayMicroseconds(10);
    analogWrite(left_mot_fwd, 0);
    analogWrite(left_mot_bkwd, 0);
    analogWrite(right_mot_fwd, 0);
    analogWrite(right_mot_bkwd, 0);
    delay(500);*/
    turn_right();
    }
  
  if(lls_val && !(rls_val))     // turn left
  {
    
    /*delayMicroseconds(10);
    analogWrite(left_mot_fwd, 0);
    analogWrite(left_mot_bkwd, 0);
    analogWrite(right_mot_fwd, 0);
    analogWrite(right_mot_bkwd, 0);
    delay(500);*/
    turn_left();
    }
  
  if(rls_val && lls_val)     // stop
  {
    stop_bot();
   }
}

void move_fwd()
{
  analogWrite(left_mot_fwd, 130);
    analogWrite(left_mot_bkwd, 0);
    analogWrite(right_mot_fwd, 130);
    analogWrite(right_mot_bkwd, 0);
    /*
    digitalWrite(left_mot_fwd, HIGH);
    digitalWrite(left_mot_bkwd, LOW);
    digitalWrite(right_mot_fwd, HIGH);
    digitalWrite(right_mot_bkwd, LOW);*/
  }
  void turn_left()
  {
    analogWrite(left_mot_fwd, 0);
    analogWrite(left_mot_bkwd, 0);
    analogWrite(right_mot_fwd, 130);
    analogWrite(right_mot_bkwd, 0);

    /*
   digitalWrite(left_mot_fwd, LOW);
    digitalWrite(left_mot_bkwd, LOW);
    digitalWrite(right_mot_fwd, HIGH);
    digitalWrite(right_mot_bkwd, LOW);*/
  
    }
    void turn_right()
    {
      analogWrite(left_mot_fwd, 130);
    analogWrite(left_mot_bkwd, 0);
    analogWrite(right_mot_fwd, 0);
    analogWrite(right_mot_bkwd, 0);
    
   /* digitalWrite(left_mot_fwd, HIGH);
    digitalWrite(left_mot_bkwd, LOW);
    digitalWrite(right_mot_fwd, LOW);
    digitalWrite(right_mot_bkwd, LOW);*/
  
      }
      void stop_bot()
      {
         analogWrite(left_mot_fwd, 0);
    analogWrite(left_mot_bkwd, 0);
    analogWrite(right_mot_fwd, 0);
    analogWrite(right_mot_bkwd, 0);
    
    /*digitalWrite(left_mot_fwd, LOW);
    digitalWrite(left_mot_bkwd, LOW);
    digitalWrite(right_mot_fwd, LOW);
    digitalWrite(right_mot_bkwd, LOW);
     */
        }
