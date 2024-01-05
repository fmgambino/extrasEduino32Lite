#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
float ldrPin = 39;  // Cambia esto al número de pin al que conectaste tu LDR

void setup()
{
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("  Hola Mundo ");
  Serial.println("EDUINO32 LITE");
  lcd.setCursor(0,1);
  lcd.print("  EDUINO32 LITE ");
  Serial.println("EDUINO32 LITE");
  //delay(2000);
}

void loop()
{
  int ldrValue = analogRead(ldrPin);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Luminosidad: ");
  lcd.print(ldrValue);
  Serial.print("Valor: ");
  Serial.println(ldrValue);

  delay(1000);  // Espera un segundo antes de leer nuevamente
}
