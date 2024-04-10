  //initialize the wire for the "button"
  const int button = 8;
  const int servo1 = 9;
  //initialize the servos


void setup() {

  int actionVal = 0;
  bool doStart = false;
}

void loop() {
  start();
  //iterate through each action depending on the value of actionVal
  
  if (doStart && actionVal == 1) { 
    //
     
  }

  if (doStart HIGH && actionVal == 2) { 
    //
  }
  
  if (doStart HIGH && actionVal == 3) { 
    //
  }
  
  if (doStart HIGH && actionVal == 4) { 
    //
  }


*/
}

bool start() {
  if digitalRead(8) == HIGH) {
    return doStart = true;
    actionVal++;
  }
  else {
    return false;
  }
}
