#define echo 11
#define trigger 12

float zeit;
float entfernung;
int differenz;

void setup() {
 Serial.begin(9600);
 pinMode(trigger, OUTPUT);
 pinMode(echo, INPUT);



}

void loop() {
  digitalWrite(trigger,LOW);
  delay(5);
  digitalWrite(trigger, HIGH);
  delay(10);
  digitalWrite(trigger, LOW);
  
  zeit = pulseIn(echo, HIGH);
  entfernung = (zeit/2)*0.03432;
  if (entfernung >= 500 || entfernung <= 0) {
    Serial.println("keineMessung");
  } else {
  Serial.print(entfernung);
  Serial.println(" cm");
  delay(60);
  }
  if (entfernung < 20){
    if (entfernung > 5) {
      tone(4, 500);
      differenz = entfernung * 20;
      delay(differenz);
      noTone(4);
      delay(differenz);
    }else
    tone(4, 1000);
    delay(1000);
    noTone(4);  
  } 
  
}
