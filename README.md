# 🔐 Arduino Password Door Lock System

This project is a simple password-protected door lock system using an Arduino UNO, 4x4 keypad, servo motor, and an LED. The system unlocks the door (servo rotates) only when the correct password is entered via the keypad. It's perfect for beginners learning Arduino and basic security applications.

---

## 🧾 Features

- Password-based access control
- Unlocks door using a servo motor
- LED indicator for access status
- `#` to submit the password
- `*` to clear/reset the password entry
- Simple and compact design using basic components

---

## 🧰 Components Required

| Component       | Quantity |
|----------------|----------|
| Arduino UNO     | 1        |
| 4x4 Keypad      | 1        |
| Servo Motor (e.g., SG90) | 1        |
| LED             | 1        |
| 220Ω Resistor   | 1        |
| Jumper Wires    | As needed |
| Breadboard      | 1        |

---

## 🔌 Pin Connections

| Component     | Arduino Pin |
|---------------|-------------|
| Keypad Rows   | 9, 8, 7, 6   |
| Keypad Columns| 5, 4, 3, 2   |
| Servo Signal  | 10          |
| Servo VCC     | 5V          |
| Servo GND     | GND         |
| LED (+ via 220Ω resistor) | 13 |
| LED (GND)     | GND         |

---

## 🔐 Default Password

