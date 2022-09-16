#include <IRremote.hpp>

int RECV_PIN = 2;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup() {
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  
  Serial.begin(9600);
  irrecv.enableIRIn();

}

void loop() {
 analogWrite(3, 100);
 analogWrite(4, 100);
 analogWrite(5, 100);
 if (irrecv.decode(&results)){
   Serial.println(results.value, DEC);

 }
 irrecv.resume();

}
