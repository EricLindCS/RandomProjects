#define BUTTON_PIN PB5
#define ENDPNEU PB8
#define RAMPPNEU PB7
#define LED_BUILTIN PC13
#define BUTTON_PIN_2 PB9

void setup() {
  
  pinMode(ENDPNEU, OUTPUT);
  //pinMode(PB5, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(RAMPPNEU, OUTPUT);
  pinMode(BUTTON_PIN_2, INPUT_PULLUP);

  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(RAMPPNEU, HIGH);
  delay(1000);
  digitalWrite(RAMPPNEU, LOW);
  digitalWrite(LED_BUILTIN, HIGH);
  
  delay(2000);

}

void loop() {

  // put your main code here, to run repeatedly:
  if(!digitalRead(BUTTON_PIN)){
    delay(1000);
    digitalWrite(RAMPPNEU, HIGH);
    delay(3000);
    digitalWrite(RAMPPNEU, LOW);
  }

  if(digitalRead(BUTTON_PIN_2)){
    digitalWrite(ENDPNEU, HIGH);
  }
  else {
    digitalWrite(ENDPNEU, LOW);
  }

  delay(200);
  
}
