// last pin not six, six would go on whenever and not according to code 
int pinArray[] = {13, 12, 11, 10, 9, 8, 7, 5};
int pinAmount = sizeof(pinArray) / sizeof(pinArray[0]);
int ledOn = 0;
int ledOff = 0;

void setup() {
  // put your setup code here, to run once:
  // setup all needed pins to output
 for(int i = 0; i < pinAmount; i++){
    pinMode(pinArray[i], OUTPUT);
 }
}

void loop() {
  // put your main code here, to run repeatedly:
  knightRiderRight();
  delay(100);
  knightRiderLeft();
}

// as long as ledOn is lower than amount of leds, led gets turned on
// after turn on as long as ledOff is lower than leds amound, led gets turned of
void knightRiderRight(){
  while(ledOn < pinAmount){
    turnOn(ledOn);
    ledOn++;
  } 
  while(ledOff<pinAmount){
    turnOff(ledOff);
    ledOff++;
  }
}

// ledOn ledOff - 1 to get to correct corresponding pin location in array
// as long as ledOn is bigger then zero, led gets turned on. Stops when ledOn equals zero
void knightRiderLeft(){
  ledOn --;
  ledOff --;
  while(ledOn >= 0){
    turnOn(ledOn);
      ledOn--;
  }
// as long as ledOff is bigger than zero, led gets turned off. stops when ledOff equals zero
  while(ledOff >= 0){
    turnOff(ledOff);
    ledOff--;
  }
}

// function to turn on led in pinArray with 80ms delay.
void turnOn(int led){
  digitalWrite(pinArray[led], HIGH);
  delay(80);
}
// function to turn led of in pinArray with 50ms delay.
void turnOff(int led){
  digitalWrite(pinArray[led], LOW);
  delay(50);
}

