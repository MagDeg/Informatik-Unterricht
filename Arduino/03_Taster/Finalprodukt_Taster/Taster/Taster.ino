#define led 7
#define taster 4

long startTime;             //variable startTime wird als "long" Datentyp deklariet (Variable kann nur nicht Dezimalzahlen annehmen), wert in Millisekunden beim ersten Tastendruck
long duration;              //variable duration wird al s"long" Dateityp deklariet, Variable für die Dauer

boolean ebenGedrueckt = false;        //definiere boolsche Variable (nur true oder false) 

void setup() {
  pinMode(led, OUTPUT);
  pinMode(taster, INPUT);
  Serial.begin(9600); //Serielle Schnittstelle initialisiert 
  // (...)Rate der Übertragung (Menge pro Zeit), desto höher desto Fehleranfälliger, 9600 = Standardt

}

void loop() {
  
  // wenn Taster gedrückt = false (Spannung fällt an Wiederstand ab), wenn Taster nicht gedrückt = true (Stromkreis nicht geschlossen, an Widerstand fällt keine Spannung ab, es liegen 5V an)
  // Wiederstand nicht vergessen sonst beim Drücken Kurzschluss!!
  // immer wenn der Taster nicht true, also false ist wird ... ausgeführt
  
 if (!digitalRead(taster)) {                                                   // Wenn Taster gedrückt ist (false, bzw. low)
  
    if (!ebenGedrueckt){
    startTime = millis();                                                      // millis() -> gibt Zeit seit Start Programm an, Variable wird auf diese Zeit definiert
    //Wenn Taster gedrückt und eben nicht gedrückt war, dann ...               // ...und eben noch nicht gedrückt war, dann
    digitalWrite(led, HIGH);                                                   // LED an
    Serial.println("Taster gedrückt");                                         // Nachicht auf Schnittstelle ausgeben
    //.println -> Zeilenumbruch nach Text, nur .print alles gleiche Zeile      
    ebenGedrueckt = true;                                                      // Statusvariable updaten
    delay(50);                                                                 // entprellt Taster, um bei schneller Abfrage Fehler zu vermeiden
    
  }
  
 }
 else {                                                                        // Taster nicht gedrückt, aber
  
  if(ebenGedrueckt){                                                           // ...Taster war eben gedrückt
  //Taster nicht mehr gedrückt, aber eben war er noch                          // LED aus
    digitalWrite(led, LOW);
    long duration = millis() - startTime;                                      // Variable wird als Differenz aus startTime und millis festgelegt, also Zeit seitdem das Programm läuft und Zeit als Schalter gedrückt = Dauer Schalterdruck
    Serial.println("Taster losgelassen");                                      // Nachicht auf Schnittstelle ausgeben
    Serial.println(duration);                                                  // Nachicht Dauer Tastendruck auf Schnittstelle ausgeben
    ebenGedrueckt = false;                                                     // Statusvariable updaten
    delay(50);                                                                 // kurz warten, um Taster zu entprellen
  }
  
 
 }

}
