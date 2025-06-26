// Button-Triggered Delay Blinker Code
// Components: Arduino, Push Button, LED
// Behavior: LED blinks with a delay after button press

const int buttonPin = 2;    // Push button connected to digital pin 2
const int ledPin = 13;      // Built-in LED on pin 13

int buttonState = 0;        // Variable to store button state
bool blinking = false;      // Toggle blinking on button press
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;  // Debounce delay in ms

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // Use internal pull-up resistor
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(buttonPin);

  // Simple debounce
  if (reading == LOW && (millis() - lastDebounceTime) > debounceDelay) {
    blinking = !blinking;
    lastDebounceTime = millis();
    Serial.println(blinking ? "Blinking ON" : "Blinking OFF");
    delay(200); // Button press delay
  }

  // Blink LED with delay if blinking is true
  if (blinking) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
