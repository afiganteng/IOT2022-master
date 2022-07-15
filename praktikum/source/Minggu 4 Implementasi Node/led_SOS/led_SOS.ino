#define LedMerah 16 //D0 pin led merah
#define LedHijau 5 //D1 pin led hijau
#define LedBiru 4 //D2 pin led biru
void setup() {
Serial.begin(9600);
pinMode(LedMerah, OUTPUT);
pinMode(LedHijau, OUTPUT);
pinMode(LedBiru, OUTPUT); // atur pin digital sebagai output.
}
void RunningLED() {
digitalWrite(LedMerah, HIGH);
for(int x=0; x<2; x++){
  digitalWrite(LedHijau, LOW);
}
//digitalWrite(LedHijau, LOW);
digitalWrite(LedBiru, LOW);
Serial.println("LED Merah nyala");

delay(7000);
digitalWrite(LedMerah, HIGH);
for(int x=0; x<2; x++){
  digitalWrite(LedHijau, HIGH);
  delay(150);
  digitalWrite(LedHijau, LOW);
  delay(150);
}
digitalWrite(LedHijau, HIGH);
digitalWrite(LedBiru, LOW);
Serial.println("LED Hijau nyala");
delay(1000);

digitalWrite(LedMerah, LOW);
digitalWrite(LedHijau, LOW);
digitalWrite(LedBiru, HIGH);
Serial.println("LED Hijau nyala");
delay(9000);

digitalWrite(LedMerah, LOW);
for(int x=0; x<2; x++){
  digitalWrite(LedHijau, HIGH);
  delay(150);
  digitalWrite(LedHijau, LOW);
  delay(150);
}
digitalWrite(LedHijau, HIGH);
digitalWrite(LedBiru, HIGH);
Serial.println("LED Merah nyala");
delay(1000);
Serial.println();
}
void loop() {
RunningLED();
}
