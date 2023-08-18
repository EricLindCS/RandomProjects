int potetn = 0; //global variable, not nessesary here but why not


//define pins using phrases, not nessesary, but good practice
#define POTPIN 0
#define LED1 9
#define LED2 10
#define LED3 11
#define LED4 12

//function for program brevity
void lightup(int num){

    //turn all leds off
    for (int j=9; j < 13; j++)
    {
        digitalWrite(j, LOW);
    }
    
    //turn amount of leds on equal to potentiometer map value
    for (int i = 0; i < num; i++){
        digitalWrite((i+9), HIGH);
    }
}

//runs at start of program, defines output pins (do not need to define analog input pins)
void setup()
{
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);

    //begin serial connection to computer for debugging
    Serial.begin(9600); 
}

//Constantly iterates
void loop()
{
    potetn = analogRead(0); //get potentiometer value, 0 to 1023

//ignore this
    //Serial.write(potetn.ToString());
    //Serial.write(" & ");

    //do math to change potentiometer value to either 0,1,2,3,4 and print that value to console
    potetn = map(potetn, 0, 1023, 0, 4);
    Serial.println(potetn);
   
   //switch statement based on 0-4 value
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

    delay(100); //delay between iterations of the program
}