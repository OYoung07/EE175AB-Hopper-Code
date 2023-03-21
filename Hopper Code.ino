#include <Stepper.h>

const int steps2 = 200;
Stepper myStepper2(steps2, 16, 5, 4, 15);


void setup() {
  // put your setup code here, to run once:
    pinMode(0, INPUT); /// pin of button
    
    myStepper2.setSpeed(55);
  pinMode(16,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(15,OUTPUT);
   Serial.begin(9600);

}
int flag = 0;
  // put your main code here, to run repeatedly:
void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(0);
  if(buttonState == HIGH) {
    if(flag == 0) {
      //Turn motor 90 degrees
      myStepper2.step(-90);
      flush();
    }
    flag = 1;
  }
  else if(buttonState == LOW) {
    flag = 0;
    ESP.reset();
  }
  //myStepper2.step(90);

}

void flush()
{
    digitalWrite(16, LOW);
    digitalWrite(5, LOW);
    digitalWrite(3, LOW);
    digitalWrite(1, LOW); 

}
