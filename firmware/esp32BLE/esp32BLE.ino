#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

int hum = 65;
int temp = 15;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT"); // Nombre del dispositivo Bluetooth
  Serial.println("ESP32 Bluetooth Serial Listo");
}

void loop() {
  // Actualiza el valor de humedad y temperatura (simulado)
  hum = random(0, 100);
  temp = random(10, 30);

  // Crea una cadena para los datos de humedad y temperatura
  String dataToSend = "Humedad: " + String(hum) + "%, Temperatura: " + String(temp) + "°C";

  // Envía los datos a través de Bluetooth
  SerialBT.print(dataToSend);

  // Intenta leer datos desde el dispositivo Bluetooth
  if (SerialBT.available()) {
    String receivedData = SerialBT.readStringUntil('\n'); // Lee hasta encontrar un salto de línea
    Serial.print("Recibido: ");
    Serial.println(receivedData);
  }

  // Espera un tiempo antes de enviar/recibir datos nuevamente
  delay(5000); // Puedes ajustar el intervalo según tus necesidades
}
#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

int hum = 65;
int temp = 15;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT"); // Nombre del dispositivo Bluetooth
  Serial.println("ESP32 Bluetooth Serial Listo");
}

void loop() {
  // Actualiza el valor de humedad y temperatura (simulado)
  hum = random(0, 100);
  temp = random(10, 30);

  // Crea una cadena para los datos de humedad y temperatura
  String dataToSend = "Humedad: " + String(hum) + "%, Temperatura: " + String(temp) + "°C";

  // Envía los datos a través de Bluetooth
  SerialBT.print(dataToSend);

  // Intenta leer datos desde el dispositivo Bluetooth
  if (SerialBT.available()) {
    String receivedData = SerialBT.readStringUntil('\n'); // Lee hasta encontrar un salto de línea
    Serial.print("Recibido: ");
    Serial.println(receivedData);
  }

  // Espera un tiempo antes de enviar/recibir datos nuevamente
  delay(5000); // Puedes ajustar el intervalo según tus necesidades
}
