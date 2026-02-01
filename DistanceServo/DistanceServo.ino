#include <ESP32Servo.h>

const int TRIG_PIN = 13;
const int ECHO_PIN = 14;
const int GREEN_LED = 23;
const int RED_LED = 22;
const int THRESHOLD_CM = 5;
const int BLUE_BUTTON = 2;
const int BLUE_LED = 17;

const int SERVO_PIN = 15;
const int MAX_DISTANCE = 40;

int buttonState = 0;

Servo myServo;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(BLUE_BUTTON, INPUT);
  Serial.begin(9600);

  myServo.attach(SERVO_PIN);

  Serial.println("Servo initialized on pin 15");
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  buttonState = digitalRead(BLUE_BUTTON);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  int distance = duration * 0.034 / 2;

  if (distance > 0 && distance <= THRESHOLD_CM) {
    digitalWrite(RED_LED, HIGH);
  } else {
    digitalWrite(RED_LED, LOW);
  }

  if (distance > 0 && distance > THRESHOLD_CM) {
    digitalWrite(GREEN_LED, HIGH);
  } else {
    digitalWrite(GREEN_LED, LOW);
  }


  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(BLUE_LED, HIGH);
  } else {
    // turn LED off:
    digitalWrite(BLUE_LED, LOW);
  }

  int servoAngle = map(constrain(distance, 0, MAX_DISTANCE), 0, MAX_DISTANCE, 180, 0);
  myServo.write(servoAngle);

  Serial.print("Button State: ");
  Serial.print(buttonState);
  Serial.print(" Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Servo Angle: ");
  Serial.println(servoAngle);
  delay(100);
}
