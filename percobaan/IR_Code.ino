int ledPin = 13; // D7 choose pin for the LED
int inputPin =12; // D6 choose input pin (for Infrared sensor) 
int val = 0; // variable for reading the pin status

void setup() 
{  Serial.begin(9600);
   pinMode(ledPin, OUTPUT); // declare LED as output 
   pinMode(inputPin, INPUT); // declare Infrared sensor as input
}


void loop() {
  // put your main code here, to run repeatedly:
   val = digitalRead(inputPin); // read input value 
   if (val == HIGH)
   { // check if the input is HIGH
      digitalWrite(ledPin, LOW); // turn LED OFF 
      Serial.print(val);
      Serial.println("IR Sensor Value with out Object in front of the Sensor");
 
   } 
   else 
   { 
      digitalWrite(ledPin, HIGH); // turn LED ON 
      Serial.print(val);
      Serial.println("IR Sensor Value with an Object in front of the Sensor");
      delay(1000);
   } 
}
