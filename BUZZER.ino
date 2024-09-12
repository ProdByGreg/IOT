int butonstate = 0;
void setup() {
  pinMode(7, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);}

void loop() {
  butonstate = digitalRead(7);
  if (butonstate == HIGH){

  tone(13, 261, 250);
  digitalWrite(8, HIGH);
  delay(250);
  digitalWrite(8, LOW);
  delay(50);

  tone(13, 261, 250);
  digitalWrite(8, HIGH);
  delay(250);
  digitalWrite(8, LOW);
  delay(50);

  tone(13, 391, 250);
  digitalWrite(9, HIGH);
  delay(250);
  digitalWrite(9, LOW);
  delay(50);

  tone(13, 391, 250);
  digitalWrite(9, HIGH);
  delay(250);
  digitalWrite(9, LOW);
  delay(50);

  tone(13, 440, 250);
  digitalWrite(10, HIGH);
  delay(250);
  digitalWrite(10, LOW);
  delay(50);

  tone(13, 440, 250);
  digitalWrite(10, HIGH);
  delay(250);
  digitalWrite(10, LOW);
  delay(50);

  tone(13, 391, 250);
  digitalWrite(9, HIGH);
  delay(250);
  digitalWrite(9, LOW);
  delay(50);

  tone(13, 349, 250);
  digitalWrite(11, HIGH);
  delay(250);
  digitalWrite(11, LOW);
  delay(50);

  tone(13, 349, 250);
  digitalWrite(11, HIGH);
  delay(250);
  digitalWrite(11, LOW);
  delay(50);

  tone(13, 329, 250);
  digitalWrite(12, HIGH);
  delay(250);
  digitalWrite(12, LOW);
  delay(50);

  tone(13, 329, 250);
  digitalWrite(12, HIGH);
  delay(250);
  digitalWrite(12, LOW);
  delay(50);

  tone(13, 294, 250);
  digitalWrite(8, HIGH);
  delay(250);
  digitalWrite(8, LOW);
  delay(50);

  tone(13, 294, 250);
  digitalWrite(8, HIGH);
  delay(250);
  digitalWrite(8, LOW);
  delay(50);

  tone(13, 261, 250);
  digitalWrite(8, HIGH);
  delay(250);
  digitalWrite(8, LOW);
  delay(50);

  noTone(13);
  delay(500);

   }else{

  tone(13, 261, 250);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  delay(250);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  delay(50);}}
