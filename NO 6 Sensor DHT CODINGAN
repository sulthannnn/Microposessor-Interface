#include <ESP8266WiFi.h>
#include <DHT.h>
#include <ArduinoOTA.h>
#include <ESP8266HTTPClient.h>

// Konfigurasi WiFi
const char* ssid = "ee";           // Nama WiFi
const char* password = "12345678";   // Password WiFi

// Konfigurasi ThingSpeak
const char* server = "api.thingspeak.com";
const char* apiKey = "YOUR_API_KEY";      // Ganti dengan API Key ThingSpeak

// Konfigurasi DHT
#define DHTPIN 2                        // Pin yang terhubung ke DHT
#define DHTTYPE DHT22                    // Tipe DHT: DHT11 atau DHT22
DHT dht(DHTPIN, DHTTYPE);

// Variabel untuk waktu pengiriman data
unsigned long previousMillis = 0;
const long interval = 20000;              // Interval pengiriman data (20 detik)

void setup() {
  Serial.begin(115200);
  dht.begin();

  // Koneksi WiFi
  Serial.println("Menghubungkan ke WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWiFi Terhubung!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Konfigurasi OTA
  ArduinoOTA.onStart([]() {
    String type = (ArduinoOTA.getCommand() == U_FLASH) ? "sketch" : "filesystem";
    Serial.println("OTA Update Started: " + type);
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nOTA Update Selesai");
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("OTA Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });
  ArduinoOTA.begin();
  Serial.println("OTA Siap");
}

void loop() {
  ArduinoOTA.handle(); // Menangani proses OTA

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Membaca data sensor
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    // Periksa apakah pembacaan valid
    if (isnan(temperature) || isnan(humidity)) {
      Serial.println("Gagal membaca data dari sensor DHT!");
      return;
    }

    // Tampilkan data di Serial Monitor
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C, Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    // Kirim data ke ThingSpeak
    if (WiFi.status() == WL_CONNECTED) {
      WiFiClient client;
      if (client.connect(server, 80)) {
        String postStr = String("api_key=") + apiKey +
                         "&field1=" + String(temperature) +
                         "&field2=" + String(humidity);

        client.println("POST /update HTTP/1.1");
        client.println("Host: " + String(server));
        client.println("Connection: close");
        client.println("Content-Type: application/x-www-form-urlencoded");
        client.println("Content-Length: " + String(postStr.length()));
        client.println();
        client.println(postStr);

        Serial.println("Data dikirim ke ThingSpeak!");
      }
      client.stop();
    }
  }
}