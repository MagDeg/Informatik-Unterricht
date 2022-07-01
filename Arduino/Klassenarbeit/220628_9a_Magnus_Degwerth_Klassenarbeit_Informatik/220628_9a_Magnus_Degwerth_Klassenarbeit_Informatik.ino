#define poti A0
#define led 7

void setup() {
 pinMode(poti, INPUT);
 pinMode(led, OUTPUT);
 //Serial.begin(9600);

}

void loop() {
  int resistor = analogRead(poti);
  //Serial.println(resistor);
  if (resistor > 500) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
