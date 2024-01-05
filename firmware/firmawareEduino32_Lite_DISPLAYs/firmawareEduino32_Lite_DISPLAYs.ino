int clockpin = 4;  // Cuando hay que leer los bits      SH
int data = 16;     // Envío de datos                     DS
int latch = 17;    // Indica pin de salida en el chip ST

int clockpin1 = 5;   // Cuando hay que leer los bits      SH
int data1 = 18;      // Envío de datos                     DS
int latch1 = 19;     // Indica pin de salida en el chip ST



const int numero[] = { 63, 6, 91, 79, 102, 109, 125, 7, 127, 103, 63 };
const int numero1[] = { 63, 6, 91, 79, 102, 109, 125, 7, 127, 103, 63 };

unsigned long lastMillis = 0;
const int interval = 500; // Intervalo de 1 segundo

int contador_unidades = 0;
int contador_decenas = 0;

void setup() {
  pinMode(latch, OUTPUT);
  pinMode(clockpin, OUTPUT);
  pinMode(data, OUTPUT);

  pinMode(latch1, OUTPUT);
  pinMode(clockpin1, OUTPUT);
  pinMode(data1, OUTPUT);

  digitalWrite(latch1, LOW);
  shiftOut(data1, clockpin1, MSBFIRST, numero1[0]);
  digitalWrite(latch1, HIGH);

  digitalWrite(latch, LOW);
  shiftOut(data, clockpin, MSBFIRST, numero[0]);
  digitalWrite(latch, HIGH);
}

void updateDisplay(int value, int pin_data, int pin_clock, int pin_latch) {
  digitalWrite(pin_latch, LOW);
  shiftOut(pin_data, pin_clock, MSBFIRST, value);
  digitalWrite(pin_latch, HIGH);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - lastMillis >= interval) {
    lastMillis = currentMillis;

    contador_unidades++;
    if (contador_unidades == 10) {
      contador_unidades = 0;
      contador_decenas++;
      if (contador_decenas == 10) {
        contador_decenas = 0;
      }
    }

    updateDisplay(numero[contador_unidades], data, clockpin, latch);
    updateDisplay(numero1[contador_decenas], data1, clockpin1, latch1);
  }
}
