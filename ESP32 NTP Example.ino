#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Sensor.h>
#include "DHT.h"
#define DHTPIN 14      
#define DHTTYPE DHT22   
DHT dht(DHTPIN, DHTTYPE); 
int lcdColums = 20;
int lcdrows = 4;
LiquidCrystal_I2C lcd(0x27,lcdColums,lcdrows);
void setup()
{
  Serial.begin(9600);
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Test");
  lcd.clear();
}
void loop(){
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  lcd.setCursor(3,0);
  lcd.print("Humi=" + String(h)+"%");
  lcd.setCursor(3,1);
  lcd.print("Temp=" + String(t)+"C");
}