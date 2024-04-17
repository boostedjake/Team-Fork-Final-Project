
#include <Servo.h>   

Servo myservo; // initialize servos
Servo myservo2;

//initialize the wire for the "button"
const int buttonPin = 2;
const int piezoPin = 3;
const int man = 4;
const int duck = 5;
const int duckStand = 13;
const int startButton = 6;
const int ledStand = 7;
const int ledHouse = 8;
const int ledStore = 9;
const int ledStartButton = 10;
const int servo1 = 11;
const int storeGrapes = 12;



//State change Detection / variables to change
int buttonState;
//int lastButtonState = 0;
int actionVal;

void setup() {
  
  buttonState = 0;
  actionVal = 0;
  pinMode(buttonPin, INPUT);
  pinMode(man, INPUT);
  pinMode(duck, INPUT);
  pinMode(duckStand, INPUT);
  pinMode(startButton, INPUT);
  pinMode(storeGrapes, INPUT);
  pinMode(ledHouse, OUTPUT);
  pinMode(ledStand, OUTPUT);
  pinMode(ledStore, OUTPUT);
  pinMode(ledStartButton, OUTPUT);
  myservo.attach(servo1);
  pinMode(piezoPin, OUTPUT);

  Serial.begin(9600); //starts the serial communication

}

void loop() {
  
  preInteraction();

  if (digitalRead(startButton) == HIGH) {
    //set button +1
    buttonState++;
    interactionOne();
    interactionThree();
  }
  interactionTwo();
  interactionTwelve();
  interactionThirteen();

}

void preInteraction() {

  //player places duck and man in starting location
  if (digitalRead(duck) == HIGH && actionVal == 0 && digitalRead(man) == HIGH) { 
    //start led lights up
    //action value set to 1
    actionVal = 1;
    digitalWrite(ledStartButton, HIGH);

  }
}

void interactionOne() { 

  //player presses button
  if (buttonState == 1 && actionVal == 1 && digitalRead(duck) == HIGH && digitalRead(man) == HIGH) {   
    //led start button turns off
    //led stand turns on
    //sound effect plays
    //action value 2
    digitalWrite(ledStartButton, LOW);
    digitalWrite(ledStand, HIGH);
    soundEffects();
    actionVal = 2;
    
  }
}  

void interactionTwo() { 
  //Player places duck at the lemonade stand
  if (actionVal == 2 && digitalRead(duckStand) == HIGH && digitalRead(man) == HIGH) {
    
    //button led prompts
    //action value 3
    digitalWrite(ledStartButton, HIGH);
    digitalWrite(ledStand, LOW);
    actionVal = 3;

  }
}

void interactionThree() {
  //Player presses button second time dialogue servo flips to grape
  if (buttonState == 2 && actionVal == 3 && digitalRead(duckStand) == HIGH && digitalRead(man) == HIGH) {
    //start button off
    //servo flips "grapes"
    digitalWrite(ledStartButton, LOW);
    myservo.write(180);
  }
  else {
    //move servo back after something changes
    myservo.write(0);
  }
  //sound effects play
  //store LED lights up
  soundEffects();
  digitalWrite(ledStore, HIGH);
  actionVal = 4;
}

void interactionTwelve() {
  //Player places duck and man at store
  if (actionVal == 4 && digitalRead(duck) == HIGH && digitalRead(man) == HIGH) {
    //led store turns off
    //action value updated
    digitalWrite(ledStore, LOW);
    actionVal = 5;
  }
}

void interactionThirteen() {
  //Player places grapes on pressure plate
  if (actionVal == 5 && digitalRead(duck) == HIGH && digitalRead(man) == HIGH && digitalRead(storeGrapes) == HIGH) {
    //sound effect plays
    //action value updated
    soundEffects();
    actionVal = 6;
  }

}



void soundEffects() {
  if (actionVal == 1 || actionVal == 5) {
    tone(3, 10);
    noTone(3);
  }
  if (actionVal == 3) { 
    tone(3, 10);
    noTone(3);
  }
}

