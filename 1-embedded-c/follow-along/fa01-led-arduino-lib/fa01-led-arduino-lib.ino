// This sketch blinks the built-in LED on and off every 1 second.

void setup() {
    // Initialize pin 13 (onboard LED) as an output:
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED on
    delay(500);                       // Wait for 1 second
    digitalWrite(LED_BUILTIN, LOW);   // Turn the LED off
    delay(500);                       // Wait for 1 second

    // Stop the loop forever
    while (true) {
        // Do nothing — loop is now "stopped"
    }
}
