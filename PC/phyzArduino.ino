#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#include <RC_Receiver.h> // lets the controller work
#endif

RC_Receiver receiver(3,4,7,10); //initializes what channels are on what pins for the controller

int current3 = 5;
int last3 = 5;
int current6 = 5;
int last6 = 5;
int current4 = 5;
int last4 = 5;
int current5 = 5;
int last5 = 5;
int currentCase = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  currentCase = random(1,5);  
  
  last3 = current3;
  last4 = current4;
  last5 = current5;
  last6 = current6;
  if(receiver.getMap(1) < 10) {
    current3 = 0;
  }
  else if(receiver.getMap(1) > 20) {
    current3 = 1;
  }
  if(receiver.getMap(2) < 10) {
    current4 = 0;
  }
  else if(receiver.getMap(2) > 20) {
    current4 = 1;
  }
  if(receiver.getMap(3) < 10) {
    current5 = 0;
  }
  else if(receiver.getMap(3) > 20) {
    current5 = 1;
  }
  if(receiver.getMap(4) < 10) {
    current6 = 0;
  }
  else if(receiver.getMap(4) > 20) {
    current6 = 1;
  }
  if(current3 != last3) {
    Serial.print(3);
  }
  else if(current4 != last4) {
    Serial.print(4);
  }
  else if(current5 != last5) {
    Serial.print(5);
  }
  else if(current6 != last6) {
    Serial.print(6);
  }
  if (Serial.available() > 0){
    char c = Serial.read();
    switch (c){
      case 'h':
        digitalWrite(13, HIGH);
        digitalWrite(8, HIGH);
        break;
      case 'l':
        digitalWrite(13,LOW);
        digitalWrite(8,LOW);
        break;
    }
  }
}