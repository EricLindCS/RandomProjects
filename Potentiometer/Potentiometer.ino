int potetn = 0;

#define POTPIN 0
#define LED1 9
#define LED2 10
#define LED3 11
#define LED4 12

void lightup(int num){
    for (int j=9; j < 13; j++)
    {
        digitalWrite(j, LOW);
    }
    
    for (int i = 0; i < num; i++){
        digitalWrite((i+9), HIGH);
    }
}

void setup()
{
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
   
    potetn = analogRead(0);
    //Serial.write(potetn.ToString());
    //Serial.write(" & ");
    potetn = map(potetn, 0, 1023, 0, 4);
    Serial.println(potetn);
   
    switch (potetn)
    {
    case 0:
        lightup(0);
        break;
    case 1:
        lightup(1);
        break;
    case 2:
        lightup(2);
        break;
    case 3:
        lightup(3);
        break;
    case 4:
        lightup(4);
        break;
    default:
        break;
    }
    delay(100);
}