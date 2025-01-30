#include <LiquidCrystal.h>

// Pin configuration for the LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// LDR and LED pin configuration
const int ldrPin = A0;          // Pin connected to LDR
const int threshold = 500;     // Adjust the threshold value for light sensitivity
const int ledPins[] = {6, 7, 8, 9, 10, 13}; // Pins for LEDs

void setup() {
  // Initialize the LCD
  lcd.begin(16, 2); // Set the dimensions of the LCD (16x2)
  lcd.print("Initializing...");

  // Configure LED pins as output
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // Configure LDR pin as input
  pinMode(ldrPin, INPUT);

  delay(2000); // Display initialization message for 2 seconds
  lcd.clear();
}

void loop() {
  int ldrValue = analogRead(ldrPin); // Read the LDR value

  if (ldrValue < threshold) { // Low light condition
    lcd.setCursor(0, 0); // Move cursor to the first row
    lcd.print("Night: Lights ON");
    
    // Turn on all LEDs
    for (int i = 0; i < 6; i++) {
      digitalWrite(ledPins[i], HIGH);
    }
  } else { // High light condition
    lcd.setCursor(0, 0);
    lcd.print(" Day: Lights OFF ");
    
    // Turn off all LEDs
    for (int i = 0; i < 6; i++) {
      digitalWrite(ledPins[i], LOW);
    }
  }

  delay(500); // Small delay for stability
}
