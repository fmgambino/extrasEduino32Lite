#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Dirección I2C del LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Definir el pin al que está conectado el sensor en el ESP32
const int lm35 = 36;  // Por ejemplo, si está conectado al pin 34

void setup() {
  // Inicializar el LCD
  lcd.init();
  
  // Inicializar el monitor serial
  Serial.begin(9600);
}

void loop() {
  // Leer la temperatura del sensor LM35
  int lecturaSensor = analogRead(lm35);
  // Serial.print("Dato: ");
  // Serial.println(lecturaSensor);
  float temperaturaC = (lecturaSensor / 4095.0) * 3300 / 10;  // Convertir el valor a grados Celsius

  // Mostrar la temperatura en el LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperatura: ");
  lcd.setCursor(0, 1);
  lcd.print(temperaturaC);
  lcd.print(" C");

  // Imprimir la temperatura en el monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temperaturaC);
  Serial.println(" C");

  // Esperar 1 segundo
  delay(1000);
}
