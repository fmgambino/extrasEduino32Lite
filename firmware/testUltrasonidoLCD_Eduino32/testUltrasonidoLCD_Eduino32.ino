#include <LiquidCrystal_I2C.h> // Debe descargar la Libreria que controla el I2C
//#include<Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int trigger = 33;           // declaramos la palabra trigger como un tipo entero y al mismo tiempo reemplaza al pin 34
int echo = 32;           // declaramos la palabra echo como un tipo entero y al mismo tiempo reemplaza al pin 35
float tiempo_de_espera, distancia; // creamos una variable de fotante; es decir, nos puede dar resultados en decimales.

void setup() {
  Serial.begin(9600);
  pinMode (trigger, OUTPUT); // declarmos el pin 34 como salida
  pinMode (echo, INPUT);   // declaramos el 35 como entrada
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("EDUINO32 LITE"); // Mensaje a despegar
  lcd.setCursor(0, 1);
  lcd.print("Gracias p/Comprar ^_^"); // Mensaje a despegar
  delay(3000);
  lcd.clear();

}

void loop() {

  digitalWrite (trigger, LOW); 
  delayMicroseconds(4);
  digitalWrite (trigger, HIGH);
  delayMicroseconds (10);    
  digitalWrite (trigger, LOW);

  tiempo_de_espera = pulseIn (echo, HIGH); // pulseIn, recoge la señal del sonido que emite el trigger

  /*La función pulseIn espera la aparición de un pulso en una entrada y mide su duración, dando como resultado la duración medida
    El primer parámetro (ECHO) es el pin sobre el que se realizará la medición.
    Y el segundo parámetro (HIGH) indica si el pulso a esperar será un 1 (HIGH) o un 0 (LOW).
  */
  distancia = (tiempo_de_espera / 2) / 29.15; // formula para hallar la distancia

  lcd.setCursor(0, 0);
  lcd.print("distancia"); // Mensaje a despegar
  lcd.setCursor(0, 1);
  lcd.print(distancia); // Mensaje a despegar
   lcd.setCursor(7, 1);
  lcd.print("cm");
  Serial.println(distancia);
 delay(200);
 // lcd.clear();
}