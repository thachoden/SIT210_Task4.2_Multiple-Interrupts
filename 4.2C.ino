// Define pin numbers
const int buttonPin = 2;        // Push button pin
const int motionSensorPin = 3;  // Motion sensor pin
const int ledPin1 = 8;          // LED controlled by push button
const int ledPin2 = 7;         // LED controlled by motion sensor

// Variables to keep track of LED states
volatile bool ledState1 = false; // State of LED controlled by push button
volatile bool ledState2 = false; // State of LED controlled by motion sensor

// Interrupt Service Routines (ISRs)
void toggleLed1() {
    delay(100);
    ledState1 = !ledState1; // Toggle LED state
    digitalWrite(ledPin1, ledState1); // Update LED state
    Serial.println("button pushed");
}

void toggleLed2() {
    ledState2 = !ledState2; // Toggle LED state
    digitalWrite(ledPin2, ledState2); // Update LED state
    Serial.println("Motion detected");
}

void setup() {
    Serial.begin(9600);

    // Set pin modes
    pinMode(buttonPin, INPUT_PULLUP); // Use internal pull-up resistor
    pinMode(motionSensorPin, INPUT_PULLDOWN);   // Motion sensor input
    pinMode(ledPin1, OUTPUT);           // LED 1 output
    pinMode(ledPin2, OUTPUT);           // LED 2 output

    // Attach interrupts
    attachInterrupt(digitalPinToInterrupt(motionSensorPin), toggleLed2, RISING); // Trigger on motion detected
    attachInterrupt(digitalPinToInterrupt(buttonPin), toggleLed1, FALLING); // Trigger on button press

}

void loop() {
}
