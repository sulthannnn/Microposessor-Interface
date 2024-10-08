const int potPin = A0;  // Potentiometer connected to Analog Input A0

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 bps
}

void loop() {
  int adcValue = analogRead(potPin);  // Read ADC value from potentiometer
  float voltage = (adcValue * 5.0) / 1023.0;  // Convert ADC value to voltage using the formula

  Serial.print("ADC Value: ");
  Serial.print(adcValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  delay(500);  // Wait for 500ms before taking the next reading
}