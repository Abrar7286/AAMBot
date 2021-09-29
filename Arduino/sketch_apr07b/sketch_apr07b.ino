#include <Wire.h> 

//#include <LiquidCrystal_I2C.h>



//LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004

int IN1 = 2;

int IN4 = 4;



void setup()

{

  //lcd.init();  // initialize the lcd 

  //lcd.backlight();

  //lcd.print("start LCD2004");



  pinMode(IN1,INPUT);

  pinMode(IN4,INPUT);

  Serial.begin(9600);

 



  //lcd.clear();

}



void loop()

{

  //lcd.setCursor(0,0);

 // lcd.print("S075:4CHIR Tracking");



  //String val1str = "";

  //String val4str = "";



  int in1_val = digitalRead(IN1);

  int in4_val = digitalRead(IN4);



  /*if(in1_val == 0)

    val1str = " detected";

  else 

    val1str = "         ";



  if(in4_val == 0)

    val4str = " detected";

  else

    val4str = "         ";



  lcd.setCursor(0,1);

  lcd.print("IN1=" + (String)in1_val + val1str);



  lcd.setCursor(0,2);

  lcd.print("IN4=" + (String)in4_val + val4str);
*/
Serial.println(in1_val);

Serial.println(in4_val);
 delay(1000);
}

