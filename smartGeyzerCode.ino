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

//////////////////////////////
//Variables Start
float temp = 0;
float targetTemp1 = 0;/*Set on app*/
float targetTemp2 = 0;/*Set in code*/
uint8_t firstTime=1;
uint8_t flag=0;
//Variables End
//////////////////////////////

char auth[] = "2kbxhRIIOIsVCrhQMtX_MSLO9pmbfi-w";

char ssid[] = /*"YOUR_WIFI_NAME"*/
char password[] = /*"YOUR_WIFI_PASSWORD"*/
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
  
  //Set the time period after which the specified function is repeated forever
  timer.setInterval(500L, getTemperature);//Repeats after every 500ms
  timer.setInterval(1000L, geazerSwitch);//Repeats after every 1000ms
  
  pinMode(relayIn, OUTPUT);
}

//MAIN LOOP
void loop() 
{
  Blynk.run();
  timer.run();
}

//Get Temperature function START
void getTemperature()
{
  //Request for Temperature
  mySens.requestTemperatures();
  
  //Get Temperature in C
  temp = mySens.getTempCByIndex(0);
  
  //Send data to the guage on the Blynk app
  Blynk.virtualWrite(V2, temp);
}
//Get Temperature function END

//Runs continuously monitor the Input Temperature
//START
BLYNK_WRITE(V3)
{
 targetTemp1 = param.asInt();
 targetTemp2 = targetTemp1-1;
}
//END

//Geazer Switch function START
void geazerSwitch()
{
  if(firstTime && temp<targetTemp1)
  {
    switchOnGeazer();
  }
  else if(!firstTime && temp<targetTemp1)
  {
    if(temp<targetTemp2)
    {
      switchOnGeazer();
      flag=1;
    }
    else if(temp>=targetTemp2 && flag==1)
    {
      switchOnGeazer();
    }
    else
    {
      switchOffGeazer();
    }
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
  if(targetTemp1==0)
  {
   digitalWrite(relayIn, HIGH);
   Blynk.virtualWrite(V0, "Hello, please");
   Blynk.virtualWrite(V1, "set Temperature!");
  }
  else if(targetTemp1>=17 && targetTemp1<20)
  {
    digitalWrite(relayIn, HIGH);
    Blynk.virtualWrite(V0, "Geazer OFF");
    Blynk.virtualWrite(V1, "You saved money!");
    delay(3000);
    firstTime=1;
    targetTemp1 = 0;
  }
  else
  {
   digitalWrite(relayIn, HIGH);
   Blynk.virtualWrite(V0, "HEATING COMPLETE");
   Blynk.virtualWrite(V1, "Open Tap Now!!!");
   firstTime=0;
   flag=0;
  }
}
//Switch Geazer OFF END
