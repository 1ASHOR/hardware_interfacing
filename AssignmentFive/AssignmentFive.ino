#include <Servo.h>

Servo servo;
const int buttonOne = 13;
const int buttonTwo = 12;
const int maxRotation = 120;
const float slowRot = 41.66666666666667; //5 seconden gedeeld door de 120 ticks rotatie
const float fastRot = 4.166666666666667; //0,5 seconden gedeeld door de 120 ticks rotatie
int rotation = 0;

void setup() {
  // put your setup code here, to run once:
  servo.attach(7);
  servo.write(rotation);
  pinMode(buttonOne, INPUT);
  pinMode(buttonTwo, INPUT);
}

void loop() {
  // booleans met de waarde van de buttons (HIGH of LOW)
  bool pressOne = digitalRead(buttonOne);
  bool pressTwo = digitalRead(buttonTwo);

// beide buttons HIGH-> slow rotation heen, fast terug, 2 sec pauze
  if(pressOne == HIGH && pressTwo == HIGH){
    setServoRotation(slowRot, fastRot, 2000);
  }
  // button one HIGH -> sloom heen en terug, geen pauze
  else if(pressOne == HIGH && pressTwo == LOW){
    setServoRotation(slowRot, slowRot, 0);
  }
  // button two HIGH -> snel heen en terug, geen pauze
  else if(pressTwo == HIGH && pressOne == LOW){
    setServoRotation(fastRot, fastRot, 0);
  }
  delay(100);
  
}

// functie om rotatie met snelheid heen, terug en mogelijke pauze in te stellen
// rotatie tot 120 gezien dat het maximum is voor deze opdracht
void setServoRotation(int go, int back, int pause){
  rotation = 0;
  // while loop om heen te gaan zolang button ingedrukt is
  while ((digitalRead(buttonOne) == HIGH || digitalRead(buttonTwo) == HIGH) && rotation <= 120){
    rotation++;
    servo.write(rotation);
    delay(go);
  }

  delay(pause);
  // while loop om terug te gaan zolang button ingedrukt is
  while ((digitalRead(buttonOne) == HIGH || digitalRead(buttonTwo) == HIGH) && rotation >= 0){
    rotation--;
    servo.write(rotation);
    delay(back);
  }
}