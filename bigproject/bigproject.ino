#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include<Servo.h>

const int trigPin = 15;
const int echoPin = 13;
long duration;
int distance;
int safetyDistance;
Servo myservo; 
int pos = 0; 


const char* ssid = "realme5";
const char* password = "999999999";


const char* mqtt_server = "138.2.79.154";


WiFiClient espClient22;
PubSubClient client(espClient22);

const int led = 4;
int val = 0 ;
const int ldr = A0;

long now = millis();
long lastMeasure = 0;
long lastMsg = 0;
char msg(50);
int value = 0;

void setup_wifi() {
  delay(10);
  
  Serial.println();
 
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi connected - NodeMCU IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(String topic, byte* message  ,unsigned int length ) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageInfo;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageInfo += (char)message[i];
  }
  
  Serial.println();

  val = digitalRead(5);
  Serial.println(val); 
  delay(100);      
  
  
 
  if(topic=="room/light"){
      Serial.print("Changing Room Light to ");
  delay(100);
      if(messageInfo == "on"){
     
        digitalWrite(led, HIGH);
        Serial.print("On");
      }
      else if(messageInfo == "off"){
       
        digitalWrite(led, LOW);
        Serial.print("Off");
      }
        Serial.println();
  }
    Serial.println();
  if(topic=="lampu"){
    if(messageInfo == "0"){
     
        digitalWrite(led, LOW);
        Serial.print("OFF LDR");
      }
      else if(messageInfo == "1"){
       
        digitalWrite(led, HIGH);
        Serial.print("ON LDR");
      }
    }
  Serial.println();
}

void reconnect() {

  while (!client.connected()) {
    Serial.print("Tes MQTT connection...");
    
    
    if (client.connect("ESP8266Client22")) {
      Serial.println("connected");  
     
      client.subscribe("room/light");
      client.subscribe("lampu");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      
      delay(5000);
    }
  }
}


void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(14,HIGH);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  myservo.attach(0);

}


void loop() {

  if (!client.connected()) {
    reconnect();
  }
  if(!client.loop())
    client.connect("ESP8266Client22");
    
  val = digitalRead(5);   
  Serial.println(val);   
  delay(100);     
  if(val == 1 )  
  {  
   digitalWrite(14,HIGH); // LED ON  
  }  
  else  
  {  
   digitalWrite(14,LOW); // LED OFF  
  }  

  now = millis();
  if(now - lastMeasure >3000){
    lastMeasure = now;
    int nilai = analogRead(ldr);

    static char intensitasCahaya[7];
    dtostrf(nilai,6,2,intensitasCahaya);

    client.publish("cahaya",intensitasCahaya);
    
    Serial.print ("Cahaya = ");
    Serial.print (nilai);
    Serial.print ("V");

    }
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance= duration*0.034/2;
    safetyDistance = distance;
    if (safetyDistance <= 5){
    
    myservo.write(180); 
    delay(3000); 
    }
    else{ 
    myservo.write(0); 
    delay(20);  }
    Serial.print("Distance: ");
    Serial.println(distance);
}
  }
