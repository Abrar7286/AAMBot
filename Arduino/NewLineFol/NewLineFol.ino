#include <Wire.h>


#define right_line_sens 2      // right sensor
#define left_line_sens 3       // left sensor

#define obst_sens_trig 8      // obstacle sensor trigger 
#define obst_sens_echo 9      // obstacle sensor echo reciver


#define left_mot_fwd 4        // left motor forward move
#define left_mot_bkwd 5       // left motor bakward move
#define right_mot_fwd 6       // right motor forward move
#define right_mot_bkwd 7      // right motor bakward move

int echo_time=0;
int dist=0;

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

void move_fwd()
{
  /*analogWrite(left_mot_fwd, 80);
    analogWrite(left_mot_bkwd, 0);
    analogWrite(right_mot_fwd, 80);
    analogWrite(right_mot_bkwd, 0);*/
    
    digitalWrite(left_mot_fwd, HIGH);
    digitalWrite(left_mot_bkwd, LOW);
    digitalWrite(right_mot_fwd, HIGH);
    digitalWrite(right_mot_bkwd, LOW);
  }
  void turn_right()
  {
    /*analogWrite(left_mot_fwd, 0);
    analogWrite(left_mot_bkwd, 0);
    analogWrite(right_mot_fwd, 80);
    analogWrite(right_mot_bkwd, 0);*/

    
   digitalWrite(left_mot_fwd, HIGH);
    digitalWrite(left_mot_bkwd, LOW);
    digitalWrite(right_mot_fwd, LOW);
    digitalWrite(right_mot_bkwd, LOW);
  
    }
    void turn_left()
    {
      /*analogWrite(left_mot_fwd, 80);
    analogWrite(left_mot_bkwd, 0);
    analogWrite(right_mot_fwd, 0);
    analogWrite(right_mot-bkwd, 0);*/
    
    digitalWrite(left_mot_fwd, LOW);
    digitalWrite(left_mot_bkwd, LOW);
    digitalWrite(right_mot_fwd, HIGH);
    digitalWrite(right_mot_bkwd, LOW);
  
      }
      void stop_bot()
      {
        /* analogWrite(left_mot_fwd, 0);
    analogWrite(left_mot_bkwd, 0);
    analogWrite(right_mot_fwd, 0);
    analogWrite(right_mot_bkwd, 0);*/
    
    digitalWrite(left_mot_fwd, LOW);
    digitalWrite(left_mot_bkwd, LOW);
    digitalWrite(right_mot_fwd, LOW);
    digitalWrite(right_mot_bkwd, LOW);
  
        }
