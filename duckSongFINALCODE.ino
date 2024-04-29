
#include <Servo.h>   

Servo myservo; // initialize servos


//LED is yellow wire
//copper tape is blue wire
//piezo is green wire
//servo is green wire
//initialize cardboard button pin
const int buttonPin = 2;
const int piezoPin = 3;
const int man = 4;
const int duck = 5;
const int duckStand = 13;
const int ledStand = 7;
const int ledHouse = 8;
const int ledStore = 9;
const int ledStartButton = 10;
const int servo1 = 11;
const int storeGrapes = 12;



//State change Detection / variables to change
int buttonPushCounter = 0;  // counter for the number of button presses
int buttonState = 0;        // current state of the button
int lastButtonState = 0;    // previous state of the button
int actionVal = 0;
bool soundPlay = false;

void setup() {
  
  buttonState = 0;
  actionVal = 0;
  pinMode(buttonPin, INPUT);
  pinMode(man, INPUT);
  pinMode(duck, INPUT);
  pinMode(duckStand, INPUT);
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

  if (actionVal == 0) {
    myservo.write(0);
  }
  //soundEffects();
  button();
  preInteraction();
  interactionOne();
  interactionTwo();
  interactionThree();
  if (actionVal == 4) {
    myservo.write(90);
  }
  //stopMusicMan();
  interactionFour();
  if (actionVal == 5) {
    myservo.write(180);
  }
  //stopMusicDuck();
  interactionFive();
  interactionSix();
  interactionSeven();
  if (actionVal == 8) {
    myservo.write(90);
  }
  //stopMusicMan();
  interactionEight();
  if (actionVal == 9) {
    myservo.write(-90);
  }
  interactionNine();
  interactionTen();
}

void preInteraction() {
  //player places duck and man in starting location
  if (digitalRead(duck) == HIGH && actionVal == 0) { 
    //start led lights up
    //action value set to 1
    actionVal = 1;
    digitalWrite(ledStartButton, HIGH);
    Serial.println("Pre-Interaction Successful!");
  }

}

void interactionOne() { 
  //player presses button
  if (buttonPushCounter == 1 && actionVal == 1 && digitalRead(duck)) {   
    //led start button turns off
    //led stand turns on
    //sound effect plays
    //action value 2
    digitalWrite(ledStartButton, LOW);
    digitalWrite(ledStand, HIGH);
    //soundPlay = true;
    actionVal = 2;
    Serial.println("Interaction One Successful!");
    Serial.println(buttonPushCounter);
  }
}  

void interactionTwo() { 
  //Player places duck at the lemonade stand
  if (actionVal == 2 && digitalRead(duckStand) == HIGH) {
    //button led prompts
    //action value 3
    //soundPlay = false;
    digitalWrite(ledStartButton, HIGH);
    digitalWrite(ledStand, LOW);
    actionVal = 3;
    Serial.println("Interaction Two Successful!");
  }
}

void interactionThree() {
  //Player presses button second time dialogue servo flips to grape
  if (buttonPushCounter == 2 && actionVal == 3 && digitalRead(duckStand) == HIGH) {
    //start button off
    //servo flips "grapes"
    digitalWrite(ledStartButton, LOW);
    
    //sound effects play
    //store LED lights up
    //soundPlay = true;
    actionVal = 4;
    Serial.println("Interaction Three Successful!");
  }
}

void interactionFour() {
  //Player Presses button third timedialogue flips in reaction and sound effect plays
  if (buttonPushCounter == 3 && actionVal == 4 && digitalRead(duckStand) == HIGH) {
    //soundPlay = true;
    actionVal = 5;
    digitalWrite(ledHouse, HIGH);
    Serial.println("Four Successful");
  }
}


void interactionFive() {
  //back home
  if (actionVal == 5 && digitalRead(duck) == HIGH) {
    digitalWrite(ledHouse, LOW);
    //soundPlay = true;
    digitalWrite(ledStartButton, HIGH);
    actionVal = 6;
    Serial.println("Five Successful");
  }
}

void interactionSix() {
    //player presses button
  if (buttonPushCounter == 4 && actionVal == 6 && digitalRead(duck)) {   
    //led start button turns off
    //led stand turns on
    //sound effect plays
    //action value 7
    digitalWrite(ledStartButton, LOW);
    digitalWrite(ledStand, HIGH);
    //soundPlay = true;
    actionVal = 7;
    Serial.println("Interaction 6 Successful!");
  }
}

void interactionSeven() {
  if (actionVal == 7 && digitalRead(duckStand) == HIGH) {
    //place duck back to stand
    //button led prompts
    //action value 3
    digitalWrite(ledStartButton, HIGH);
    digitalWrite(ledStand, LOW);
    //soundPlay = true;
    actionVal = 8;
    Serial.println("Seven Successful");
  }
}

void interactionEight() {
  //dialogue flips to store
  if (buttonPushCounter == 5 && actionVal == 8 && digitalRead(duckStand) == HIGH) {
    
    //soundPlay = true; //next day
    digitalWrite(ledStore, HIGH);
    actionVal = 9;
    Serial.println("Eight Successful");
  }
}

void interactionNine() {
  //Player places  duck and man at store
  if (actionVal == 9 && digitalRead(duck) == HIGH) {
    //led store turns off
    //action value updated
    //soundPlay = false;
    digitalWrite(ledStore, LOW);
    actionVal = 10;
    Serial.println("Interaction Nine Successful!");
  }
}

void interactionTen() {
  //Player places grapes on pressure plate
  if (actionVal == 10 && digitalRead(duck) == HIGH && digitalRead(storeGrapes) == HIGH) {
    //sound effect plays
    //action value updated
    //soundPlay = true;
    actionVal = 11;
    Serial.println("Interaction Ten Successful!");
  }
}

int button() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
        // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;
  return buttonPushCounter;
}
