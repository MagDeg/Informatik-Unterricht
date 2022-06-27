// LED mit Potenziometer dimmbar

#define potiPin A0
#define led 3

int pwm = 0;



void setup() {
  pinMode(led, OUTPUT);    
  pinMode (potiPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int power = analogRead(potiPin);
  Serial.println(power);

  
  if ((power > 0) && (power < 1020)) {
    int powerNew = analogRead(potiPin);
    while(power++ == powerNew) {
      power = power++;
      powerNew = analogRead(potiPin);
      pwm = pwm+1;
      analogWrite(led, pwm/4);    
    }
  }
  if (power > 1020 ) {
    pwm = 250;
 }
  //Abbaubedingung fehlt

}

//andere Möglichkeit: einfach potiPin/4 als pwm nehmen. 
