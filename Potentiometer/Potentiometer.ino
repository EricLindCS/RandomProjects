int _potetn = 0; //global variable, not nessesary here but why not

//define pins using phrases, not nessesary, but good practice
#define POTENTIOMETER 0
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
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);

    //begin serial connection to computer for debugging
    Serial.begin(9600); 
}

//Constantly iterates
void loop()
{
    _potetn = analogRead(POTENTIOMETER); //get potentiometer value, 0 to 1023

    //ignore this//
    //Serial.write(_potetn.ToString());
    //Serial.write(" & ");

    //do math to change potentiometer value from 0-1023 to either 0,1,2,3,4 and print that value to console
    _potetn = map(_potetn, 0, 1023, 0, 4);
    Serial.println(_potetn);
   
   //switch statement based on 0-4 value
    switch (_potetn)
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

    /*instead of the code block above, you could just write this*/
    //lightup(_potetn);

    delay(100); //delay between iterations of the program
}