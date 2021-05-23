//Temperature Sensor libraries
#include <OneWire.h>
#include <DallasTemperature.h>

//Communication libraries
#include <ESP8266WiFi.h>
#include <Blynk.h>
#include <BlynkSimpleEsp8266.h>

#define tempSensBusLine 4 //D2 pin for TEMPERATURE SENSOR BUS LINE
#define relayIn         12 //D8 pin to drive BASE of TRANSISTOR for RELAY

//Function Prototypes
void getTemperature();
void switchOnGeazer();
void switchOffGeazer();
void geazerSwitch();

//Create Instances
OneWire oneWire(tempSensBusLine);
DallasTemperature mySens(&oneWire);

BlynkTimer timer;

//Variables
float temp = 0;
int targetTemp = 0;

char auth[] = "2kbxhRIIOIsVCrhQMtX_MSLO9pmbfi-w";

char ssid[] = /*"The Office";*/"Don't even think about it";
char password[] = /*"switch403";*/"KusumaSas3";
//End of variables

//MAIN SETUP
void setup() 
{
  //Begin sensor functionality
  mySens.begin();
  
  //Begin Blynk functionality
  Blynk.begin(auth,ssid,password);

  //Setup Blynk app UI
  Blynk.virtualWrite(V3, 20);
  
  //Set the instance timer's interval to 1 sec
  timer.setInterval(500L, getTemperature);
  timer.setInterval(1000Lu, geazerSwitch);
  
  pinMode(relayIn, OUTPUT);
  /*digitalWrite(relayIn, LOW);*/
}

//MAIN LOOP
void loop() 
{
  Blynk.run();
  timer.run();
}

//Get Temperature START
void getTemperature()
{
  //Request for Temperature and store them in Scratch pad
  mySens.requestTemperatures();
  //Get Temperature in C
  temp = mySens.getTempCByIndex(0);
  //Send data to Blynk app
  Blynk.virtualWrite(V2, temp);
}
//Get Temperature END

//Loop to continuously monitor the Input Temperature
//START
BLYNK_WRITE(V3)
{
 targetTemp = param.asInt();
}
//END

//Geazer Switch function START
void geazerSwitch()
{
  if((int)temp<targetTemp)
  {
    switchOnGeazer();
  }
  else
  {
    switchOffGeazer();
  }
}
//Geazer Switch function END

//Switch Geazer ON START
void switchOnGeazer()
{
  digitalWrite(relayIn, LOW);
  Blynk.virtualWrite(V0, "HEATING WATER...");
  Blynk.virtualWrite(V1, "Please Wait");
}
//Switch Geazer ON END

//Switch Geazer OFF START
void switchOffGeazer()
{
  if(targetTemp==0)
  {
   digitalWrite(relayIn, HIGH);
   Blynk.virtualWrite(V0, "Hello, please");
   Blynk.virtualWrite(V1, "set Temperature!");
  }
  else if(targetTemp>=17 && targetTemp<20)
  {
    digitalWrite(relayIn, HIGH);
    Blynk.virtualWrite(V0, "Geazer OFF");
    Blynk.virtualWrite(V1, "You saved money!");
    delay(3000);
    targetTemp = 0;
  }
  else






































































  
  {
   digitalWrite(relayIn, HIGH);
   Blynk.virtualWrite(V0, "HEATING COMPLETE");
   Blynk.virtualWrite(V1, "Open Tap Now!!!");
  }
}
//Switch Geazer OFF END
