#include <LiquidCrystal.h> 
#include <OneWire.h> 
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 8 

int fanPin = 11;


OneWire oneWire(ONE_WIRE_BUS); 

DallasTemperature sensors(&oneWire);
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); 

void setup(void) 
{ 
 pinMode(fanPin, OUTPUT);
 
 sensors.begin(); 

 lcd.begin(16,2);
} 
void loop(void) 
{ 
 sensors.requestTemperatures();
 
 int Temp = (sensors.getTempFByIndex(0));
 String fanPosition = "";

 if(Temp > 78){
  digitalWrite(fanPin, HIGH);
  fanPosition = " On";
 }
 else{
  digitalWrite(fanPin, LOW);
  fanPosition = "Off";
 }
 
 lcd.setCursor(0,0);
 lcd.print("Temp is: ");
 lcd.print(Temp);
 lcd.print("F");
 lcd.setCursor(0,1);
 lcd.print(" Fan is: " + fanPosition);
}
