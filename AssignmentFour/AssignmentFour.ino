const int pinArray[] = {12, 11, 10, 4, 3, 2}; 
const int pinCount = sizeof(pinArray) / sizeof(pinArray[0]);
const int potentioPin = A1;
const int output = 1023 / 7; //146,14

void setup() {
  // alles in array (alle LEDs op output)
  for(int i = 0; i < pinCount; i++){
    pinMode(pinArray[i], OUTPUT);
  }
}

void loop() {
  // alles op low zetten
  for(int i = 0; i < pinCount; i++){
    digitalWrite(pinArray[i], LOW);
  }
  turnLeds(); // methode roepen
}

void turnLeds(){
  int potentioValue = analogRead(potentioPin); //output potmeter

// 
  int start = startPosition(potentioValue);
  // meegegeven aantal LEDs uitschakelen
  shutOffLoop(start);
  delay(100);
}

// checkt meegegeven waarde, zodra hoger of gelijk aan x word hoeveelheid LEDs terug gegeven
int startPosition(int potentioValue){
  int led = 0;

  if(potentioValue >= output*6){
    return led;
  } else if(potentioValue >= output*5){
    led = 1;
    return led;
  } else if(potentioValue >= output*4){
    led = 2;
    return led;
  } else if(potentioValue >= output*3){
    led = 3;
    return led;
  } else if(potentioValue >= output*2){
    led = 4;
    return led;
  } else if(potentioValue >= output){
    led = 5;
    return led;
  } else {
    led = 6;
    return led;
  }
}

//uitschakel loop tot aantal i(LEDs)
void shutOffLoop(int i){
  for(int j = i; j < pinCount; j++){
    digitalWrite(pinArray[j], HIGH);
  }
}