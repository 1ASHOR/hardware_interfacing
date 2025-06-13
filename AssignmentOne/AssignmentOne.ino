void setup() {
  // pin 10 & 13 als output gezet voor de leds
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // methodes roepen met pauzes ertussen
  tenOn();
  delay(1500);
  thirteenOn();
  delay(1500);
}

// methodes voor lamp 1 aan/ uit en 2 uit/aan
void tenOn(){
  digitalWrite(10, HIGH);
  digitalWrite(13, LOW);
}

void thirteenOn(){
    digitalWrite(10, LOW);
    digitalWrite(13, HIGH);
}