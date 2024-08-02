#include<Servo.h>
Servo doorServo;
const int trigPin = 8;
const int echoPin = 9;
const int servoPin = 7;
const int buzzerPin = 5;

void setup() {
  Serial.begin(9600);
  doorServo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  doorServo.write(0);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delay(100);
  digitalWrite(trigPin, HIGH);
  delay(100);
  digitalWrite(trigPin, LOW);
  //readthe echopin
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034/2);
  Serial.print("Distance:");
  Serial.print(distance);
  Serial.println("cm");
  
  if(distance<15){
    digitalWrite(buzzerPin, HIGH);
    delay(2000);
    digitalWrite(buzzerPin, LOW);
    delay(1000); 
    doorServo.write(90);
    //doorServo.write(0);
  }
  else if (distance > 15) {
    Serial.println("No nearby object detected");
    doorServo.write(0);
  }  
  delay(1000);
}
