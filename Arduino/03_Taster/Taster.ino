#define led 7
#define taster 4

void setup() {
  pinMode(led, OUTPUT);
  pinMode(taster, INPUT);
  Serial.begin(9600);

}

void loop() {
  // taster = false
 if (!digitalRead(taster)) {
  digitalWrite(led, HIGH);
  Serial.println("Taster gdedrückt");
 }
 else {
  digitalWrite(led, LOW); 
  Serial.println("Taster losgelassen");
 }

}
