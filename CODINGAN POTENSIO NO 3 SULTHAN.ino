const int potPin = A0;  // Potentiometer signal pin
const int ledPin = 9;   // LED pin

void setup() {
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
}

void loop() {
  int potValue = analogRead(potPin);  // Read potentiometer value (0-1023)
  int brightness = map(potValue, 0, 1023, 0, 255);  // Map pot value to PWM value (0-255)
  analogWrite(ledPin, brightness);  // Set LED brightness using PWM
  delay(10);  // Small delay to avoid flickering
}