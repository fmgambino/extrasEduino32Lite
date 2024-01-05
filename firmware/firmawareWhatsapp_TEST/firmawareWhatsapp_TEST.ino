#include <WiFiManager.h>
#include <WiFi.h>
#include <NTPClient.h>
#include <RTClib.h>

// Librerías para Twilio
#include <WiFiClientSecure.h>
#include <Base64.h>
#include <ArduinoJson.h>

// Configura las credenciales de Twilio
const char* accountSid = "ACc782f7841555aa109ce8d060decb9ea5";
const char* authToken = "ee91142a85d1f1e0fa6f0d4c13353b33";
const char* twilioNumber = "whatsapp:+14155238886"; // Número de Twilio para enviar mensajes a WhatsApp
const char* myNumber = "whatsapp:+543816150488"; // Tu número de WhatsApp

WiFiClientSecure client;
NTPClient timeClient(client, "pool.ntp.org");

RTC_DS3231 rtc;

void setup() {
  Serial.begin(115200);

  // Inicializa el RTC
  if (!rtc.begin()) {
    Serial.println("No se puede encontrar el módulo RTC. Verifique las conexiones.");
    while (1);
  }

  // Intenta cargar la hora desde el RTC
  if (rtc.lostPower()) {
    Serial.println("El módulo RTC ha perdido energía, ajustando la hora!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  // Configura Wi-Fi a través de WiFiManager
  WiFiManager wm;
  wm.autoConnect("ESP32-Config");

  // Inicializa la conexión NTP
  timeClient.begin();
}

void loop() {
  timeClient.update();

  DateTime now = timeClient.getFormattedTime();
  Serial.print("Fecha y hora actuales: ");
  Serial.println(now.timestamp(DateTime::TIMESTAMP_FULL));

  // Envía la fecha y hora a través de WhatsApp
  sendWhatsAppMessage(now);

  delay(60000); // Espera 1 minuto antes de volver a enviar la hora
}

void sendWhatsAppMessage(DateTime time) {
  Serial.println("Enviando mensaje por WhatsApp...");

  String message = "Fecha y hora actual: " + time.timestamp(DateTime::TIMESTAMP_FULL);

  // Construye la URL para la API de Twilio
  String url = "https://api.twilio.com/2010-04-01/Accounts/" + String(accountSid) + "/Messages.json";

  // Construye la solicitud HTTP para Twilio
  String auth = base64::encode(String(accountSid) + ":" + String(authToken));
  String postData = "To=" + myNumber + "&From=" + twilioNumber + "&Body=" + message;
  
  client.begin(url);
  client.addHeader("Authorization", "Basic " + auth);
  client.addHeader("Content-Type", "application/x-www-form-urlencoded");

  int httpCode = client.POST(postData);

  if (httpCode > 0) {
    String payload = client.getString();
    Serial.println("Respuesta de Twilio: " + payload);
  } else {
    Serial.println("Error en la solicitud HTTP a Twilio");
  }

  client.end();
}
