void setup() {
  // Pin definieren:
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  // LED an Pin 8 blinken lassen: 
  digitalWrite(8, HIGH);
  delay(10000);
  digitalWrite(8, LOW);
  delay(100);
  // delay = Wartezeit in Millisekunden
  digitalWrite(7, HIGH);
  delay(300);
  digitalWrite(7, LOW);
  delay(100);
  digitalWrite(9, HIGH);
  delay(6000);
  digitalWrite(9, LOW);
  delay(100);
  digitalWrite(7, HIGH);
  delay(300);
  digitalWrite(7, LOW);
}
