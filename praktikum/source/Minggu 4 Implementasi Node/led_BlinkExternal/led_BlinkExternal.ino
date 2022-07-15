#define LED 5
void setup() {
  pinMode(LED, OUPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, HIGH);
  delay(1000);
}
