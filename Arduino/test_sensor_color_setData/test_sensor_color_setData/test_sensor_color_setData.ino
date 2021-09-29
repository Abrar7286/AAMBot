/************************************************************************************************************************************************************************                                              
 * - Author           : BEE MB                       *                                               
 * - Profession       : (Developer) MEGA DAS owner   *                                                                                              
 * - Main purpose     : Industrial Application       *                                                                                  
 * - Copyright holder : No copyrights                *                                  
 * - Date             : 06/09/2016                   *
 * ***********************************************************************************************************************************************************************/
// the used PINs
const int s0=7;
const int s1=8;
const int s2=10;
const int s3=11;
const int sensorData=12;
// Global variable to store data
int data=0;

void setup() 
{
  // PINs configuration
   pinMode(s0,OUTPUT);
   pinMode(s1,OUTPUT);
   pinMode(s2,OUTPUT);
   pinMode(s3,OUTPUT);
   pinMode(sensorData,INPUT);
  // Serial baude rate setup
   Serial.begin(9600);
  // Frequency scale
   digitalWrite(s0,HIGH);
   digitalWrite(s1,HIGH);
   
}

void loop()
{
/*********************** getting the RED COLOR data ************************/
  // Set S2 and S3 to LOW in order to sense the RED color
   digitalWrite(s2,LOW);
   digitalWrite(s3,LOW);
  // store data in the Global varibale
   data=pulseIn(sensorData,LOW);
  // Display data through the Serial monitor
   Serial.print("Red data= ");
   Serial.print(data);
   Serial.print(" ");
   delay(20);
/*********************** getting the GREEN COLOR data ************************/
   digitalWrite(s2,HIGH);
   digitalWrite(s3,HIGH);
   data=pulseIn(sensorData,LOW);
   Serial.print("Green data= ");
   Serial.print(data);
   Serial.print(" ");
   delay(20);
/*********************** getting the BLUE COLOR data ************************/

   digitalWrite(s2,LOW);
   digitalWrite(s3,HIGH);
   data=pulseIn(sensorData,LOW);
   Serial.print("Blue data= ");
   Serial.print(data);
   Serial.println(" ");
   delay(20);
   //delay(2000);
}
