#define rotPin 8
#define gelbPin 7
#define gruenPin 9
#define fGruenPin 3
#define fRotPin 2

void setup() {
  pinMode(rotPin, OUTPUT);
  pinMode(gruenPin, OUTPUT);
  pinMode(gelbPin, OUTPUT);
  pinMode(fGruenPin, OUTPUT);
  pinMode(fRotPin, OUTPUT);
}
void fussgaengerGruenAn() {
  digitalWrite(fGruenPin, HIGH);
}

void fussgaengerGruenAus() {
  digitalWrite(fGruenPin, LOW);
}

void fussgaengerRotAn() {
  digitalWrite(fRotPin, HIGH);
}

void fussgaengerRotAus() {
  digitalWrite(fRotPin, LOW);
}

void gruen() {
  digitalWrite(gruenPin, HIGH);
  delay(5000);
  digitalWrite(gruenPin,LOW);
  delay(200);
}
void gelbAn() {
  digitalWrite(gelbPin, HIGH);
  
}
void gelbAus() {
  digitalWrite(gelbPin, LOW);
  delay(200);
}
void rotAn() {
  digitalWrite(rotPin, HIGH);
}
void rotAus() {
  digitalWrite(rotPin, LOW);
  delay(200);
}

void loop() {
  
  
  gruen();
  gelbAn();
  delay(2000);
  gelbAus();
  rotAn();
  fussgaengerRotAus();
  fussgaengerGruenAn();
  delay(9000);
  fussgaengerGruenAus();
  gelbAn();
  fussgaengerRotAn();
  delay(1000);
  rotAus();
  gelbAus();
  
}
