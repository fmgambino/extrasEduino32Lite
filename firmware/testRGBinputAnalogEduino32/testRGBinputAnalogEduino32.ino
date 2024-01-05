//LEDS
const int ledR = 15;
const int ledG = 2;
const int ledB = 23;
// PMW SIGNAL
const int canalPWM = 0;
const int canalPWM1 = 1;
const int canalPWM2 = 2;

const int frecuencia = 500; // en Hz
const int resolucion = 12; // 8-16 bits de resolución.

void setup()
{
  Serial.begin(9600);
  // 1) configura señal PWM
  ledcSetup(canalPWM, frecuencia, resolucion);
  ledcSetup(canalPWM1, frecuencia, resolucion);
  ledcSetup(canalPWM2, frecuencia, resolucion);

  ledcAttachPin(ledR, canalPWM);
  ledcAttachPin(ledG, canalPWM1);
  ledcAttachPin(ledB, canalPWM2);
}

void loop()
{
  ledcWrite(canalPWM, analogRead(A0)); // Belong to VP
  Serial.println (analogRead(A0));
  ledcWrite(canalPWM1, analogRead(A3));// Belong to VN
  Serial.println (analogRead(A3));
  ledcWrite(canalPWM2, analogRead(A6));// Belong to VN
  Serial.println (analogRead(A6));
  delay(100);
}