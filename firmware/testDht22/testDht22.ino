#include <DHT.h>

// Declara el pin del sensor DHT22
#define DHTPIN 32

// Declara el tipo de sensor DHT22
#define DHTTYPE DHT22

// Declara el sensor DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Inicializa el puerto serie
  Serial.begin(9600);

  // Inicializa el sensor DHT22
  dht.begin();
}

void loop() {
  // Lee los datos del sensor DHT22
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();

  // Imprime la humedad y temperatura
  Serial.print("Humedad: ");
  Serial.print(hum);
  Serial.print(" %, ");
  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println(" *C");

  // Retraso de 2 segundos
  delay(2000);
}
