/* 
  IR Breakbeam sensor demo!
*/


const int BUTTON_PIN = 6; // the number of the pushbutton pin

// Variables will change:
int lastStateb = HIGH; // the previous state from the input pin
int currentState;    // the current reading from the input pin

#define LEDPIN 8
  // Pin 13: Arduino has an LED connected on pin 13
  // Pin 11: Teensy 2.0 has the LED on pin 11
  // Pin  6: Teensy++ 2.0 has the LED on pin 6
  // Pin 13: Teensy 3.0 has the LED on pin 13

#define SENSORPIN 7

// variables will change:
int sensorState = 0, lastState=0;         // variable for reading the pushbutton status

void handleTime(){
 float st = millis();
  while(digitalRead(BUTTON_PIN) != LOW){
    if (digitalRead(SENSORPIN) == HIGH){
      Serial.println(((millis()-st)/1000.0),5);
      break;
    }
    if(digitalRead(BUTTON_PIN) == LOW){  ////remove later ////
      Serial.println("canc");
    }
  }
}



void setup() {
   pinMode(BUTTON_PIN, INPUT_PULLUP);
  // initialize the LED pin as an output:
  pinMode(LEDPIN, OUTPUT);      
  // initialize the sensor pin as an input:
  pinMode(SENSORPIN, INPUT);     
  digitalWrite(SENSORPIN, HIGH); // turn on the pullup
  
  Serial.begin(9600);
}

void loop(){
  // read the state of the pushbutton value:
  sensorState = digitalRead(SENSORPIN);

  // check if the sensor beam is broken
  // if it is, the sensorState is LOW:
  if (sensorState == LOW) {     
    // turn LED on:
    digitalWrite(LEDPIN, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(LEDPIN, LOW); 
  }
  
  if (sensorState && !lastState) {
    Serial.println("Unbroken");
  } 
  if (!sensorState && lastState) {
    Serial.println("Broken");
    handleTime();
  }
  lastState = sensorState;



  currentState = digitalRead(BUTTON_PIN);

  if(lastStateb == LOW && currentState == HIGH)
    Serial.println("The state changed from LOW to HIGH");

  // save the last state
  lastStateb = currentState;



}