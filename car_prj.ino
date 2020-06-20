
//Big Iulian, grupa 30239
#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11); 
#define pwm1          6
#define pwm2          5
#define pwm3          9
#define pwm4          8

const int trigPin = 3;
const int echoPin = 2;
long duration;
int distanceCm;
char a; 

void setup() {
  pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
  pinMode(pwm1,   OUTPUT);
  pinMode(pwm2,   OUTPUT);
  pinMode(pwm3,   OUTPUT);
  pinMode(pwm4,   OUTPUT);
  BT.begin(9600);
  Serial.begin(9600);
  
}

 void loop(){
 digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
Serial.println(distanceCm);
  if(distanceCm <=25){
    digitalWrite(pwm1, 9);
    delay(900);
    digitalWrite(pwm1, 0);
    delay(100);
    }else if (BT.available())
  
  {
    a=(BT.read());
    Serial.print(a);
    switch(a){
    case 'F':
    digitalWrite(pwm1, LOW);
    digitalWrite(pwm2, HIGH);
    digitalWrite(pwm3, LOW);
    digitalWrite(pwm4, LOW);
    break;
    
    case 'S':
    digitalWrite(pwm1, LOW);
    digitalWrite(pwm2, LOW);
    digitalWrite(pwm3, LOW);
    digitalWrite(pwm4, LOW);
    break;
    
    case 'B':
    digitalWrite(pwm1, HIGH);
    digitalWrite(pwm2, LOW);
    digitalWrite(pwm3, LOW);
    digitalWrite(pwm4, LOW);
    break;

    case 'L':
    digitalWrite(pwm1, LOW);
    digitalWrite(pwm2, LOW);
    digitalWrite(pwm3, LOW);
    digitalWrite(pwm4, HIGH);
    break;

    case 'R':
    digitalWrite(pwm1, LOW);
    digitalWrite(pwm2, LOW);
    digitalWrite(pwm3, HIGH);
    digitalWrite(pwm4, LOW);
    break;

    case'I':
    digitalWrite(pwm1, LOW);
    digitalWrite(pwm2, HIGH);
    digitalWrite(pwm3, HIGH);
    digitalWrite(pwm4, LOW);
    break;

    case'G':
    digitalWrite(pwm1, LOW);
    digitalWrite(pwm2, HIGH);
    digitalWrite(pwm3, LOW);
    digitalWrite(pwm4, HIGH);
    break;

    case'J':
    digitalWrite(pwm1, HIGH);
    digitalWrite(pwm2, LOW);
    digitalWrite(pwm3, HIGH);
    digitalWrite(pwm4, LOW);
    break;

    case'H':
    digitalWrite(pwm1, HIGH);
    digitalWrite(pwm2, LOW);
    digitalWrite(pwm3, LOW);
    digitalWrite(pwm4, HIGH);
    break;

    }
    
    }
  }
