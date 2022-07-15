#include <Servo.h>
int ledPin = 5; // D7 choose pin for the LED
int inputPin =0; // D6 choose input pin (for Infrared sensor) 
int val = 14; // variable for reading the pin status
Servo myservo;

#define echoPin 4 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 16 //attach pin D3 Arduino to pin Trig of HC-SR04

long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() 
{  
  myservo.attach(2);
  delay(2000);
  pinMode(ledPin, OUTPUT); // declare LED as output 
  pinMode(inputPin, INPUT); // declare Infrared sensor as input
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}


void loop() {
  // put your main code here, to run repeatedly:
   val = digitalRead(inputPin); // read input value 
   if (val == HIGH)
   { // check if the input is HIGH
      digitalWrite(ledPin, LOW); // turn LED OFF 
//      Serial.print(val);
//      Serial.println("IR Sensor Value with out Object in front of the Sensor");
      myservo.write(180); 
 
   } 
   else 
   { 
      digitalWrite(ledPin, HIGH); // turn LED ON 
      Serial.print(val);
      Serial.println("IR Sensor Value with an Object in front of the Sensor");
      myservo.write(0);
      delay(1000);
   } 
   
   // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(200);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  if (distance >= 4 && distance >= 1)
   { // check if the input is HIGH
      digitalWrite(ledPin, LOW); // turn LED OFF 
      delay(1000);
   } 
   if (distance > 4)
   { // check if the input is HIGH
      digitalWrite(ledPin, HIGH); // turn LED OFF 
      Serial.println("IR Sensor Value with an Object in front of the Sensor");
//      Serial.print("Distance: ");
//      Serial.print(distance);
//      Serial.println(" cm");
   } 
}
