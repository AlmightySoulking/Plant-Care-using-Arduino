#include <LiquidCrystal.h>
#include <DHT.h>
#define DHTPIN 13
#define DHTTYPE DHT11
#define LDR_PIN 9
#define SOIL_MOISTURE_DO_PIN A2 
#define SOIL_MOISTURE_AO_PIN A3
DHT dht(DHTΡΙΝ, DHTTYPE);
LiquidCrystal lcd (7,6,5,4,3,2);
void setup() {
  lcd.begin(16,2);
  dht.begin();
  lcd.print("Initializing");
  delay(2000);
  lcd.clear();
  pinMode(LDR_PIN,INPUT);
  pinMode(SOIL_MOISTURE_DO_PIN,INPUT);
  pinMode(12,OUTPUT);
  digitalWrite(12,HIGH);
  
void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int soilMoistureDigitalValue = digitalRead(SOIL_MOISTURE_DO_PIN);
  int soilMoistureAnalogValue = analogRead(SOIL_MOISTURE_AO_PIN);
  int ldrValue = digitalRead(LDR_PIN);
  if (isnan(temperature) || isnan(humidity)) {
    lcd.setCursor(0, 0);
    lcd.print("DHT11 Error");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print("C");
    
    lcd.setCursor(9, 0);
    lcd.print("Hum: ");
    lcd.print(humidity);
  lcd.print("%");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(soilMoistureDigitalValue == LOW ? "Soil Dry " : "Soil Wet ");
    lcd.setCursor(0, 1);
    lcd.print("Moisture: ");
    lcd.print(soilMoistureAnalogValue);
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(ldrValue == LOW ? "It's Night" : "It's Day");
    delay(2000);
  }
}