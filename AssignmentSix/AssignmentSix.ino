#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Address, columns, rows
const int buttonOne = 13;
const int buttonTwo = 12;

float seconds = 0;
int minutes = 0;
int hours = 0;

boolean timer = false;
float lapHold = 0;

void setup() {
  // setup LCD
  lcd.init();      
  lcd.backlight();       
  lcd.print("Press to start");
  //setup Buttons
  pinMode(buttonOne, INPUT);
  pinMode(buttonTwo, INPUT);
}

void loop() {
  bool pressOne = digitalRead(buttonOne);
  bool pressTwo = digitalRead(buttonTwo);

  //zodra knop 1 gedrukt word:
  if(pressOne == HIGH){
    lcd.clear(); // haal start up text weg
    //start timer
    timer = true;
    startTimer();
  }

//beide knoppen indrukken, timer resetten
  if(pressOne == HIGH && pressTwo == HIGH){
   resetTimer();
  }
 
}

void startTimer(){
  // laat de timer oneindig lopen
  while(timer = true){

    //pauzeer timer zodra knop 2 gedrukt word
    if(digitalRead(buttonTwo) == HIGH){
      timer = false; //stopt de while loop
      return;
    }

// zodra knop 1 ingedruk gehouden word gaat een kleine timer lopen
    if(digitalRead(buttonOne) == HIGH){
      lapHold = lapHold + 0.01;
      if(lapHold >= 2){ // is die timer 2seconden
        showLap(); //laap de lap tijd zien
      } 
      //geen 2 seconden ingedrukt gehouden
    } else {
        lapHold = 0; // reset timer
    }

    // zodra seconden 60 is, 0 tellen en minuten +1
    seconds = seconds + 0.01;
    if(seconds >= 60){
      seconds = 0;
      minutes ++;
    }
    //zodra minuten 60 is, 0 tellen en uren +1
    else if(minutes >= 60){
      minutes = 0;
      hours ++;
    }
  

    //"uren . minuten . seconden" op scherm zetten
    lcd.setCursor(0, 0);
    lcd.print(hours);
    lcd.print(".");
    lcd.print(minutes);
    lcd.print(".");
    lcd.print(seconds, 2);
  }
}

//functie om lap "uren . minuten . seconden" op scherm te zetten
void showLap(){
  lcd.setCursor(0, 1); //2e rij links
  lcd.print(hours);
  lcd.print(".");
  lcd.print(minutes);
  lcd.print(".");
  lcd.print(seconds, 2);
}

//functie om timer te resetten met bericht
void resetTimer(){
    lcd.print("Timer reset");
    delay(2000);
    lcd.clear();
    lcd.print("Press to Start");
    hours = 0;
    minutes = 0;
    seconds = 0;
}






