//pin defintions (STM32)
//Not required, but makes it easier to keep track of what does what

#define BUTTON_PIN PB5 //Contact pin 1
#define ENDPNEU PB8 //Relay out (single action solenoid)
#define RAMPPNEU PB7 //Relay out (double-action solenoid)
#define LED_BUILTIN PC13 //Board's built in LED
#define BUTTON_PIN_2 PB9 //Contact pin 2

void setup() {
  
  //Pin setups
  pinMode(ENDPNEU, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(RAMPPNEU, OUTPUT);
  pinMode(BUTTON_PIN_2, INPUT_PULLUP);

  //Reset double action pneumatics cycle (with visual indicator)
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(RAMPPNEU, HIGH);
  delay(1000);
  digitalWrite(RAMPPNEU, LOW);
  digitalWrite(LED_BUILTIN, HIGH);
  
  delay(2000);

}

void loop() {

  // Ramp pneumatics relay handeler
  if(!digitalRead(BUTTON_PIN)){ //See if ball is completing the circut
    delay(1000); //Give the ball time to stop
    digitalWrite(RAMPPNEU, HIGH); //Actuate piston
    delay(3000); //Give the ball time to roll down ramp

    digitalWrite(RAMPPNEU, LOW); //Re-lower ramp for testing purposes, !!!remove later!!!
  }

  if(digitalRead(BUTTON_PIN_2)){ //See if ball 2 is completing the other circut
    digitalWrite(ENDPNEU, HIGH); //Actuate piston
  }
  else {
    digitalWrite(ENDPNEU, LOW); //Release Piston
  }

  delay(200); //delay between each cycle of the loop
  
}
