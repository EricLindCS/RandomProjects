#define BUTTON_PIN PB3

void setup() {
  // put your setup code here, to run once:
  pinMode(PB7, OUTPUT);
  pinMode(PB5, INPUT);
  pinMode(PC13, OUTPUT);
  digitalWrite(PB7, HIGH);
  digitalWrite(PC13, LOW);
  delay(1000);
  
  digitalWrite(PB7, LOW);
  digitalWrite(PC13, HIGH);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  delay(2000);

  pinMode(PB8, OUTPUT);
     pinMode(PB9, INPUT_PULLUP);



}

bool hast = false;

void loop() {

  // put your main code here, to run repeatedly:
  if(!digitalRead(BUTTON_PIN)){
   // if(!hast){
    //  hast = true;
    //  delay(1000);
    //  digitalWrite(PB7, HIGH);
    //}
    delay(1000);
    digitalWrite(PB7, HIGH);
    delay(3000);
    digitalWrite(PB7, LOW);
  }
  
  delay(1000);
  /*
  digitalWrite(PB7, LOW);
  digitalWrite(PC13, HIGH);
  delay(1000);
    hast = false;
*/

  if(digitalRead(PB9)){
    digitalWrite(PB8, HIGH);
  }
  else {
    digitalWrite(PB8, LOW);
  }
//digitalWrite(PB8, LOW);
//delay(1000);
//digitalWrite(PB8, HIGH);



  delay(100);
  
}
