#define LED_MERAH D3
#define LED_HIJAU D4
#define LED_BIRU D5
#define PIN_LDR A0

void setup() {
  Serial.begin(9600);
  pinMode(LED_MERAH, OUTPUT);
  pinMode(LED_HIJAU, OUTPUT);
  pinMode(LED_BIRU, OUTPUT);
}

void loop() {
 int a = analogRead(A0);

Serial.print("Intensitas Cahaya: ");
Serial.println(a);

if (a > 500) {
digitalWrite(LED_MERAH, LOW);
digitalWrite(LED_HIJAU, HIGH);
digitalWrite(LED_BIRU, HIGH);
}
else {
digitalWrite(LED_MERAH, HIGH);
digitalWrite(LED_HIJAU, HIGH);
digitalWrite(LED_BIRU, HIGH);
}
 
 delay(2000);
}
