void setup() {
  pinMode(6, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);}

void loop() {
  tone(6, 261, 250);
  analogWrite(3, 150);
  analogWrite(4, 250);
  analogWrite(5, 0);
  delay(500);
  
  tone(6, 294, 250);
  analogWrite(3, 255);
  analogWrite(4, 165);
  analogWrite(5, 0);
  delay(500);
  
  tone(6, 329, 250);
  analogWrite(3, 255);
  analogWrite(4, 0);
  analogWrite(5, 0);
  delay(500);
  
  tone(6, 349, 250);
  analogWrite(3, 0);
  analogWrite(4, 255);
  analogWrite(5, 0);
  delay(500);
  
  tone(6, 391, 250);
  analogWrite(3, 0);
  analogWrite(4, 0);
  analogWrite(5, 255);
  delay(500);
  
  tone(6, 440, 250);
  analogWrite(3, 128);
  analogWrite(4, 0);
  analogWrite(5, 128);
  delay(500);

  tone(6, 493, 250);
  analogWrite(3, 255);
  analogWrite(4, 105);
  analogWrite(5, 180);
  delay(500);

  tone(6, 523, 250);
  analogWrite(3, 255);
  analogWrite(4, 255);
  analogWrite(5, 255);
  delay(500);}
