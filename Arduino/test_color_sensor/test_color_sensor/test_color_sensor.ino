
// the used PINs
const int s0=4;
const int s1=5;
const int s2=6;
const int s3=7;
const int sensorData=8;
const int ledRed=A4;
const int ledGreen=A5;
const int ledBlue=11;
// Global variable to store data

int dataR=0;
int dataG=0;
int dataB=0;

void setup() 
{
   pinMode(s0,OUTPUT);
   pinMode(s1,OUTPUT);
   pinMode(s2,OUTPUT);
   pinMode(s3,OUTPUT);
   pinMode(sensorData,INPUT);
   Serial.begin(9600);

   digitalWrite(s0,HIGH);
   digitalWrite(s1,LOW);
   
}

void loop()
{
   digitalWrite(s2,LOW);
   digitalWrite(s3,LOW);
   dataR=pulseIn(sensorData,LOW);
   delay(20);

   digitalWrite(s2,HIGH);
   digitalWrite(s3,HIGH);
   dataG=pulseIn(sensorData,LOW);
   delay(20);

   digitalWrite(s2,LOW);
   digitalWrite(s3,HIGH);
   dataB=pulseIn(sensorData,LOW);
   delay(20);
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
