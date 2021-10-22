//done by mehedi
#include <Wire.h>
#include <LiquidCrystal.h>

#include <OneWire.h>
#include <DallasTemperature.h>
// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_PIN 8
#define PHPin A0// 

OneWire oneWire(ONE_WIRE_PIN);
DallasTemperature sensors(&oneWire);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 

float PHval;// 
void setup()
{
  lcd.begin(16, 2);
  lcd.print("Current Temp:"); 
  
  pinMode(13,OUTPUT);  
  Serial.begin(9600);  
  Serial.println("pH meter !");    //Test the serial monitor

}
 
 
void loop()
{
  getTemp();
  delay(1000);
  getPH();//
  delay(10000);//
  
}
void getTemp()
{
  lcd.setCursor(0, 1);
  sensors.requestTemperatures();
  lcd.print(sensors.getTempCByIndex(0));
  lcd.print("C");
  }
void getPH()//
 {
  PHval=analogRead(A0)/1024.0*5.0*1.45;
  Serial.print("    PH value: ");     
  Serial.println(PHval);
   lcd.setCursor(0,1);
   lcd.print("PH:"); 
   lcd.setCursor(12,1);
   lcd.println(PHval);
  }
  
  
