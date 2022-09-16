#define LATCHPIN 12
#define CLOCKPIN 11
#define DATAPIN 13

byte lampen = 00000000;

void schalteLEDS(byte lichter) {
  digitalWrite(LATCHPIN, 0);
  digitalWrite(CLOCKPIN, 0);
  digitalWrite(DATAPIN, 0);
  
  for (int a = 0; a <=7; a++) {
    digitalWrite(DATAPIN, bitRead(lichter, a));
    delay(10);
    digitalWrite(CLOCKPIN, 1);
    delay(10);
    digitalWrite(CLOCKPIN, 0);
    
  }
  
  // Signal ausgeben:
  digitalWrite(LATCHPIN, 1);
}

void schalteLEDSALt(byte lichter) {
  
  digitalWrite(LATCHPIN, 0);
  digitalWrite(CLOCKPIN, 0);
  digitalWrite(DATAPIN, 0);
  
  digitalWrite(DATAPIN, bitRead(lichter, 0));
  delay(10);
  digitalWrite(CLOCKPIN, 1);
  delay(10);
  digitalWrite(CLOCKPIN, 0);

  digitalWrite(DATAPIN, bitRead(lichter, 1));
  delay(10);
  digitalWrite(CLOCKPIN, 1);
  delay(10);
  digitalWrite(CLOCKPIN, 0);

  digitalWrite(DATAPIN, bitRead(lichter, 2));
  delay(10);
  digitalWrite(CLOCKPIN, 1);
  delay(10);
  digitalWrite(CLOCKPIN, 0);

  digitalWrite(DATAPIN, bitRead(lichter, 3));
  delay(10);
  digitalWrite(CLOCKPIN, 1);
  delay(10);
  digitalWrite(CLOCKPIN, 0);

  digitalWrite(DATAPIN, bitRead(lichter, 4));
  delay(10);
  digitalWrite(CLOCKPIN, 1);
  delay(10);
  digitalWrite(CLOCKPIN, 0);

  digitalWrite(DATAPIN, bitRead(lichter, 5));
  delay(10);
  digitalWrite(CLOCKPIN, 1);
  delay(10);
  digitalWrite(CLOCKPIN, 0);

  digitalWrite(DATAPIN, bitRead(lichter, 6));
  delay(10);
  digitalWrite(CLOCKPIN, 1);
  delay(10);
  digitalWrite(CLOCKPIN, 0);

  digitalWrite(DATAPIN, bitRead(lichter, 7));
  delay(10);
  digitalWrite(CLOCKPIN, 1);
  delay(10);
  digitalWrite(CLOCKPIN, 0);

}

void writeByte(){
  for(int a = 0; a <= 7; a++) {
     bitWrite(lampen, a, 1);
     schalteLEDS(lampen);
     bitWrite(lampen, a, 0);
  }
}

void setup() {
 
  pinMode(LATCHPIN, OUTPUT);
  pinMode(CLOCKPIN, OUTPUT);
  pinMode(DATAPIN, OUTPUT);
}

void loop() {
 writeByte(lampen);
 //lampen = B10101010;
 //schalteLEDS(lampen);
 //delay(100);
 //lampen = B01010101;
 //schalteLEDS(lampen);
 //delay(100);
 
}
