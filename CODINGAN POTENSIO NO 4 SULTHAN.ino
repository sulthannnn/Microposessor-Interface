const int potPin = A0;  // Potentiometer signal pin
const int servoPin = 9;  // Servo signal pin

#include <Servo.h>

Servo myServo;  // Create a servo object

void setup() {
  myServo.attach(servoPin);  // Attach the servo to the pin
}

void loop() {
  int potValue = analogRead(potPin);  // Read the potentiometer value
  int servoAngle = map(potValue, 0, 1023, 0, 180);  // Map the pot value to a servo angle
  myServo.write(servoAngle);  // Set the servo angle
  delay(15);  // Wait for the servo to move
}