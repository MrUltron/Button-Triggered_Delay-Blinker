# 🔘 Button-Triggered Delay Blinker 🔦

A simple Arduino project where an LED blinks with a delay when a button is pressed. This project uses digital input with software debounce and toggled LED blinking.

---

## 📦 Components Required

| Component        | Description              |
|------------------|--------------------------|
| Arduino UNO/Nano | Microcontroller board 🧠 |
| Push Button      | Digital input trigger 🔘 |
| LED              | Output indicator 💡      |
| Resistor (220Ω)  | For LED current limiting |
| Jumper Wires     | Connections              |
| Breadboard       | Prototyping              |

---

## 🔌 Circuit Diagram

- Button leg ➜ `Digital Pin 2`
- Button other leg ➜ `GND`
- LED anode (+) ➜ `Digital Pin 13` *(or any digital pin)*
- LED cathode (–) ➜ `GND` through `220Ω` resistor

> 💡 Using internal pull-up for button input — no external pull-up resistor needed!

---

## 🧠 Features

- Press button once ➜ Start blinking
- Press button again ➜ Stop blinking
- Includes debounce logic (50ms)
- Built-in LED (pin 13) supported

---

## 🧪 Arduino Code

```cpp
const int buttonPin = 2;
const int ledPin = 13;
bool blinking = false;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(buttonPin);
  if (reading == LOW && (millis() - lastDebounceTime) > debounceDelay) {
    blinking = !blinking;
    lastDebounceTime = millis();
    delay(200);
  }

  if (blinking) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
```