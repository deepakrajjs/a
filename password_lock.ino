#include <Keypad.h>
#include <Servo.h>

// Servo motor setup
Servo lockServo;
const int servoPin = 10;

// LED pin
const int ledPin = 13;

// Correct password
const String correctPassword = "1234";
String inputPassword = "";

// Keypad configuration
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  lockServo.attach(servoPin);
  lockServo.write(0); // Locked position
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (key == '#') {
      if (inputPassword == correctPassword) {
        digitalWrite(ledPin, HIGH);
        lockServo.write(90);      // Unlock
        delay(5000);              // Keep unlocked for 5 sec
        lockServo.write(0);       // Lock again
        digitalWrite(ledPin, LOW);
      } else {
        for (int i = 0; i < 3; i++) {
          digitalWrite(ledPin, HIGH);
          delay(200);
          digitalWrite(ledPin, LOW);
          delay(200);
        }
      }
      inputPassword = ""; // Reset after attempt
    }
    else if (key == '*') {
      inputPassword = ""; // Clear entry
    }
    else {
      inputPassword += key; // Add key to input
    }
  }
}
