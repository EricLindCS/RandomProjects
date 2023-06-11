

// Pin mapping for segments and digits
const byte segmentPins[] = {PB0, PB14, PB4, PB8 ,PB6 ,PB3 ,PB7, PB5};
const byte digitPins[] = {PB13, PB12};

// Define the digit patterns for 0-9
const int digitPatterns[][8] = {
  {1, 1, 1, 1, 1, 1, 0, 0},  // 0
  {0, 1, 1, 0, 0, 0, 0, 0},  // 1
  {1, 1, 0, 1, 1, 0, 1, 0},  // 2
  {1, 1, 1, 1, 0, 0, 1, 0},  // 3
  {0, 1, 1, 0, 0, 1, 1, 0},  // 4
  {1, 0, 1, 1, 0, 1, 1, 0},  // 5
  {1, 0, 1, 1, 1, 1, 1, 0},  // 6
  {1, 1, 1, 0, 0, 0, 0, 0},  // 7
  {1, 1, 1, 1, 1, 1, 1, 0},  // 8
  {1, 1, 1, 1, 0, 1, 1, 0}   // 9
};

void setup() {
  // Set the digit and segment pins as OUTPUT
  for (int i = 0; i < sizeof(digitPins) / sizeof(digitPins[0]); i++) {
    pinMode(digitPins[i], OUTPUT);
  }

  for (int i = 0; i < sizeof(segmentPins) / sizeof(segmentPins[0]); i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop() {
  // Display numbers 0-9 repeatedly
  for (int i = 0; i < 10; i++) {
    displayNumber(i);
    delay(1500);
  }
}

void displayNumber(int number) {
  // Turn off all digits
  for (int i = 0; i < sizeof(digitPins) / sizeof(digitPins[0]); i++) {
    digitalWrite(digitPins[i], HIGH);
  }

  // Set the segment pins based on the digit pattern
  for (int i = 0; i < sizeof(segmentPins) / sizeof(segmentPins[0]); i++) {
    if (digitPatterns[number][i] == 1) {
      digitalWrite(segmentPins[i], LOW);  // Common anode, so LOW turns on segments
    } else {
      digitalWrite(segmentPins[i], HIGH);
    }
  }

  // Enable the corresponding digit
 // digitalWrite(digitPins[number], LOW);
 digitalWrite(digitPins[0], LOW);
}