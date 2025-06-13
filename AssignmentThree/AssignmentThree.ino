int buttonPress = 0;

void setup() {
  pinMode(8, OUTPUT); //LED
  pinMode(10, OUTPUT);//LED
  pinMode(12, INPUT);//BUTTON
}

void loop() {
  plusOnePress();
  switchLed();
}

// LEDs worden gewisseld gebasseerd op of buttonPress een even of oneven nummer is
// Daarna een delay om foute lezing te voorkomen
void switchLed(){
  if(buttonPress % 2 == 0){
    digitalWrite(8, LOW);
    digitalWrite(10, HIGH);
    delay(50);
  } else {
     digitalWrite(8, HIGH);
    digitalWrite(10, LOW);
    delay(50);
  }
}

// als de knop gedrukt word dan int buttonPress plus één
void plusOnePress(){
  int buttonState = digitalRead(12);

  if(buttonState == HIGH){
    buttonPress ++;
    delay(200); // delay om incorrecte inputlezing te voorkomen
  }
}