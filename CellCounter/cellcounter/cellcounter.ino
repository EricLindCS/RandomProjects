//define button pins
#define incrementButtonPin PB11
#define decrementButtonPin PB10
#define resetButtonPin PB1


// Pin mapping for segments and digits
const byte segmentPins[] = {PB0, PB14, PB4, PB8 ,PB6 ,PB3 ,PB7, PB5};
const byte digitPins[] = {PB13, PB12};

// Define the digit patterns for 0-9
const int digitPatterns[][8] = {
  {0, 0, 0, 0, 0, 0, 1, 1},  // 0
  {1, 0, 0, 1, 1, 1, 1, 1},  // 1
  {0, 0, 1, 0, 0, 1, 0, 1},  // 2
  {0, 0, 0, 0, 1, 1, 0, 1},  // 3
  {1, 0, 0, 1, 1, 0, 0, 1},  // 4
  {0, 1, 0, 0, 1, 0, 0, 1},  // 5
  {0, 1, 0, 0, 0, 0, 0, 1},  // 6
  {0, 0, 0, 1, 1, 1, 1, 1},  // 7
  {0, 0, 0, 0, 0, 0, 0, 1},  // 8
  {0, 0, 0, 0, 1, 0, 0, 1}   // 9
};

int number = 0;  // Current number

// Button pins

int incrementButtonState = HIGH;      // Current state of the increment button
int lastIncrementButtonState = HIGH;  // Previous state of the increment button
int decrementButtonState = HIGH;      // Current state of the decrement button
int lastDecrementButtonState = HIGH;  // Previous state of the decrement button
int resetButtonState = HIGH;          // Current state of the reset button
int lastResetButtonState = HIGH;      // Previous state of the reset button

void setup() {
  // Set the digit and segment pins as OUTPUT
  for (int i = 0; i < sizeof(digitPins) / sizeof(digitPins[0]); i++) {
    pinMode(digitPins[i], OUTPUT);
  }

  for (int i = 0; i < sizeof(segmentPins) / sizeof(segmentPins[0]); i++) {
    pinMode(segmentPins[i], OUTPUT);
  }

  // Set button pins as INPUT
  pinMode(incrementButtonPin, INPUT_PULLUP);
  pinMode(decrementButtonPin, INPUT_PULLUP);
  pinMode(resetButtonPin, INPUT_PULLUP);
}

void loop() {
  // Read the state of the buttons
  incrementButtonState = digitalRead(incrementButtonPin);
  decrementButtonState = digitalRead(decrementButtonPin);
  resetButtonState = digitalRead(resetButtonPin);

  // Check if the increment button is pressed (falling edge detected)
  if (incrementButtonState == LOW && lastIncrementButtonState == HIGH) {
    incrementNumber();  // Increment the number
  }

  // Check if the decrement button is pressed (falling edge detected)
  if (decrementButtonState == LOW && lastDecrementButtonState == HIGH) {
    decrementNumber();  // Decrement the number
  }

  // Check if the reset button is pressed (falling edge detected)
  if (resetButtonState == LOW && lastResetButtonState == HIGH) {
    resetNumber();  // Reset the number to 0
  }

  // Update the last button states
  lastIncrementButtonState = incrementButtonState;
  lastDecrementButtonState = decrementButtonState;
  lastResetButtonState = resetButtonState;

  // Display the current number
  displayNumber();
}

void incrementNumber() {
  number++;  // Increment the number
  if (number > 99) {
    number = 99;  // Limit the number to 99
  }
}

void decrementNumber() {
  number--;  // Decrement the number
  if (number < 0) {
    number = 0;  // Limit the number to 0
  }
}

void resetNumber() {
  number = 0;  // Reset the number to 0
}

void displayNumber() {
  int tensDigit = number / 10;     // Extract the tens digit
  int onesDigit = number % 10;     // Extract the ones digit

  // Turn off all digits
  for (int i = 0; i < sizeof(digitPins) / sizeof(digitPins[0]); i++) {
    digitalWrite(digitPins[i], LOW);
  }

  // Set the segment pins based on the digit pattern for the tens digit
  for (int i = 0; i < sizeof(segmentPins) / sizeof(segmentPins[0]); i++) {
    if (digitPatterns[tensDigit][i] == 1) {
      digitalWrite(segmentPins[i], HIGH);  // Common anode, so HIGH turns on segments
    } else {
      digitalWrite(segmentPins[i], LOW);
    }
  }

  // Enable the tens digit
  digitalWrite(digitPins[0], HIGH);
  delay(5);  // Small delay for multiplexing

  // Turn off all segments
  for (int i = 0; i < sizeof(segmentPins) / sizeof(segmentPins[0]); i++) {
    digitalWrite(segmentPins[i], LOW);
  }

  // Set the segment pins based on the digit pattern for the ones digit
  for (int i = 0; i < sizeof(segmentPins) / sizeof(segmentPins[0]); i++) {
    if (digitPatterns[onesDigit][i] == 1) {
      digitalWrite(segmentPins[i], HIGH);  // Common anode, so HIGH turns on segments
    } else {
      digitalWrite(segmentPins[i], LOW);
    }
  }

  // Enable the ones digit
  digitalWrite(digitPins[1], HIGH);
  delay(5);  // Small delay for multiplexing
}