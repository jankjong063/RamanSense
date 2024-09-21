#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD I2C address and dimensions (16x2)
const int sensorPin = A0; // Analog pin connected to the Raman laser sensor

void setup() {
  lcd.begin(16, 2); // Correct initialization with the number of columns and rows
  lcd.backlight();
  Serial.begin(9600);
  
  lcd.setCursor(0, 0);
  lcd.print("Object Detection");
  delay(2000);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  
  // Simulating object detection based on reflection data
  if (sensorValue > 800) {
    displayData("Metallic Object", sensorValue);
  } else if (sensorValue > 500) {
    displayData("Plastic Object", sensorValue);
  } else {
    displayData("Unknown Object", sensorValue);
  }
  
  delay(1000); // Update every second
}

void displayData(String objectType, int sensorValue) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(objectType);
  lcd.setCursor(0, 1);
  lcd.print("Reflect: ");
  lcd.print(sensorValue);
  Serial.println("Object: " + objectType + ", Reflection: " + String(sensorValue));
}
