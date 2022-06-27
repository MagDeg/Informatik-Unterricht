#define blau 3
#define gruen 5
#define rot 6

#define potiBlau A1
#define potiGruen A2
#define potiRot A3



void setup() {
  pinMode(blau, INPUT);
  pinMode(gruen, INPUT);
  pinMode(rot, INPUT);
  
  pinMode(potiBlau, INPUT);
  pinMode(potiGruen, INPUT);
  pinMode(potiRot, INPUT);

  
  Serial.begin(9600);

}

void loop() {
  int potiBlauIn = analogRead(potiBlau);
  int potiGruenIn = analogRead(potiGruen);
  int potiRotIn = analogRead(potiRot); 

  float potiBlauPwm = potiBlauIn/4;
  float prozentBlau = potiBlauPwm/255;


  Serial.println("rot: " + String(100 - prozentBlau*100) + "%, " + "grün: " + String(255 - potiGruenIn/4) + ", " + "blau: " + String(255 - potiBlauIn/4));
  
  analogWrite(blau, potiBlauIn/4);      
  analogWrite(gruen, potiGruenIn/4);
  analogWrite(rot, potiRotIn/4);
}


//map(analogRead(potiBlau), 0, 1024, 0, 255) -> Input wird von Input 0-1024 auf 0-255 gesetzt
