#include <IRremote.h>   // Das Programm greift an dieser Stelle auf eine „Library“ zurück. Das erleichtert einem viel Arbeit. Denn das Infrarotlicht wird mit einem Code verschlüsselt gesendet. Um diesen Code selber auszulesen und in passende Werte umzuwandeln, wären sehr viele Zeilen Code erforderlich.
#include <Servo.h>

#define ledPin 13
#define led2Pin 12
#define RECV_PIN 11  //  Der Kontakt der am Infrarotsensor die Daten ausgibt, wird mit Pin 11 des Arduinoboards verbunden.

Servo servo;

IRrecv irrecv(RECV_PIN);   // An dieser Stelle wird ein Objekt definiert, dass den Infrarotsensor an Pin 11 ausliest.
decode_results results;  // Dieser Befehl sorgt dafür, dass die Daten, die per Infrarot eingelesen werden unter „results“ abgespeichert werden.

boolean ledAn = false;
bool led2An;

void setup(){
  Serial.begin(9600);    //Im Setup wird die Serielle Verbindung gestartet, damit man sich die Empfangenen Daten der Fernbedienung per seriellen Monitor ansehen kann.
  pinMode (13, OUTPUT);
  pinMode (12, OUTPUT);
  irrecv.enableIRIn();   //Dieser Befehl initialisiert den Infrarotempfänger.
  servo.attach(2);
}

void loop(){  

if (irrecv.decode(&results)) {
  Serial.println(results.value, DEC);
  if(results.value == 16757325) {
    
     led2An = ledAn; 
     digitalWrite(led2Pin, led2An);
     ledAn = !ledAn;
     digitalWrite(ledPin, ledAn);
      
     if (ledAn) {
      servo.write(90);
     } else {
      servo.write(0);
     }
     
    }

  
  irrecv.resume();  //Der nächste Wert soll vom IR-Empfänger eingelesen werden
  }
}
