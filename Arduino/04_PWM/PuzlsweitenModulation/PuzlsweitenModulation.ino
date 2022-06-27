#define led 3

int pwm = 10;

void setup() {
  pinMode(led, OUTPUT);
  

};



void loop() {
  analogWrite(led, pwm);
  delay(500);
  if (pwm < 250) {
    pwm = pwm + 10;
  } else if (pwm = 250) {
      while(pwm > 10) {
        pwm = pwm - 10;
        analogWrite(led, pwm);
        delay(500);
      }
    }
}
