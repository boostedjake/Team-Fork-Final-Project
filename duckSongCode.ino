
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
const int startButton = 6;
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
  button();
  if (actionVal == 0) {
    preInteraction();
    Serial.println("0 Complete");
    if (actionVal == 1) {
      interactionOne();
      Serial.println("1 Complete");
      if (actionVal == 2) {
        interactionTwo();
        Serial.println("2 Complete");
        if (actionVal == 3) {
          interactionThree();
          Serial.println("3 Complete");
          if (actionVal == 4) {
            interactionFour();
          }
            if (actionVal == 5) {
              interactionFive();
            }
              if (actionVal == 6) {
                interactionTwelve();
                Serial.println("6 Complete");
                if (actionVal == 7) {
                  interactionThirteen();
                  Serial.println("7 Complete");
                }
              }
        
        
        }
      }
    }
  }
}

void preInteraction() {

  //player places duck and man in starting location
  if (digitalRead(duck) == HIGH && actionVal == 0 && digitalRead(man) == HIGH) { 
    //start led lights up
    //action value set to 1
    actionVal = 1;
    digitalWrite(ledStartButton, HIGH);
    Serial.println("Pre-Interaction Successful!");

  }
  
}

void interactionOne() { 

  //player presses button
  if (buttonPushCounter == 1 && actionVal == 1 && digitalRead(duck) == HIGH && digitalRead(man) == HIGH) {   
    //led start button turns off
    //led stand turns on
    //sound effect plays
    //action value 2
    digitalWrite(ledStartButton, LOW);
    digitalWrite(ledStand, HIGH);
    soundEffects();
    actionVal = 2;
    //Serial.println("Interaction One Successful!");
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
    Serial.println("Interaction Two Successful!");
  }
}

void interactionThree() {
  //Player presses button second time dialogue servo flips to grape
  if (buttonPushCounter == 2 && actionVal == 3 && digitalRead(duckStand) == HIGH && digitalRead(man) == HIGH) {
    //start button off
    //servo flips "grapes"
    digitalWrite(ledStartButton, LOW);
    myservo.write(90);
    //sound effects play
    //store LED lights up
    soundEffects();
    actionVal = 4;
    //Serial.println("Interaction Three Successful!");
  }
}

void interactionFour() {
  //dialogue flips in reaction and sound effect plays
  if (actionVal == 4 && digitalRead(duckStand) == HIGH && digitalRead(man) == HIGH) {
    myservo.write(180);
    soundEffects();
    actionVal = 5;
    digitalWrite(ledHouse, HIGH);
  }
}


void interactionFive() {
  if (actionVal == 5 && digitalRead(duck) == HIGH && digitalRead(man) == HIGH) {
    digitalWrite(ledHouse, LOW);
    soundEffects();
    digitalWrite(ledStartButton, HIGH);
    actionVal = 6;
  }
}

void interactionSix() {
    //player presses button
  if (buttonPushCounter == 3 && actionVal == 6 && digitalRead(duck) == HIGH && digitalRead(man) == HIGH) {   
    //led start button turns off
    //led stand turns on
    //sound effect plays
    //action value 7
    digitalWrite(ledStartButton, LOW);
    digitalWrite(ledStand, HIGH);
    soundEffects();
    actionVal = 7;
    //Serial.println("Interaction 7 Successful!");
  }
}

void interactionSeven() {
  if (actionVal == 7 && digitalRead(duckStand) == HIGH && digitalRead(man) == HIGH) {
    //place duck back to stand
    //button led prompts
    //action value 3
    digitalWrite(ledStartButton, HIGH);
    digitalWrite(ledStand, LOW);
    soundEffects();
    actionVal = 8;
  }
}

void interactionEight() {
  //dialogue flips to store
  if (buttonPushCounter == 4 && digitalRead(duckStand) == HIGH && digitalRead(man) == HIGH) {
    
    
    digitalWrite(ledStore, HIGH);
  }

}

void interactionTwelve() {
  //Player places  duck and man at store
  if (actionVal == 6 && digitalRead(duck) == HIGH && digitalRead(man) == HIGH) {
    //led store turns off
    //action value updated
    digitalWrite(ledStore, LOW);
    actionVal = 5;
    Serial.println("Interaction Twelve Successful!");

  }
}

void interactionThirteen() {
  //Player places grapes on pressure plate
  if (actionVal == 7 && digitalRead(duck) == HIGH && digitalRead(man) == HIGH && digitalRead(storeGrapes) == HIGH) {
    //sound effect plays
    //action value updated
    soundEffects();
    actionVal = 6;
    Serial.println("Interaction Thirteen Successful!");

  }

}

int button() {
  // read the pushbutton input pin:
  buttonState = digitalRead(startButton);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      Serial.println(buttonPushCounter);
        

    }
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;
  return buttonPushCounter;
}


void soundEffects() {
  if (actionVal == 1 || actionVal == 6) {
    //General Melody
    tone(3, 10);
    noTone(3);
  }
  if (actionVal == 4) { 
    //No Sound
    tone(3, 10);
    noTone(3);
  }
  if (actionVal == 5) {
    //play til the next day
  }
}

