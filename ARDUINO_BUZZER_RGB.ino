const int buzzer = 8;
void setup() {
  pinMode(buzzer, OUTPUT);}

void loop() {
  tone(buzzer, 261, 250);
  delay(500);
  tone(buzzer, 294, 250);
  delay(500);
  tone(buzzer, 329, 250);
  delay(500);
  tone(buzzer, 349, 250);
  delay(500);
  tone(buzzer, 391, 250);
  delay(500);
  tone(buzzer, 440, 250);
  delay(500);
  tone(buzzer, 493, 250);
  delay(500);
  tone(buzzer, 523, 250);
  delay(500);}