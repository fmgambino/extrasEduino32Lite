#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int trigger = 33;
int echo = 32;
float tiempo_de_espera, distancia;

void setup() {
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("EDUINO32 LITE");

  delay(2000);

  String mensaje = " ¡Gracias PABLO por su Compra ^_^ ! ";
  desplazarMensajes("EDUINO32 LITE", mensaje);

  lcd.clear();
}

void loop() {
  digitalWrite(trigger, LOW);
  delayMicroseconds(4);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  tiempo_de_espera = pulseIn(echo, HIGH);
  distancia = (tiempo_de_espera / 2) / 29.15;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distancia");
  lcd.setCursor(0, 1);
  lcd.print(distancia);
  lcd.setCursor(7, 1);
  lcd.print("cm");
  Serial.println(distancia);
  delay(200);
}

void desplazarMensajes(String mensaje1, String mensaje2) {
  for (int i = 0; i <= mensaje2.length() + 15; i++) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(mensaje1);
    lcd.setCursor(0, 1);
    lcd.print(mensaje2.substring(i, i + 16));
    delay(350);
  }
}
