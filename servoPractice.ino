#include <Servo.h>

Servo myservo; // create servo variable
const int buttonPin = 2;
//variables to change
int buttonState = 0;
int lastButtonState = 0;

void setup() {
  myservo.attach(9); // attaches the servo on pin 9
  pinMode(buttonPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  // read the pushbutton pin
  buttonState = digitalRead(buttonPin)

  if (digitalRead(buttonPin) == HIGH) {
    myservo.write(180); // tells the servo what angle to turn to 0-180
    Serial.println(buttonPin);
  } else { 
    myservo.write(0); 

  }

}
