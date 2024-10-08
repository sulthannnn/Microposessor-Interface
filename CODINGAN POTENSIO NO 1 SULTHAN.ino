const int potPin = A0;  // Pin analog untuk potensiometer

void setup() {
  Serial .begin(9600); // Memulai komunikasi serial
}

void loop() {
  int nilaiADC = analogRead(potPin); // Membaca nilai ADC dari potensiometer
  Serial.print("Nilai ADC: ");
  Serial.println(nilaiADC); // Menampilkan nilai ADC pada serial monitor
  delay(1000); // Tunda selama 1 detik
}