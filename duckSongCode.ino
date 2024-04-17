
#include <Servo.h>   

Servo myservo; // initialize servo
Servo myservo2;

//initialize the wire for the "button"
const int buttonPin = 2;
const int piezoPin = 3;
const int man = 4;
const int duck = 5;
const int startButton = 6;
const int ledStand = 7;
const int ledHouse = 8;
const int ledStore = 9;
const int ledStartButton = 10;
//const int manStand = 4;
//const int duckStand = 5;
//const int duckHome = 6;
// const int manStore = 8;

// myservo goes to 9
// myservo2 goes to 10

const int dialogueButton = 11;
const int storeGrapes = 12;
const int ledDialogueButton = 13;



State change Detection / variables to change
int buttonState;
//int lastButtonState = 0;
int actionVal;

void setup() {
  
  buttonState = 0;
  actionVal = 0;
  pinMode(buttonPin, INPUT);
  pinMode(man, INPUT);
  pinMode(duck, INPUT);
  pinMode(duckStore, INPUT);
  pinMode(startButton, INPUT);
  pinMode(dialogueButton, INPUT);
  pinMode(storeGrapes, INPUT);
  pinMode(ledHouse, OUTPUT);
  pinMode(ledStand, OUTPUT);
  pinMode(ledStore, OUTPUT);
  pinMode(ledStartButton, OUTPUT);
  pinMode(ledDialogueButton, OUTPUT);
  pinMode(piezoPin, OUTPUT);

  Serial.begin(9600); //starts the serial communication

}

void loop() {
  
  preInteraction();

  if (digitalRead(startButton) == HIGH && digitalRead(dialogueButton) == HIGH) {
    
  }
  interactionOne();
  
  if (doStart && actionVal == 2) { 
    //
    actionVal = 3;
  }
  
  if (doStart && actionVal == 3) { 
    //
    actionVal = 4;

  }
 
}

void preInteraction() {
  //iterate through each action depending on the value of actionVal
  //player places duck and man in starting location
  if (digitalRead(duck) == HIGH && actionVal == 0 && digitalRead(man) == HIGH) { 
    //start led blinks
    //action value set to 1
    actionVal = 1;
    digitalWrite(ledStartButton, HIGH);

  }
}

void interactionOne() { 
    if (buttonState = 1 && actionVal == 1 && digitalRead(duck) == HIGH && digitalRead(man) == HIGH) {   
    //led turn off
    //action value 2
    //
    digitalWrite(ledStartButton, LOW);
    actionVal = 2;

  }
}

